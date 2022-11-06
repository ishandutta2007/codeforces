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
#include <array>
#include <utility>
#include <stdint.h>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::array;
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

typedef array<uint64_t, 14> Arr;
const Arr a0 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

Arr sum(Arr a, Arr b)
{
	Arr r;
	for (uint32_t i = 0; i != a.size(); ++i)
		r[i] = a[i] + b[i];
	return r;
}

Arr shift(Arr a)
{
	Arr r = a0;
	for (uint32_t i = 1; i != a.size(); ++i)
		r[i] = a[i - 1];
	return r;
}

vector<Arr> tree_data;

void add(uint32_t p_elem, uint32_t elem_l, uint32_t elem_r, uint32_t v, Arr delta)
{
	tree_data[p_elem] = sum(tree_data[p_elem], delta);
	if (elem_l != elem_r - 1)
	{
		uint32_t mid = elem_l + (elem_r - elem_l) / 2;
		if (v < mid)
			add(2 * p_elem + 1, elem_l, mid, v, delta);
		else
			add(2 * p_elem + 2, mid, elem_r, v, delta);
	}
}

Arr get(uint32_t p_elem, uint32_t elem_l, uint32_t elem_r, uint32_t l, uint32_t r)
{
	if (l <= elem_l and elem_r <= r)
		return tree_data[p_elem];
	
	if (r <= elem_l or elem_r <= l)
		return a0;
	
	uint32_t mid = elem_l + (elem_r - elem_l) / 2;
	return sum(get(2 * p_elem + 1, elem_l, mid, l, r)
	          ,get(2 * p_elem + 2, mid, elem_r, l, r));
}

int main()
{
	uint32_t n, k;
	cin >> n >> k;
	
	++k;
	
	uint32_t n_rounded = 1;
	while (n_rounded < n)
		n_rounded *= 2;
		
	tree_data.resize(2 * n_rounded - 1, a0);
	
	vector<uint32_t> nums(n);
	std::generate(nums.begin(), nums.end(), input<uint32_t>);
	
	for (uint32_t i = 0; i != n; ++i)
	{
		auto delta = shift(get(0, 0, n_rounded, 0, nums[i] - 1));
		delta[1] += 1;
		add(0, 0, n_rounded, nums[i] - 1, delta);
	}
	
	uint64_t ans = get(0, 0, n_rounded, 0, n_rounded)[k];
	cout << ans << endl;
	return 0;
}