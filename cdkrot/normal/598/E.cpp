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

uint32_t ans[31][31][51];

uint32_t get(uint32_t n, uint32_t m, uint32_t k);
uint32_t calc(uint32_t n, uint32_t m, uint32_t k);
int main();


uint32_t get(uint32_t n, uint32_t m, uint32_t k)
{
	return (ans[n][m][k] != UINT32_MAX ? ans[n][m][k] : (ans[n][m][k] = calc(n, m, k)));
}

uint32_t calc(uint32_t n, uint32_t m, uint32_t k)
{	
	if (2 * k > n * m) // k is greater than a half.
		return get(n, m, n * m - k);
	
	if (k == 0)
		return 0;
	
	uint32_t res = UINT32_MAX;
	
	for (uint32_t z = 0; z <= 1; ++z)
	{
		for (uint32_t i = max(k / m, uint32_t(1)); i <= n - 1; ++i)
		{
			auto part_1 = min(i * m, k);
			res = min(res, m * m + get(i, m, part_1) + get(n - i, m, k - part_1));
		}
		
		std::swap(n, m);
	}
	
	assert(res != UINT32_MAX);
	return res;
}

int main()
{
	for (uint32_t i = 0; i != 31; ++i)
		for (uint32_t j = 0; j != 31; ++j)
			for (uint32_t k = 0; k != 51; ++k)
				ans[i][j][k] = UINT32_MAX;
	
	std::iostream::sync_with_stdio(false);
	
	for (uint32_t t = input<uint32_t>(); t != 0; --t)
	{
		uint32_t n, m, k;
		cin >> n >> m >> k;
		cout << get(n, m, k) << "\n";
	}
	
	return 0;
}