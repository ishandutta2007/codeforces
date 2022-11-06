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


int main()
{
	std::iostream::sync_with_stdio(false);
	
	string a = input<string>();
	string b = input<string>();
	
	uint64_t ans = 0;
	uint32_t num[2] = {0, 0};
	num[a[0] - '0'] = 1;
	pair<int32_t, int32_t> cur_window = {0, 0};
	
	for (int32_t i = 0; i != int32_t(b.size()); ++i) {
		pair<int32_t, int32_t> new_window = {
			a.size() - 1 - min(a.size() - 1, b.size() - 1 - i),
			min(int32_t(a.size()) - 1, i)
		};
		
		for (int32_t j = cur_window.first; j != new_window.first; ++j)
			num[a[j] - '0'] -= 1;
		for (int32_t j = cur_window.second + 1; j != new_window.second + 1; ++j)
			num[a[j] - '0'] += 1;
		
		ans += num[1 - (b[i] - '0')];
		cur_window = new_window;
	}
	
	cout << ans << "\n";
	
	return 0;
}