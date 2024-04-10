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
#include <map>
#include <algorithm>
#include <utility>
#include <stdint.h>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::map;

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
	uint32_t n = input<uint32_t>();
	
	map<vector<bool>, uint32_t> data;
	
	for (uint32_t i = 0; i != n; ++i)
	{
		vector<bool> required(n);
		for (uint32_t j = 0; j != n; ++j)
			required[j] = input<char>() - '0';
		
		if (data.find(required) == data.end())
			data.emplace(required, 1);
		else
			++data.find(required)->second;
	}
	
	auto cmp = [](const pair<vector<bool>, uint32_t>& a, const pair<vector<bool>, uint32_t>& b){return a.second < b.second;};
	cout << std::max_element(data.begin(), data.end(), cmp)->second << endl;
	
	return 0;
}