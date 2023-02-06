#include <Arduino.h>
#include <ESP8266WiFi.h> //https://github.com/esp8266/Arduino
#include <IRCClient.h>
#include "config/wlan.h"
#include "config/twitch.h"

WiFiClient wiFiClient;
String ircChannel = "#" + twitchChannelName;
IRCClient client(IRC_SERVER, IRC_PORT, wiFiClient);

void connectWifi()
{
  Serial.begin(115200);
  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}

void sendTwitchMessage(String message)
{
  client.sendMessage(ircChannel, message);
}

void callback(IRCMessage ircMessage)
{
  // Serial.println("In CallBack");

  if (ircMessage.command == "PRIVMSG" && ircMessage.text[0] != '\001')
  {
    // Serial.println("Passed private message.");

    ircMessage.nick.toUpperCase();

    String message("<" + ircMessage.nick + "> " + ircMessage.text);
    // sendTwitchMessage("Found light command: " + ircMessage.text);

    // prints chat to serial
    Serial.println(message);
    // Effekt für Follows
    // if (ircMessage.text.indexOf("following") > -1 && ircMessage.nick == "STREAMLAB")
    // {
    // }
    // else
    // {
    // }

    // if (ircMessage.text == "!licht")
    // {
    //   sendTwitchMessage("Du kannst das Licht mit folgenden Befehlen steuern: Jeweils !strobo !stroborot !strobogrün !stroboblau !stroborosa !strobogelb !stroboorange !strobolila !stroboblauweiß !strobobunt !911 !blauweiß !gelbblau !rotweiß !grünrosa !grünlila !weiß !rot !grün !blau !rosa !gelb !orange !lila");
    // }
    // else if (ircMessage.text == "!strobo" || ircMessage.text == "!stroboweiß")
    // {
    //   strobe(colorWhite, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!stroborot")
    // {
    //   strobe(colorRed, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!strobogrün" || ircMessage.text == "!strobogruen")
    // {
    //   strobe(colorGreen, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!stroboblau")
    // {
    //   strobe(colorBlue, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!stroborosa")
    // {
    //   strobe(colorRose, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!strobogelb")
    // {
    //   strobe(colorYellow, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!stroboorange")
    // {
    //   strobe(colorOrange, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!strobolila")
    // {
    //   strobe(colorPurple, colorBlack, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!stroboblauweiß" || ircMessage.text == "!stroboblauweis")
    // {
    //   strobe(colorBlue, colorWhite, DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!strobobunt")
    // {
    //   strobeColorful(DEFAULT_STROBO_LENGTH);
    // }
    // else if (ircMessage.text == "!police" || ircMessage.text == "!911")
    // {
    //   police(DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!blauweiß" || ircMessage.text == "!blauweis")
    // {
    //   colorWheel(colorBlue, colorWhite, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!gelbblau")
    // {
    //   colorWheel(colorYellow, colorBlue, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!rotweiß" || ircMessage.text == "!rotweis")
    // {
    //   colorWheel(colorRed, colorWhite, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!grünrosa" || ircMessage.text == "!grunrosa" || ircMessage.text == "!gruenrosa")
    // {
    //   colorWheel(colorGreen, colorRose, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!grünlila" || ircMessage.text == "!grunlila" || ircMessage.text == "!gruenlila")
    // {
    //   colorWheel(colorGreen, colorPurple, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!grünblau" || ircMessage.text == "!grunblau" || ircMessage.text == "!gruenblau")
    // {
    //   colorWheel(colorGreen, colorBlue, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!grüngelb" || ircMessage.text == "!grungelb" || ircMessage.text == "!gruengelb")
    // {
    //   colorWheel(colorGreen, colorYellow, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!grünweiß" || ircMessage.text == "!grünweis" || ircMessage.text == "!grunweiß" || ircMessage.text == "!grunweis" || ircMessage.text == "!gruenweiß" || ircMessage.text == "!gruenweis")
    // {
    //   colorWheel(colorGreen, colorYellow, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!weiß" || ircMessage.text == "!weis")
    // {
    //   colorWheel(colorWhite, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!rot")
    // {
    //   colorWheel(colorRed, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!grün" || ircMessage.text == "!grun" || ircMessage.text == "!gruen")
    // {
    //   colorWheel(colorGreen, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!blau")
    // {
    //   colorWheel(colorBlue, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!rosa")
    // {
    //   colorWheel(colorRose, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!gelb")
    // {
    //   colorWheel(colorYellow, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!orange")
    // {
    //   colorWheel(colorOrange, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!lila")
    // {
    //   colorWheel(colorPurple, colorBlack, DEFAULT_EFFECT_LENGTH);
    // }
    // else if (ircMessage.text == "!effektRegenbogen")
    // {
    //   setEffectToRainbow();
    // }
    // else if (ircMessage.text == "!effektRotWeiß")
    // {
    //   setEffectToRedWhite();
    // }
    // else if (ircMessage.text == "!effektWeiß")
    // {
    //   setEffectToWhite();
    // }
    // else if (ircMessage.text == "!effektDefault" || ircMessage.text == "!effektBlauWeiß")
    // {
    //   setEffectToBlueWhite();
    // }
    return;
  }
}

void setup()
{
  connectWifi();

  // Initialise IRC
  client.setCallback(callback);
}

void loop()
{
  // Try to connect to chat. If it loses connection try again
  if (!client.connected())
  {
    Serial.println("Attempting to connect to " + ircChannel);
    // Attempt to connect
    // Second param is not needed by Twtich
    if (client.connect(TWITCH_BOT_NAME, "", TWITCH_OAUTH_TOKEN))
    {
      client.sendRaw("JOIN " + ircChannel);
      Serial.println("connected and ready to rock");
      sendTwitchMessage("Die LED-Wall-Steuerung ist ready. Lasst das Geblinke beginnen!");
    }
    else
    {
      Serial.println("failed... try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
    return;
  }
  client.loop();
}