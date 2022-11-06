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
#include <cmath>
#include <utility>
#include <stdint.h>
#include <assert.h>
#include <array>
#include <set>
#include <map>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;
using std::set;
using std::map;
using std::array;

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

#ifdef __CDKROT_LOCAL
#define debug_print_single(x) {debug_print_seq(x); debug_print_seq_end();}
#define debug_print_seq(x)    {cerr << #x << " = " << x << ", ";}
#define debug_print_seq_end() {endl(cerr);}
#define debug_print_text(s)   {cerr << s << endl;}
#else
#define debug_print_single(x) {}
#define debug_print_seq(x)    {}
#define debug_print_seq_end() {}
#define debug_print_text(s)   {}
#endif


int main() {
	std::iostream::sync_with_stdio(false);
	
	uint32_t n = input<uint32_t>();
	uint32_t s = input<uint32_t>();
	
	vector<pair<uint32_t, uint32_t>> passengers(n);
	for (uint32_t i = 0; i != n; ++i)
		cin >> passengers[i].first >> passengers[i].second, passengers[i].first = s - passengers[i].first;
	
	std::sort(passengers.begin(), passengers.end());
	
	uint32_t cur_time = 0;
	uint32_t cur_floor = 0;
	for (uint32_t i = 0; i != n; ++i) {
		cur_time += passengers[i].first - cur_floor;
		cur_floor = passengers[i].first;
		
		if (cur_time < passengers[i].second)
			cur_time = passengers[i].second;
	}
	
	cur_time += s - cur_floor;
	
	cout << cur_time << "\n";
	
	return 0;
}