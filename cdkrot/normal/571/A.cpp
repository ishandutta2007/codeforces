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

uint64_t count(uint32_t a, uint32_t b, uint32_t c, uint32_t l)
{
	uint64_t res = 0;
	for (uint32_t i = max(a, b + c); i <= a + l; ++i)
	{
		uint64_t left = static_cast<uint64_t>(min(l - (i - a), i - (b + c)));
		res += (left + 2) * (left + 1) / 2;
	}
	return res;
}

int main()
{
	uint32_t a, b, c, l;
	cin >> a >> b >> c >> l;
	
	uint64_t long_l = static_cast<uint64_t>(l);
	uint64_t ans = (long_l + 1) * (long_l + 2) * (long_l + 3) / 6;
	
	ans -= count(a, b, c, l);
	ans -= count(b, c, a, l);
	ans -= count(c, a, b, l);
	
	cout << ans << endl;
	
	return 0;
}