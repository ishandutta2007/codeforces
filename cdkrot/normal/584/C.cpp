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

char other(char a, char b)
{
	for (char c = 'a'; c != 'z' + 1; ++c)
		if (c != a and c != b)
			return c;
	return 0; // never.
}

int main()
{
	auto n  = input<uint32_t>();
	auto t  = input<uint32_t>();
	auto s1 = input<string>();
	auto s2 = input<string>();
	
	uint32_t num_common_required = n - t;
	
	uint32_t num_common = 0;
	for (uint32_t i = 0; i != n; ++i)
		if (s1[i] == s2[i])
			++num_common;
	
	uint32_t num_common_to_do = min(num_common, num_common_required);
	uint32_t extra_partially_common = (num_common >= num_common_required ? 0 : num_common_required - num_common);
	
	uint32_t extra_s1 = extra_partially_common;
	uint32_t extra_s2 = extra_partially_common;
	
	string ans = "";
	for (uint32_t i = 0; i != n; ++i)
		if (s1[i] == s2[i])
		{
			if (num_common_to_do != 0)
				ans += s1[i], --num_common_to_do;
			else
				ans += other(s1[i], s2[i]);
		}
		else
		{
			if (extra_s1 != 0)
				ans += s1[i], --extra_s1;
			else if (extra_s2 != 0)
				ans += s2[i], --extra_s2;
			else
				ans += other(s1[i], s2[i]);
		}
	
	if (extra_s1 != 0 or extra_s2 != 0)
		cout << "-1\n";
	else
		cout << ans << endl;
	
	return 0;
}