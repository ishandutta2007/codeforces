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

struct info_t
{
	uint32_t value;
	uint32_t left;
	uint32_t right;
};

int main()
{
	vector<uint32_t> arr(input<uint32_t>());
	for (uint32_t& elem: arr)
		elem = input<uint32_t>();
	
	map<uint32_t, info_t> theMap;
	uint32_t bestBeautiness = 0;
	for (uint32_t i = 0; i != arr.size(); ++i)
	{
		if (theMap.find(arr[i]) == theMap.end())
			theMap[arr[i]] = {1, i, i};
		else
			++theMap[arr[i]].value, theMap[arr[i]].right = i;
		
		bestBeautiness = max(bestBeautiness, theMap[arr[i]].value);
	}
	
	pair<uint32_t, uint32_t> ans = make_pair(0, UINT32_MAX - 1);
	for (auto elem: theMap)
		if (elem.second.value == bestBeautiness and ans.second - ans.first > elem.second.right - elem.second.left)
			ans = {elem.second.left, elem.second.right};
	
	cout << ans.first + 1 << " " << ans.second + 1 << endl;
	return 0;
}