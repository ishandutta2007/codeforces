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

pair<uint32_t, uint32_t> combine(pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b)
{
	return std::make_pair(std::min(a.first, b.first), std::max(a.second, b.second));
}

int main()
{
	std::iostream::sync_with_stdio(false);
	uint32_t n = input<uint32_t>();
	vector<uint32_t> data(n);
	std::generate(data.begin(), data.end(), input<uint32_t>);
	
	vector<vector<pair<uint32_t, uint32_t>>> cache(1);
	cache[0].resize(n);
	for (uint32_t i = 0; i != n; ++i)
		cache[0][i] = make_pair(data[i], data[i]);
	
	while ((1u << cache.size()) < data.size())
	{
		cache.resize(cache.size() + 1);
		cache.back().resize(n);
		for (uint32_t i = 0; i != n; ++i)
		{
			cache[cache.size() - 1][i] = cache[cache.size() - 2][i];
			uint32_t block_sz = 1u << (cache.size() - 2);
			if (i + block_sz < n)
				cache[cache.size() - 1][i] = combine(cache[cache.size() - 1][i], cache[cache.size() - 2][i + block_sz]);
		}
	}
	
	// [l, r).
	auto get = [&cache](uint32_t l, uint32_t r)
	{
		uint32_t i = 0;
		while ((2u << i) < r - l) // while the next is good.
			i++;
		
		return combine(cache[i][l], cache[i][r - (1u << i)]);
	};
	
	uint32_t l = 0;
	uint32_t ans = 0;
	for (uint32_t r = 0; r != n; ++r)
	{
		while (get(l, r + 1).second - get(l, r + 1).first > 1)
			++l;
		ans = max(ans, r - l + 1);
	}
	
	cout << ans << endl;
	
	return 0;
}