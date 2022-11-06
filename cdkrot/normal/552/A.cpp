// Copyright (C) 2015 Sayutin Dmitry.
//
// This Program is free  software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
//
// You should have received a copy of the GNU General Public License
// If not, see <http://www.gnu.org/licenses/>.


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdint.h>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::abs;

template <typename T>
inline T input()
{
	T ans;
	cin >> ans;
	return ans;
}


int main()
{
	uint32_t sum = 0;
	for (uint32_t n = input<uint32_t>(); n != 0; --n)
	{
		uint32_t x1 = input<uint32_t>();
		uint32_t y1 = input<uint32_t>();
		uint32_t x2 = input<uint32_t>();
		uint32_t y2 = input<uint32_t>();
		sum += (x2 - x1 + 1) * (y2 - y1 + 1);
	}
	
	cout << sum << endl;
	
	return 0;
}