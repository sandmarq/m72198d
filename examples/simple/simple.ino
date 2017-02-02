#include <m72198d.h>

#define MAX7219_DIN 13
#define MAX7219_CS  15
#define MAX7219_CLK 14
#define NUMDISP 1

Max7219 display1(MAX7219_DIN, MAX7219_CS, MAX7219_CLK, NUMDISP);

void setup() {
  Serial.begin(115200);
  //  initialise();
  display1.init();
  Serial.println("init");
  delay(250);
}

void loop() {
  //  output(0x08, 0x0c); //digit 7 (leftmost digit) data
  display1.setAddress(MAX7219_REG_ADD_DIG7);
  display1.setData(MAX7219_CODEB_FONT_REG_3);
  display1.output();
  Serial.println("digit 7 (leftmost digit) data");

  //  output(0x07, 0x0b);
  display1.setAddress(MAX7219_REG_ADD_DIG6);
  display1.setData(MAX7219_CODEB_FONT_REG_1);
  display1.output();


  //  output(0x06, 0x0d);
  display1.setAddress(MAX7219_REG_ADD_DIG5);
  display1.setData(MAX7219_CODEB_FONT_REG_0);
  display1.output();

  //  output(0x05, 0x0e);
  display1.setAddress(MAX7219_REG_ADD_DIG4);
  display1.setData(MAX7219_CODEB_FONT_REG_1);
  display1.output();

  //  output(0x04, 0x08);
  display1.setAddress(MAX7219_REG_ADD_DIG3);
  display1.setData(MAX7219_CODEB_FONT_REG_2);
  display1.output();

  //  output(0x03, 0x07);
  display1.setAddress(MAX7219_REG_ADD_DIG2);
  display1.setData(MAX7219_CODEB_FONT_REG_0);
  display1.output();

  //  output(0x02, 0x06);
  display1.setAddress(MAX7219_REG_ADD_DIG1);
  display1.setData(MAX7219_CODEB_FONT_REG_1);
  display1.output();

  //  output(0x01, 0x05); //digit 0 (rightmost digit) data
  display1.setAddress(MAX7219_REG_ADD_DIG0);
  display1.setData(MAX7219_CODEB_FONT_REG_7);
  display1.output();
  Serial.println("digit 0 (rightmost digit) data");

  delay(1000);

  display1.writeNumInFontB();

  delay(1000);
}
