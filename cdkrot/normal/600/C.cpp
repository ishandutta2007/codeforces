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
#include <array>
#include <set>
#include <map>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;
using std::set;
using std::map;
using std::array;

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

array<uint32_t, 26> conv(const string& str)
{
	array<uint32_t, 26> res;
	std::fill(res.begin(), res.end(), 0);
	for (char c: str)
		res[c - 'a']++;
	return res;
}

array<uint32_t, 26> patch(array<uint32_t, 26> in)
{
	vector<uint32_t> tmp;
	for (uint32_t i = 0; i != 26; ++i)
		if (in[i] % 2)
			tmp.push_back(i);
	
	if (not tmp.empty())
	{
		uint32_t lpos = 0, rpos = tmp.size() - 1;
		
		while (lpos < rpos)
			--in[tmp[rpos]], ++in[tmp[lpos]], ++lpos, --rpos;
	}
	return in;
}

string to_str(const array<uint32_t, 26>& other)
{
	vector<char> out(std::accumulate(other.begin(), other.end(), 0), 0);
	uint32_t lpos = 0, rpos = out.size() - 1;
	for (uint32_t i = 0; i != 26; ++i)
	{
		for (uint32_t j = 0; j != other[i] / 2; ++j)
			out[lpos] = out[rpos] = 'a' + i, ++lpos, --rpos;
		if (other[i] % 2)
			out[out.size() / 2] = 'a' + i;
	}
	return string(out.begin(), out.end());
}

int main()
{
	std::iostream::sync_with_stdio(false);
	
	cout << to_str(patch(conv(input<string>()))) << '\n';
	
	return 0;
}