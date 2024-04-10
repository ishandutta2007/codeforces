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
inline T input() {
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
	
	vector<pair<int32_t, int32_t>> bombs(input<uint32_t>());
	for (uint32_t i = 0; i != bombs.size(); ++i)
		cin >> bombs[i].first >> bombs[i].second;
	
	std::sort(bombs.begin(), bombs.end());
	vector<uint32_t> destroy(bombs.size());
	for (uint32_t i = 0; i != bombs.size(); ++i) {
		int32_t destroy_upto = bombs[i].first - bombs[i].second;
		uint32_t pos = std::lower_bound(bombs.begin(), bombs.end(), make_pair(destroy_upto, INT32_MIN)) - bombs.begin();
		
		destroy[i] = (i - pos) + (pos == 0 ? 0 : destroy[pos - 1]);
	}
	
	uint32_t best = UINT32_MAX;
	for (uint32_t i = 0; i != bombs.size() + 1; ++i) {
		// let the new bomb destroy bombs in [i, \inf).
		uint32_t new_cnt = (i == 0 ? 0 : destroy[i - 1]);
		new_cnt += bombs.size() - i;
		
		best = min(best, new_cnt);
	}
	
	cout << best << "\n";
	
	return 0;
}