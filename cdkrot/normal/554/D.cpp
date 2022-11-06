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

vector<uint64_t> precalc_FIB(uint32_t n)
{
	vector<uint64_t> ans(n);
	for (uint32_t i = 0; i != n; ++i)
	{
		if (i == 0 or i == 1)
			ans[i] = 1;
		else
			ans[i] = ans[i - 1] + ans[i - 2];
	}
	return std::move(ans);
}

int main()
{
	// the code is very short
	// but it was hard to solve it.
	
	uint32_t n = input<uint32_t>();
	uint64_t k = input<uint64_t>() - 1;
	
	vector<uint32_t> ans(n);
	auto fib = precalc_FIB(n);
	
	for (uint32_t i = 0; i != n;)
	{
		if (k < fib[n - i - 1])
			ans[i] = i + 1, ++i;
		else
		{
			// cycle of two.
			assert(i + 1 != n);
			ans[i] = i + 2;
			ans[i + 1] = i + 1;
			
			k -= fib[n - i - 1];
			
			i += 2;
		}
	}
	
	for (uint32_t elem: ans)
		cout << elem << " ";
	endl(cout);
	
	return 0;
}