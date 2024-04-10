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

#define double long double
double cross(pair<double, double> a, pair<double, double> b)
{
	return a.first * b.second - a.second * b.first;
}

double dot(pair<double, double> a, pair<double, double> b)
{
	return a.first * b.first + a.second * b.second;
}

int main()
{
	vector<pair<pair<double, double>, uint32_t>> data(input<uint32_t>());
	for (uint32_t i = 0; i != data.size(); ++i)
	{
		data[i].second = i;
		cin >> data[i].first.first >> data[i].first.second;
	}
	
	auto cmp = [](pair<pair<double, double>, uint32_t> a, pair<pair<double, double>, uint32_t> b)
	{
		return std::atan2(a.first.first, a.first.second) < std::atan2(b.first.first, b.first.second);
	};
	std::sort(data.begin(), data.end(), cmp);
	
	double ans = 100000;
	pair<uint32_t, uint32_t> best = {666, 666};
	for (uint32_t i = 0; i != data.size(); ++i)
	{
		const auto& a = data[i].first;
		const auto& b = data[(i + 1) % data.size()].first;
		if (ans > abs(std::atan2(cross(a, b), dot(a, b))))
			ans = abs(std::atan2(cross(a, b), dot(a, b))), best = {data[i].second, data[(i + 1) % data.size()].second};
	}
	
	cerr << ans << endl;
	cout << best.first + 1 << " " << best.second + 1<< endl;
	
	return 0;
}