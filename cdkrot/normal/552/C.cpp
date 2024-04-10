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

uint64_t abs(uint64_t a, uint64_t b)
{
	return (a >= b) ? (a - b) : (b - a);
}

int main()
{
	auto w = input<uint64_t>();
	auto m = input<uint64_t>();
	
	if (w == 2 or w == 3)
	{
		cout << "YES\n";
		return 0;
	}
	
	vector<uint64_t> weights;
	weights.push_back(1);
	while (weights.back() <= m)
		weights.push_back(weights.back() * w);
	vector<bool> allowed(weights.size(), true);
	
	while (m != 0)
	{
		// try to find closest w^i, as w != 2 it is not ambigious.
		auto ind = std::upper_bound(weights.begin(), weights.end(), m) - weights.begin();
		auto closest = ind;
		// try ind, ind-1, ind-2;
		if (ind >= 1 and abs(weights[ind - 1], m) < abs(weights[closest], m))
			closest = ind - 1;
		if (ind >= 2 and abs(weights[ind - 2], m) < abs(weights[closest], m))
			closest = ind - 2;
		
		if (not allowed[closest])
			break;
		
		m = abs(weights[closest], m);
		allowed[closest] = false;
	}
	
	if (m == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	
	return 0;
}