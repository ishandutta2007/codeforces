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
	uint32_t n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	
	k1 = k2 = 1;
	
	uint32_t num_turns_1 = (n1 / k1) + (n1 % k1 != 0);
	uint32_t num_turns_2 = (n2 / k2) + (n2 % k2 != 0);
	if (num_turns_1 > num_turns_2)
		cout << "First\n";
	else
		cout << "Second\n";
	
	return 0;
}