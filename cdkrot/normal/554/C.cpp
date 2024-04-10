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

#define MOD  1000000007

vector<vector<uint32_t>> precalc_C(size_t n)
{
	vector<vector<uint32_t>> ans(n);
	for (size_t i = 0; i != n; ++i)
	{
		ans[i].resize(i + 1);
		for (size_t j = 0; j != i + 1; ++j)
		{
			if (j == 0)
				ans[i][j] = 1;
			else if (j == i)
				ans[i][j] = 1;
			else
				ans[i][j] = (ans[i - 1][j] + ans[i - 1][j - 1]) % MOD;
		}
	}
	return std::move(ans);
}

int main()
{
	uint32_t k = input<uint32_t>();
	uint64_t cur_ans = 1;
	uint32_t cur_len = 0;
	auto C = precalc_C(2010);
	
	for (uint32_t i = 0; i != k; ++i)
	{
		if (i == 0)
		{
			cur_ans = 1;
			cur_len = input<uint32_t>();
		}
		else
		{
			auto len = input<uint32_t>();
			cur_ans *= C[cur_len + len - 1][len - 1];
			cur_len += len;
			cur_ans %= MOD;
		}
	}
	
	cout << cur_ans << endl;
	
	return 0;
}