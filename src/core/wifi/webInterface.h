
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include <SD.h>
#include <SPI.h>
#include <WiFi.h>
#include <typeinfo>

extern AsyncWebServer *server; // used to check if the webserver is running

// function defaults
String humanReadableSize(uint64_t bytes);
String listFiles(FS &fs, const String &folder);
String readLineFromFile(File myFile);

void loopOptionsWebUi();

void serveWebUIFile(AsyncWebServerRequest *request, const String &filename, const char *contentType);
void serveWebUIFile(
    AsyncWebServerRequest *request, const String &filename, const char *contentType, bool gzip,
    const uint8_t *originaFile, uint32_t originalFileSize
);
void configureWebServer();
void startWebUi(bool mode_ap = false);
void stopWebUi();
void cleanlyStopWebUiForWiFiFeature();

// WebSocket stream of sniffer/BLE frames to the WebUI browser (endpoint /ws)
bool wsClientConnected();
void wsBroadcastJson(const String &json);
// Called by sniffer.cpp on start/stop/channel change: updates + broadcasts
// the {"t":"status",...} object.
void wsSetSnifferState(bool active, const String &mode, int chan);
