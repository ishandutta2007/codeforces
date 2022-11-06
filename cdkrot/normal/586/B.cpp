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
#include <set>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::multiset;
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
	uint32_t n = input<uint32_t>();
	vector<uint32_t> a[2];
	vector<uint32_t> b;
	a[0].resize(n - 1);
	a[1].resize(n - 1);
	b.resize(n);
	
	std::generate(a[0].begin(), a[0].end(), input<uint32_t>);
	std::generate(a[1].begin(), a[1].end(), input<uint32_t>);
	std::generate(b.begin(), b.end(), input<uint32_t>);

	for (uint32_t i = 1; i != n - 1; ++i)
		a[0][i] += a[0][i - 1];
	
	for (uint32_t I = 1; I != n - 1; ++I)
		a[1][n - 2 - I] += a[1][n - 1 - I];
	
	a[0].insert(a[0].begin(), 0);
	a[1].push_back(0);
	
	std::multiset<uint32_t> nums;
	for (uint32_t i = 0; i != n; ++i)
		nums.insert(a[0][i] + a[1][i] + b[i]);
	
	uint32_t res = 0;
	auto it = nums.begin();
	res += *it;
	++it;
	res += *it;
	
	cout << res << endl;
	
	return 0;
}