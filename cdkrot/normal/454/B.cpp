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


int main()
{
	uint32_t n = input<uint32_t>();
	vector<uint32_t> elems(n);
	std::generate(elems.begin(), elems.end(), input<uint32_t>);
	
	uint32_t ind = std::min_element(elems.begin(), elems.end()) - elems.begin();
	
	auto prev = [n](uint32_t v){return (v + n - 1) % n;};
	
	if (elems[prev(ind)] == elems[ind])
	{
		uint32_t ind_copy = ind;
		ind = prev(ind);
		while (ind != ind_copy and elems[prev(ind)] == elems[ind])
			ind = prev(ind);
	}
	
	for (uint32_t i = (ind + 1) % n; i != ind; i = (i + 1) % n)
	{
		if (elems[prev(i)] > elems[i])
		{
			cout << "-1\n";
			return 0;
		}
	}
	
	cout << (n - ind) % n << endl;
	
	return 0;
}