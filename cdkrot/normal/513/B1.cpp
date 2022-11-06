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


template <typename T>
inline T input()
{
	T ans;
	cin >> ans;
	return ans;
}

#ifdef __CDKROT_LOCAL
#define debug_print(x) {cerr << #x << " = " << x << endl;}
#else
#define debug_print(x) {}
#endif


int main()
{
	uint32_t n = input<uint32_t>();
	uint32_t k = input<uint32_t>() - 1;
	
	vector<uint32_t> data(n);
	uint32_t l = 0;
	uint32_t r = n - 1;
	
	uint32_t cur_pow = 1 << (n - 1);
	
	for (uint32_t i = 1; i <= n; i++)
	{
		if (k < cur_pow / 2)
			data[l++] = i;
		else
		{
			data[r--] = i;
			k -= cur_pow / 2;
		}
		cur_pow /= 2;
		
	}
	
	for (uint32_t i = 0; i < n; ++i)
		cout << data[i] << " ";
	endl(cout);
	return 0;
}