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

uint32_t popcount(uint32_t v)
{
	uint32_t res = 0;
	while (v != 0)
		res += v & 1, v /= 2;
	return res;
}

int main()
{
	uint32_t n, m, k;
	cin >> n >> m >> k;
	
	vector<uint32_t> good_per_dish(n);
	std::generate(good_per_dish.begin(), good_per_dish.end(), input<uint32_t>);
	
	// look for good precessors of #i.
	// [snd][fst] -> ans.
	vector<vector<uint32_t>> good(n, vector<uint32_t>(n, 0));
	for (uint32_t z = k; z != 0; --z)
	{
		uint32_t fst, snd, delta;
		cin >> fst >> snd >> delta;
		
		good[snd - 1][fst - 1] = max(good[snd - 1][fst - 1], delta);
	}
	
	
	vector<vector<uint64_t>> DP(n, vector<uint64_t>(1u << n, 0));
	uint64_t ans = 0;
	for (uint32_t dishes_set = 1; dishes_set != (1u << n); ++dishes_set)
	{
		if (popcount(dishes_set) <= m)
			for (uint32_t last = 0; last != n; ++last)
				if ((dishes_set & (1u << last)) != 0)
				{
					for (uint32_t prev = 0; prev != n; ++prev)
						if (prev != last and (dishes_set & (1u << prev)) != 0)
							DP[last][dishes_set] = max(DP[last][dishes_set],
								DP[prev][dishes_set & ~(1u << last)] + good[last][prev]);
					
					DP[last][dishes_set] += good_per_dish[last];
					
			
					if (popcount(dishes_set) == m)
						ans = max(ans, DP[last][dishes_set]);
				}
	}
	
	cout << ans << endl;
	
	return 0;
}