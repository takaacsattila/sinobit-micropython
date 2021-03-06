/*
 * Zpix font was created by and copyright Jason Fung.  See
 *   https://github.com/SolidZORO/zpix-pixel-font
 * Zpix is released under the following license, note that commercial use
 * requires a license from the author:
 *  "for Commercial/Business Product (Multiple Product) Each addition one needs *   USD $300
 *   for Commercial/Business Product (Single Product) USD $800
 *   for Education Product FREE
 *   for Personal Product FREE
 *   My Paypal: solidzoro@live.com
 *   I don't have the ability to offer any form of invoice, can't give you any *   form of written agreement, please understanding."
 *
 * The code below to generate a Zpix font from its source is released under
 * the following license (note this does _not_ include the generated font, see
 * above for the license of the font itself):
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Tony DiCola
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __ZPIXFONT_H__
#define __ZPIXFONT_H__

extern "C" {

#include <cstdint>

typedef struct {
  uint16_t encoding;
  uint8_t data[16];
} zpixfont_character_t;

uint8_t zpixfont_char_dwidth(const zpixfont_character_t* character);

const zpixfont_character_t* zpixfont_find_character(uint16_t encoding);

/*[[[cog
# Cog script to generate the zpix font data for a set of defined characters and
# pack it tightly in flash memory.  See tools/zpixfont.py for a description of
# the binary packing of character bitmap data (the data array of 16 bytes).
import json
import zpixfont
config = json.load(open(config, 'r'))

# Load the font and get a set of characters to generate.
font = zpixfont.ZpixFont(config['sinobit_micropython']['zpixfont_bdf'])
chars = font.get_characters(*config['sinobit_micropython']['zpixfont_encodings'])

# Output the characters as a struct of font data.
cog.outl(f"""// Encoded {len(chars)} characters:
const struct {{
  uint8_t version;
  uint16_t count;
  zpixfont_character_t characters[{len(chars)}];
}} zpixfont = {{
  .version = 1,
  .count = {len(chars)},
  .characters = {{""")
for c in chars[:-1]:
    data_bytes = ', '.join(map(lambda x: f'0x{x:02X}', c.data))
    cog.outl(f"""    {{
      .encoding = {c.encoding},\t// {c.name}
      .data = {{ {data_bytes} }}
    }},""")
c = chars[-1]
data_bytes = ', '.join(map(lambda x: f'0x{x:02X}', c.data))
cog.outl(f"""    {{
      .encoding = {c.encoding},\t// {c.name}
      .data = {{ {data_bytes} }}
    }}
  }}
}};""")
]]]*/
// Encoded 193 characters:
const struct {
  uint8_t version;
  uint16_t count;
  zpixfont_character_t characters[193];
} zpixfont = {
  .version = 1,
  .count = 193,
  .characters = {
    {
      .encoding = 32,	// space
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04 }
    },
    {
      .encoding = 33,	// exclam
      .data = { 0x00, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 34,	// quotedbl
      .data = { 0x00, 0x0A, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 35,	// numbersign
      .data = { 0x00, 0x0A, 0x01, 0x40, 0x7C, 0x05, 0x00, 0xA0, 0x14, 0x07, 0xC0, 0x50, 0x0A, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 36,	// dollar
      .data = { 0x20, 0x0E, 0x02, 0xA0, 0x50, 0x06, 0x00, 0x40, 0x0C, 0x01, 0x40, 0xA8, 0x0E, 0x00, 0x80, 0x06 }
    },
    {
      .encoding = 37,	// percent
      .data = { 0x00, 0x00, 0x01, 0x20, 0x54, 0x0B, 0x00, 0xA0, 0x0A, 0x01, 0xA0, 0x54, 0x09, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 38,	// ampersand
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x48, 0x06, 0x00, 0x80, 0x2A, 0x05, 0x40, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 39,	// quotesingle
      .data = { 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 40,	// parenleft
      .data = { 0x08, 0x02, 0x00, 0x40, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x10, 0x02, 0x00, 0x20, 0x06 }
    },
    {
      .encoding = 41,	// parenright
      .data = { 0x40, 0x04, 0x00, 0x80, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x20, 0x04, 0x01, 0x00, 0x06 }
    },
    {
      .encoding = 42,	// asterisk
      .data = { 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01, 0xF0, 0x08, 0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 43,	// plus
      .data = { 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0x01, 0xF0, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 44,	// comma
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x01, 0x00, 0x06 }
    },
    {
      .encoding = 45,	// hyphen
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 46,	// period
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 47,	// slash
      .data = { 0x00, 0x02, 0x00, 0x40, 0x08, 0x02, 0x00, 0x40, 0x08, 0x02, 0x00, 0x40, 0x08, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 48,	// zero
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 49,	// one
      .data = { 0x00, 0x04, 0x01, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 50,	// two
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 51,	// three
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x00, 0x80, 0x60, 0x02, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 52,	// four
      .data = { 0x00, 0x02, 0x00, 0xC0, 0x18, 0x05, 0x00, 0xA0, 0x24, 0x07, 0xC0, 0x10, 0x02, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 53,	// five
      .data = { 0x00, 0x1F, 0x02, 0x00, 0x40, 0x0F, 0x01, 0x10, 0x02, 0x00, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 54,	// six
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x40, 0x0F, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 55,	// seven
      .data = { 0x00, 0x1F, 0x02, 0x20, 0x04, 0x01, 0x00, 0x20, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 56,	// eight
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x80, 0xE0, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 57,	// nine
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x1E, 0x00, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 58,	// colon
      .data = { 0x00, 0x00, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 59,	// semicolon
      .data = { 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x40, 0x10, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 60,	// less
      .data = { 0x00, 0x01, 0x00, 0x40, 0x10, 0x04, 0x01, 0x00, 0x10, 0x01, 0x00, 0x10, 0x01, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 61,	// equal
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 62,	// greater
      .data = { 0x00, 0x10, 0x01, 0x00, 0x10, 0x01, 0x00, 0x10, 0x04, 0x01, 0x00, 0x40, 0x10, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 63,	// question
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x04, 0x01, 0x00, 0x40, 0x08, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 64,	// at
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x4C, 0x0A, 0x81, 0x50, 0x2A, 0x05, 0xC0, 0x80, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 65,	// A
      .data = { 0x00, 0x04, 0x00, 0x80, 0x28, 0x05, 0x00, 0xA0, 0x1C, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 66,	// B
      .data = { 0x00, 0x1E, 0x02, 0x20, 0x44, 0x08, 0x81, 0xE0, 0x22, 0x04, 0x40, 0x88, 0x1E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 67,	// C
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x01, 0x00, 0x20, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 68,	// D
      .data = { 0x00, 0x1E, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x1E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 69,	// E
      .data = { 0x00, 0x1F, 0x02, 0x00, 0x40, 0x08, 0x01, 0xF0, 0x20, 0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 70,	// F
      .data = { 0x00, 0x1F, 0x02, 0x00, 0x40, 0x08, 0x01, 0xE0, 0x20, 0x04, 0x00, 0x80, 0x10, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 71,	// G
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x01, 0x70, 0x22, 0x04, 0x40, 0x98, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 72,	// H
      .data = { 0x00, 0x11, 0x02, 0x20, 0x44, 0x08, 0x81, 0xF0, 0x22, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 73,	// I
      .data = { 0x00, 0x1F, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 74,	// J
      .data = { 0x00, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x10, 0x02, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 75,	// K
      .data = { 0x00, 0x11, 0x02, 0x40, 0x48, 0x0A, 0x01, 0x80, 0x28, 0x04, 0x80, 0x90, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 76,	// L
      .data = { 0x00, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 77,	// M
      .data = { 0x00, 0x11, 0x02, 0x20, 0x6C, 0x0D, 0x81, 0x50, 0x2A, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 78,	// N
      .data = { 0x00, 0x11, 0x03, 0x20, 0x64, 0x0A, 0x81, 0x50, 0x26, 0x04, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 79,	// O
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 80,	// P
      .data = { 0x00, 0x1E, 0x02, 0x20, 0x44, 0x08, 0x81, 0xE0, 0x20, 0x04, 0x00, 0x80, 0x10, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 81,	// Q
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0xA8, 0x0E, 0x00, 0x20, 0x06 }
    },
    {
      .encoding = 82,	// R
      .data = { 0x00, 0x1E, 0x02, 0x20, 0x44, 0x08, 0x81, 0xE0, 0x24, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 83,	// S
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x04, 0x00, 0x40, 0x04, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 84,	// T
      .data = { 0x00, 0x1F, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 85,	// U
      .data = { 0x00, 0x11, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 86,	// V
      .data = { 0x00, 0x11, 0x02, 0x20, 0x44, 0x05, 0x00, 0xA0, 0x14, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 87,	// W
      .data = { 0x00, 0x15, 0x02, 0xA0, 0x54, 0x0A, 0x81, 0x50, 0x2A, 0x02, 0x80, 0x50, 0x0A, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 88,	// X
      .data = { 0x00, 0x11, 0x02, 0x20, 0x28, 0x05, 0x00, 0x40, 0x14, 0x02, 0x80, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 89,	// Y
      .data = { 0x00, 0x11, 0x02, 0x20, 0x44, 0x05, 0x00, 0xA0, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 90,	// Z
      .data = { 0x00, 0x1F, 0x00, 0x20, 0x08, 0x01, 0x00, 0x40, 0x10, 0x02, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 91,	// bracketleft
      .data = { 0x30, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0xC0, 0x06 }
    },
    {
      .encoding = 92,	// backslash
      .data = { 0x00, 0x08, 0x01, 0x00, 0x20, 0x02, 0x00, 0x40, 0x08, 0x00, 0x80, 0x10, 0x02, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 93,	// bracketright
      .data = { 0x30, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0xC0, 0x06 }
    },
    {
      .encoding = 94,	// asciicircum
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 95,	// underscore
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 96,	// grave
      .data = { 0x00, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 97,	// a
      .data = { 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x80, 0x10, 0x1E, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 98,	// b
      .data = { 0x00, 0x10, 0x02, 0x00, 0x78, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x1E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 99,	// c
      .data = { 0x00, 0x00, 0x00, 0x00, 0x38, 0x08, 0x81, 0x00, 0x20, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 100,	// d
      .data = { 0x00, 0x01, 0x00, 0x20, 0x3C, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 101,	// e
      .data = { 0x00, 0x00, 0x00, 0x00, 0x38, 0x08, 0x81, 0x10, 0x3E, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 102,	// f
      .data = { 0x00, 0x06, 0x01, 0x00, 0x20, 0x0F, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 103,	// g
      .data = { 0x00, 0x00, 0x00, 0x00, 0x3C, 0x08, 0x81, 0x10, 0x22, 0x03, 0xC0, 0x08, 0x11, 0x01, 0xC0, 0x06 }
    },
    {
      .encoding = 104,	// h
      .data = { 0x00, 0x10, 0x02, 0x00, 0x78, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 105,	// i
      .data = { 0x00, 0x04, 0x00, 0x00, 0x30, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 106,	// j
      .data = { 0x00, 0x04, 0x00, 0x00, 0x30, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x03, 0x00, 0x06 }
    },
    {
      .encoding = 107,	// k
      .data = { 0x00, 0x10, 0x02, 0x00, 0x44, 0x09, 0x01, 0x40, 0x30, 0x05, 0x00, 0x90, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 108,	// l
      .data = { 0x00, 0x0C, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 109,	// m
      .data = { 0x00, 0x00, 0x00, 0x00, 0x68, 0x0A, 0x81, 0x50, 0x2A, 0x05, 0x40, 0xA8, 0x15, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 110,	// n
      .data = { 0x00, 0x00, 0x00, 0x00, 0x78, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 111,	// o
      .data = { 0x00, 0x00, 0x00, 0x00, 0x38, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 112,	// p
      .data = { 0x00, 0x00, 0x00, 0x00, 0x78, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0xF0, 0x10, 0x02, 0x00, 0x06 }
    },
    {
      .encoding = 113,	// q
      .data = { 0x00, 0x00, 0x00, 0x00, 0x3C, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x78, 0x01, 0x00, 0x20, 0x06 }
    },
    {
      .encoding = 114,	// r
      .data = { 0x00, 0x00, 0x00, 0x00, 0x2C, 0x06, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x08, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 115,	// s
      .data = { 0x00, 0x00, 0x00, 0x00, 0x38, 0x08, 0x81, 0x00, 0x1C, 0x00, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 116,	// t
      .data = { 0x00, 0x08, 0x01, 0x00, 0x78, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x06, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 117,	// u
      .data = { 0x00, 0x00, 0x00, 0x00, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 118,	// v
      .data = { 0x00, 0x00, 0x00, 0x00, 0x44, 0x08, 0x81, 0x10, 0x14, 0x02, 0x80, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 119,	// w
      .data = { 0x00, 0x00, 0x00, 0x00, 0x54, 0x0A, 0x81, 0x50, 0x2A, 0x03, 0x80, 0x50, 0x0A, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 120,	// x
      .data = { 0x00, 0x00, 0x00, 0x00, 0x44, 0x08, 0x80, 0xA0, 0x08, 0x02, 0x80, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 121,	// y
      .data = { 0x00, 0x00, 0x00, 0x00, 0x44, 0x08, 0x81, 0x10, 0x14, 0x02, 0x80, 0x20, 0x04, 0x03, 0x00, 0x06 }
    },
    {
      .encoding = 122,	// z
      .data = { 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x80, 0x20, 0x08, 0x02, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 123,	// braceleft
      .data = { 0x08, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x40, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x20, 0x06 }
    },
    {
      .encoding = 124,	// bar
      .data = { 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x06 }
    },
    {
      .encoding = 125,	// braceright
      .data = { 0x40, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x20, 0x08, 0x01, 0x00, 0x20, 0x04, 0x01, 0x00, 0x06 }
    },
    {
      .encoding = 126,	// asciitilde
      .data = { 0x40, 0x14, 0x80, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 161,	// exclamdown
      .data = { 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x06 }
    },
    {
      .encoding = 162,	// cent
      .data = { 0x00, 0x00, 0x00, 0x40, 0x08, 0x07, 0x01, 0x50, 0x28, 0x05, 0x00, 0xA8, 0x0E, 0x01, 0x00, 0x06 }
    },
    {
      .encoding = 163,	// sterling
      .data = { 0x30, 0x09, 0x01, 0x00, 0x20, 0x0F, 0x00, 0x40, 0x18, 0x05, 0x00, 0xA8, 0x0B, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 164,	// currency
      .data = { 0x00, 0x08, 0x08, 0xBA, 0x08, 0x82, 0x08, 0x41, 0x08, 0x20, 0x88, 0x2E, 0x88, 0x08, 0x00, 0x0C }
    },
    {
      .encoding = 165,	// yen
      .data = { 0x00, 0x11, 0x02, 0x20, 0x28, 0x05, 0x01, 0xF0, 0x08, 0x07, 0xC0, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 166,	// brokenbar
      .data = { 0x20, 0x04, 0x00, 0x80, 0x10, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x20, 0x04, 0x00, 0x80, 0x06 }
    },
    {
      .encoding = 167,	// section
      .data = { 0x0E, 0x02, 0x20, 0x44, 0x06, 0x01, 0x20, 0x22, 0x02, 0x40, 0x30, 0x11, 0x02, 0x20, 0x38, 0x0C }
    },
    {
      .encoding = 168,	// dieresis
      .data = { 0x00, 0x00, 0x00, 0x00, 0x19, 0x83, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C }
    },
    {
      .encoding = 169,	// copyright
      .data = { 0x00, 0x00, 0x01, 0xC0, 0x44, 0x0B, 0x81, 0x90, 0x32, 0x05, 0xC0, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 170,	// ordfeminine
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x38, 0x09, 0x00, 0xD0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 171,	// guillemotleft
      .data = { 0x00, 0x00, 0x00, 0xA0, 0x28, 0x05, 0x01, 0x40, 0x14, 0x02, 0x80, 0x28, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 172,	// logicalnot
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x80, 0x10, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 173,	// uni00AD
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 174,	// registered
      .data = { 0x00, 0x00, 0x01, 0xC0, 0x44, 0x0E, 0x81, 0x30, 0x3A, 0x05, 0x40, 0x98, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 175,	// macron
      .data = { 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 176,	// degree
      .data = { 0x40, 0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C }
    },
    {
      .encoding = 177,	// plusminus
      .data = { 0x00, 0x00, 0x80, 0x10, 0x02, 0x03, 0xF8, 0x08, 0x01, 0x00, 0x20, 0x00, 0x07, 0xF0, 0x00, 0x0C }
    },
    {
      .encoding = 178,	// uni00B2
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x10, 0x04, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 179,	// uni00B3
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x10, 0x09, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 180,	// acute
      .data = { 0x10, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 181,	// mu
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x11, 0x02, 0x20, 0x44, 0x09, 0x81, 0xD0, 0x20, 0x0C }
    },
    {
      .encoding = 182,	// paragraph
      .data = { 0x7C, 0x1D, 0x03, 0xA0, 0x74, 0x06, 0x80, 0x50, 0x0A, 0x01, 0x40, 0x28, 0x05, 0x00, 0xA0, 0x06 }
    },
    {
      .encoding = 183,	// periodcentered
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1C, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C }
    },
    {
      .encoding = 184,	// cedilla
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x02, 0x00, 0x80, 0x06 }
    },
    {
      .encoding = 185,	// uni00B9
      .data = { 0x00, 0x0C, 0x00, 0x80, 0x10, 0x02, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 186,	// ordmasculine
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x48, 0x09, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 187,	// guillemotright
      .data = { 0x00, 0x00, 0x02, 0x80, 0x28, 0x05, 0x00, 0x50, 0x14, 0x02, 0x80, 0xA0, 0x00, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 188,	// onequarter
      .data = { 0xC0, 0x09, 0x01, 0x20, 0x28, 0x02, 0x00, 0x50, 0x16, 0x05, 0x40, 0xB8, 0x01, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 189,	// onehalf
      .data = { 0xC0, 0x09, 0x01, 0x20, 0x28, 0x02, 0x00, 0x60, 0x12, 0x04, 0x40, 0x90, 0x07, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 190,	// threequarters
      .data = { 0xC0, 0x05, 0x01, 0xA0, 0x18, 0x0E, 0x00, 0x50, 0x16, 0x05, 0x40, 0xB8, 0x01, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 191,	// questiondown
      .data = { 0x00, 0x04, 0x00, 0x80, 0x00, 0x02, 0x00, 0x40, 0x10, 0x04, 0x00, 0x90, 0x0C, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 192,	// Agrave
      .data = { 0x20, 0x02, 0x00, 0x80, 0x10, 0x05, 0x00, 0xA0, 0x22, 0x07, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 193,	// Aacute
      .data = { 0x20, 0x08, 0x00, 0x80, 0x10, 0x05, 0x00, 0xA0, 0x22, 0x07, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 194,	// Acircumflex
      .data = { 0x20, 0x0A, 0x00, 0x80, 0x10, 0x05, 0x00, 0xA0, 0x22, 0x07, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 195,	// Atilde
      .data = { 0x68, 0x12, 0x00, 0x80, 0x10, 0x05, 0x00, 0xA0, 0x22, 0x07, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 196,	// Adieresis
      .data = { 0x50, 0x00, 0x00, 0x80, 0x10, 0x05, 0x00, 0xA0, 0x22, 0x07, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 197,	// Aring
      .data = { 0x20, 0x0A, 0x01, 0x40, 0x10, 0x05, 0x00, 0xA0, 0x22, 0x07, 0xC0, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 198,	// AE
      .data = { 0x00, 0x07, 0x00, 0xC0, 0x28, 0x05, 0x00, 0xB0, 0x24, 0x07, 0x80, 0x90, 0x13, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 199,	// Ccedilla
      .data = { 0x00, 0x0E, 0x02, 0x20, 0x44, 0x08, 0x01, 0x00, 0x20, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x80, 0x06 }
    },
    {
      .encoding = 200,	// Egrave
      .data = { 0x40, 0x04, 0x03, 0xE0, 0x40, 0x08, 0x01, 0xE0, 0x20, 0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 201,	// Eacute
      .data = { 0x10, 0x04, 0x03, 0xE0, 0x40, 0x08, 0x01, 0xE0, 0x20, 0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 202,	// Ecircumflex
      .data = { 0x20, 0x0A, 0x03, 0xE0, 0x40, 0x08, 0x01, 0xE0, 0x20, 0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 203,	// Edieresis
      .data = { 0x50, 0x00, 0x03, 0xE0, 0x40, 0x08, 0x01, 0xE0, 0x20, 0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 204,	// Igrave
      .data = { 0x40, 0x04, 0x01, 0xC0, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 205,	// Iacute
      .data = { 0x20, 0x08, 0x01, 0xC0, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 206,	// Icircumflex
      .data = { 0x20, 0x0A, 0x01, 0xC0, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 207,	// Idieresis
      .data = { 0x50, 0x00, 0x01, 0xC0, 0x10, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 208,	// Eth
      .data = { 0x00, 0x1C, 0x02, 0x40, 0x44, 0x08, 0x81, 0xD0, 0x22, 0x04, 0x40, 0x90, 0x1C, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 209,	// Ntilde
      .data = { 0x68, 0x12, 0x03, 0x20, 0x64, 0x0A, 0x81, 0x50, 0x2A, 0x04, 0xC0, 0x98, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 210,	// Ograve
      .data = { 0x40, 0x04, 0x01, 0xC0, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 211,	// Oacute
      .data = { 0x20, 0x08, 0x01, 0xC0, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 212,	// Ocircumflex
      .data = { 0x20, 0x0A, 0x01, 0xC0, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 213,	// Otilde
      .data = { 0x68, 0x12, 0x01, 0xC0, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 214,	// Odieresis
      .data = { 0x50, 0x00, 0x01, 0xC0, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 215,	// multiply
      .data = { 0x00, 0x00, 0x00, 0x82, 0x08, 0x80, 0xA0, 0x08, 0x02, 0x80, 0x88, 0x20, 0x80, 0x00, 0x00, 0x0C }
    },
    {
      .encoding = 216,	// Oslash
      .data = { 0x10, 0x0E, 0x02, 0xA0, 0x54, 0x0A, 0x81, 0x50, 0x2A, 0x05, 0x40, 0xA8, 0x0E, 0x01, 0x00, 0x06 }
    },
    {
      .encoding = 217,	// Ugrave
      .data = { 0x40, 0x04, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 218,	// Uacute
      .data = { 0x10, 0x04, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 219,	// Ucircumflex
      .data = { 0x20, 0x0A, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 220,	// Udieresis
      .data = { 0x50, 0x00, 0x02, 0x20, 0x44, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 221,	// Yacute
      .data = { 0x10, 0x04, 0x02, 0x20, 0x44, 0x05, 0x00, 0xA0, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 222,	// Thorn
      .data = { 0x00, 0x10, 0x02, 0x00, 0x40, 0x0F, 0x01, 0x10, 0x22, 0x04, 0x40, 0xF0, 0x10, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 223,	// germandbls
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x48, 0x09, 0x01, 0x60, 0x22, 0x04, 0x40, 0xC8, 0x16, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 224,	// agrave
      .data = { 0x00, 0x08, 0x00, 0x80, 0x00, 0x06, 0x01, 0x20, 0x1C, 0x04, 0x80, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 225,	// aacute
      .data = { 0x00, 0x04, 0x01, 0x00, 0x00, 0x06, 0x01, 0x20, 0x1C, 0x04, 0x80, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 226,	// acircumflex
      .data = { 0x00, 0x04, 0x01, 0x40, 0x00, 0x06, 0x01, 0x20, 0x1C, 0x04, 0x80, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 227,	// atilde
      .data = { 0x00, 0x0D, 0x02, 0x40, 0x00, 0x06, 0x01, 0x20, 0x1C, 0x04, 0x80, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 228,	// adieresis
      .data = { 0x00, 0x00, 0x01, 0x40, 0x00, 0x06, 0x01, 0x20, 0x1C, 0x04, 0x80, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 229,	// aring
      .data = { 0x00, 0x0C, 0x02, 0x40, 0x48, 0x06, 0x01, 0x20, 0x1C, 0x04, 0x80, 0x90, 0x0D, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 230,	// ae
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x50, 0x1E, 0x05, 0x00, 0xA8, 0x0A, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 231,	// ccedilla
      .data = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x01, 0x10, 0x20, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x80, 0x06 }
    },
    {
      .encoding = 232,	// egrave
      .data = { 0x00, 0x08, 0x00, 0x80, 0x00, 0x07, 0x01, 0x10, 0x3E, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 233,	// eacute
      .data = { 0x00, 0x02, 0x00, 0x80, 0x00, 0x07, 0x01, 0x10, 0x3E, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 234,	// ecircumflex
      .data = { 0x00, 0x04, 0x01, 0x40, 0x00, 0x07, 0x01, 0x10, 0x3E, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 235,	// edieresis
      .data = { 0x00, 0x00, 0x01, 0x40, 0x00, 0x07, 0x01, 0x10, 0x3E, 0x04, 0x00, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 236,	// igrave
      .data = { 0x00, 0x08, 0x00, 0x80, 0x00, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 237,	// iacute
      .data = { 0x00, 0x02, 0x00, 0x80, 0x00, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 238,	// icircumflex
      .data = { 0x00, 0x04, 0x01, 0x40, 0x00, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 239,	// idieresis
      .data = { 0x00, 0x00, 0x01, 0x40, 0x00, 0x02, 0x00, 0x40, 0x08, 0x01, 0x00, 0x20, 0x04, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 240,	// eth
      .data = { 0x00, 0x12, 0x01, 0x80, 0x48, 0x07, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 241,	// ntilde
      .data = { 0x00, 0x0D, 0x02, 0x40, 0x00, 0x0F, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x11, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 242,	// ograve
      .data = { 0x00, 0x08, 0x00, 0x80, 0x00, 0x07, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 243,	// oacute
      .data = { 0x00, 0x02, 0x00, 0x80, 0x00, 0x07, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 244,	// ocircumflex
      .data = { 0x00, 0x04, 0x01, 0x40, 0x00, 0x07, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 245,	// otilde
      .data = { 0x00, 0x0D, 0x02, 0x40, 0x00, 0x07, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 246,	// odieresis
      .data = { 0x00, 0x00, 0x01, 0x40, 0x00, 0x07, 0x01, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0E, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 247,	// divide
      .data = { 0x00, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x04, 0x00, 0x80, 0x00, 0x0C }
    },
    {
      .encoding = 248,	// oslash
      .data = { 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x01, 0x30, 0x2A, 0x05, 0x40, 0xC8, 0x0E, 0x02, 0x00, 0x06 }
    },
    {
      .encoding = 249,	// ugrave
      .data = { 0x00, 0x08, 0x00, 0x80, 0x00, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 250,	// uacute
      .data = { 0x00, 0x02, 0x00, 0x80, 0x00, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 251,	// ucircumflex
      .data = { 0x00, 0x04, 0x01, 0x40, 0x00, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 252,	// udieresis
      .data = { 0x00, 0x00, 0x01, 0x40, 0x00, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0x88, 0x0F, 0x00, 0x00, 0x06 }
    },
    {
      .encoding = 253,	// yacute
      .data = { 0x00, 0x02, 0x00, 0x80, 0x00, 0x08, 0x81, 0x10, 0x14, 0x02, 0x80, 0x20, 0x04, 0x03, 0x00, 0x06 }
    },
    {
      .encoding = 254,	// thorn
      .data = { 0x00, 0x10, 0x02, 0x00, 0x78, 0x08, 0x81, 0x10, 0x22, 0x04, 0x40, 0xF0, 0x10, 0x02, 0x00, 0x06 }
    },
    {
      .encoding = 255,	// ydieresis
      .data = { 0x00, 0x00, 0x01, 0x40, 0x00, 0x08, 0x81, 0x10, 0x14, 0x02, 0x80, 0x20, 0x04, 0x03, 0x00, 0x06 }
    },
    {
      .encoding = 20384,	// uni4FA0
      .data = { 0x21, 0x05, 0xFD, 0x04, 0x24, 0x9C, 0x54, 0x82, 0x13, 0xFA, 0x14, 0x42, 0x88, 0x89, 0x20, 0x8C }
    },
    {
      .encoding = 38050,	// uni94A2
      .data = { 0x4F, 0xED, 0x06, 0x2A, 0x85, 0x5E, 0xAA, 0x92, 0x52, 0xAF, 0x55, 0x4A, 0xA9, 0x05, 0xA1, 0x8C }
    },
    {
      .encoding = 38081,	// uni94C1
      .data = { 0x45, 0x0C, 0xA2, 0x1F, 0x84, 0x8E, 0x10, 0x9F, 0xD0, 0x47, 0x08, 0x42, 0x88, 0x51, 0xB1, 0x8C }
    }
  }
};
//[[[end]]]

}

#endif
