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
	vector<uint64_t> data(input<uint64_t>());
	uint64_t A = input<uint64_t>();
	
	for (uint64_t& e: data)
		e = input<uint32_t>();
	
	uint64_t the_sum = [](const vector<uint64_t>& data){uint64_t res = 0; for (auto e: data) res += e; return res;}(data);
	
	for (uint32_t i = 0; i < data.size(); ++i)
	{
		uint64_t max_value = min(data[i], A - (data.size() - 1));
		uint64_t min_value;
		uint64_t sum = the_sum - data[i]; // because i can.
		min_value = (sum >= A ? 1 : A - sum);
		
		cout << (min_value - 1) + (data[i] - max_value) << " ";
	}
	endl(cout);
	return 0;
}