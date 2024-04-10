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
#include <cmath>
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

template <typename FloatT>
struct vec2
{
	public:
		vec2() {}
		
		template <typename OtherT>
		vec2(vec2<OtherT> other): x(other.x), y(other.y) {}
		
		vec2(FloatT x, FloatT y): x(x), y(y) {}

		
		vec2<FloatT> operator-(vec2<FloatT> other)
		{
			return vec2<FloatT>(x - other.x, y - other.y);
		}
		vec2<FloatT> operator+(vec2<FloatT> other)
		{
			return vec2<FloatT>(x + other.x, y + other.y);
		}
		vec2<FloatT> operator*(FloatT num)
		{
			return vec2<FloatT>(num * x, num * y);
		}
		
		FloatT len()
		{
			return std::sqrt(x * x + y * y);
		}
		
		FloatT x;
		FloatT y;
};

const uint32_t num_iterations = 100000;
#define double long double

int main()
{
	vec2<int32_t> src;
	vec2<int32_t> dest;
	int32_t v, t;
	vec2<int32_t> wind_before;
	vec2<int32_t> wind_after;
	
	cin >> src.x >> src.y >> dest.x >> dest.y;
	cin >> v >> t;
	cin >> wind_before.x >> wind_before.y >> wind_after.x >> wind_after.y;
	
	if ((vec2<double>(src - dest) + vec2<double>(wind_before) * t).len() <= v * t)
	{
		float left = 0; // probably can't
		float right = t; // can.
		for (uint32_t i = 0; i != num_iterations; ++i)
		{
			float mid = left + (right - left) / 2;
			if ((vec2<double>(src - dest) + vec2<double>(wind_before) * mid).len() <= v * mid)
				right = mid;
			else
				left = mid;
		}
		
		cout.precision(20);
		cout << std::fixed << right << endl;
	}
	else
	{
		//?? vec2<double> new_src = vec2<double>(new_src);
		vec2<double> new_src = vec2<double>(src) + vec2<double>(wind_before) * t;
		float left = 0; // can't
		float right = 1000000000; // can.
		for (uint32_t i = 0; i != num_iterations; ++i)
		{
			float mid = left + (right - left) / 2;
			if ((new_src - vec2<double>(dest) + vec2<double>(wind_after) * mid).len() <= v * (t + mid))
				right = mid;
			else
				left = mid;
		}
		cout.precision(20);
		cout << std::fixed << t + right << endl;
	}
	
	return 0;
}