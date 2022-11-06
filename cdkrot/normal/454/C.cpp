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

typedef long double DOUBLE;

DOUBLE fast_pow(DOUBLE a, uint32_t n)
{
	DOUBLE res {1.0};
	while (n)
	{
		if (n % 2)
			res *= a;
		a *= a;
		n /= 2;
	}
	return res;
}


int main()
{
	uint32_t m, n;
	cin >> m >> n;
	
	vector<DOUBLE> data(m + 1);
	for (uint32_t i = 0; i != m + 1; ++i)
		data[i] = fast_pow(DOUBLE(i) / m, n);
	
	DOUBLE ans = 0;
	for (uint32_t i = 1; i != m + 1; ++i)
		ans += i * (data[i] - data[i - 1]);
	
	cout << std::fixed;
	cout.precision(15);
	cout << ans << endl;
	return 0;
}