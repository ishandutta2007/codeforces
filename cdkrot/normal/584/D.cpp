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

bool is_prime(uint32_t n)
{
	if (n <= 1)
		return false;
	
	for (uint32_t i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

pair<bool, vector<uint32_t>> solve(uint32_t n, uint32_t k)
{
	if (n == 0)
		return make_pair(true, vector<uint32_t>());
	if (k == 0)
		return make_pair(false, vector<uint32_t>());
	
	for (uint32_t I = 0; I + 1 != n; ++I)
	{
		uint32_t delta = n - I;
		if (is_prime(delta))
		{
			auto res = solve(I, k - 1);
			if (res.first)
			{
				res.second.push_back(delta);
				return res;
			}
		}
	}
	
	return make_pair(false, vector<uint32_t>());
}

int main()
{
	uint32_t n = input<uint32_t>();
	auto res = solve(n, 3);
	if (res.first)
	{
		cout << res.second.size() << endl;
		for (uint32_t a: res.second)
			cout << a << " ";
		endl(cout);
	}
	return 0;
}