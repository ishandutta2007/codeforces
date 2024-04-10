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

uint32_t numDivideableBy(uint32_t* arr, uint32_t sz, uint32_t num)
{
	uint32_t ans = 0;
	for (uint32_t* ptr = arr; ptr != arr + sz; ++ptr)
		ans += (*ptr % num == 0);
	return ans;
}

uint32_t Sqrt(uint32_t v)
{
	uint32_t l = 0;
	uint32_t r = v;
	while (r - l > 1)
	{
		uint32_t mid = l + (r - l) / 2;
		if (mid * mid < v)
			l = mid;
		else
			r = mid;
	}
	
	assert(r * r == v);
	return r;
}

int main()
{
	std::iostream::sync_with_stdio(false);
	
	uint32_t n = input<uint32_t>();
	vector<uint32_t> data(n * n);
	std::generate(data.begin(), data.end(), input<uint32_t>);
	
	std::sort(data.begin(), data.end());
	std::reverse(data.begin(), data.end());
	vector<uint32_t> ans;
	
	for (uint32_t i = 0; i != n * n;)
	{
		uint32_t i_old = i;
		for (; i != n * n and data[i] == data[i_old]; ++i) {}
		
		uint32_t cnt = Sqrt(numDivideableBy(data.data(), n * n, data[i_old]))
		- numDivideableBy(ans.data(), ans.size(), data[i_old]);
		
		for (; cnt != 0; --cnt)
			ans.push_back(data[i_old]);
	}
	
	for (uint32_t v: ans)
		cout << v << " ";
	endl(cout);
	return 0;
}