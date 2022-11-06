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
	for (uint32_t test_cnt = input<uint32_t>(); test_cnt != 0; --test_cnt)
	{
		uint32_t n, k;
		cin >> n >> k;
		vector<char> field[3];
		vector<char> DP[3];
		for (uint32_t i : {0, 1, 2})
		{
			field[i].resize(n);
			DP[i].resize(n);
			for (char& c: field[i])
				c = input<char>();
		}
		
		// check for next three cells. y0 \in {1, 2, 3}
		auto isLineSpare = [&field, n](uint32_t x0, uint32_t y0) -> bool
		{
			for (uint32_t x = x0; x != min(n, x0 + 3); ++x)
				if (field[y0][x] != '.')
					return false;
			return true;
		};
		
		for (uint32_t I = 0; I != n; ++I)
		{
			uint32_t x = n - 1 - I;
			const vector<vector<uint32_t>> neigh = {{0, 1}, {0, 1, 2}, {1, 2}};
			
			for (uint32_t y : {0, 1, 2})
			{
				DP[y][x] = false;
				for (uint32_t st: neigh[y])
					if (field[st][x] == '.' and field[y][x] == '.' and isLineSpare(x, st))
					{
						if (x + 3 >= n)
							DP[y][x] = true;
						else
							DP[y][x] = DP[y][x] or DP[st][x + 3];
					}
			}
		}
		
		vector<string> textual = {"NO\n", "YES\n"};
		
		if (field[0][0] == 's')
			cout << textual[DP[0][1]];
		else if (field[1][0] == 's')
			cout << textual[DP[1][1]];
		else
			cout << textual[DP[2][1]];
	}
	return 0;
}