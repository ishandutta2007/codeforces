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


int main()
{
	// (num money, degree of friendship)
	vector<pair<uint32_t, uint32_t>> data(input<uint32_t>());
	uint32_t d = input<uint32_t>();
	
	std::for_each(data.begin(), data.end(), [](pair<uint32_t, uint32_t>& cur)
	{
		cur.first = input<uint32_t>();
		cur.second = input<uint32_t>();
	});
	
	std::sort(data.begin(), data.end(), [](pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b)
	{
		return a.first < b.first;
	});
	
	uint32_t l = 0;
	uint32_t r = 0;
	uint64_t cur_sum = data[0].second;
	uint64_t max_sum = data[0].second;
	while (true)
	{
		if (r + 1 == data.size())
			break;
		
		r += 1, cur_sum += data[r].second;
		
		while (data[r].first - data[l].first >= d and l != r)
			cur_sum -= data[l].second, l += 1;
		
		max_sum = max(max_sum, cur_sum);
	}
	
	cout << max_sum << endl;
	
	return 0;
}