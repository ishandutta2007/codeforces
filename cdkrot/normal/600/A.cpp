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

bool good(const string& a)
{
	if (a.empty())
		return false;
	if (not ('1' <= a[0] and a[0] <= '9'))
		return (a.size() == 1 and a[0] == '0');
	for (uint32_t i = 1; i != a.size(); ++i)
		if (not ('0' <= a[i] and a[i] <= '9'))
			return false;
	return true;
}

pair<vector<string>, vector<string>> parse(const string& s)
{
	pair<vector<string>, vector<string>> res;
	
	size_t pos = 0;
	size_t st  = 0;
	for (; pos != s.size() + 1; ++pos)
		if (pos == s.size() or s[pos] == ',' or s[pos] == ';')
		{
			string n = s.substr(st, pos - st);
			(good(n) ? res.first : res.second).push_back(n);
			st = pos + 1;
		}
	
	return res;
}

string process(const vector<string>& a)
{
	if (a.empty())
		return "-";
	
	size_t len = 0;
	for (const auto& s: a)
		len += s.size();
	
	vector<char> res(len + 1 + a.size() - 1 + 2, 0);
	res[0] = '\"';
	
	size_t pos = 1;
	for (const auto& s: a)
	{
		std::copy(s.begin(), s.end(), res.begin() + pos);
		pos += s.size();
		res[pos] = ',';
		pos++;
	}
	res[res.size() - 2] = '\"';
	
	return string(res.data());
}


int main()
{
	auto spl = parse(input<string>());
	
	cout << process(spl.first) << '\n' << process(spl.second) << '\n';
	
	return 0;
}