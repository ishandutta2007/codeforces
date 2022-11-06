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

uint64_t count(const vector<pair<uint32_t, uint32_t>>& a, const vector<pair<uint32_t, uint32_t>>& b)
{
	uint64_t ans = 0;
	for (size_t i = 0; i != min(a.size(), b.size()); ++i)
		ans += a[i].second + b[i].second;
	
	if (a.size() > b.size())
		ans += a[b.size()].second;
	if (a.size() < b.size())
		ans += b[a.size()].second;
	
	return ans;
}

int main()
{
	auto n = input<uint32_t>();
	vector<pair<uint32_t, uint32_t>> list_left, list_right;
	
	for (uint32_t i = 0; i != n; ++i)
	{
		auto x = input<int32_t>();
		auto a = input<uint32_t>();
		
		if (x < 0)
			list_left.emplace_back(-x, a);
		else
			list_right.emplace_back(x, a);
	}
	
	auto comp = [](pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b){return a.first < b.first;};
	std::sort(list_left.begin(), list_left.end(), comp);
	std::sort(list_right.begin(), list_right.end(), comp);
	
	cout << count(list_right, list_left) << endl;
	
	return 0;
}