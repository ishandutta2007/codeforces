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

struct event
{
	uint32_t time;
	uint32_t id;
	uint32_t pri;
	bool type;
};

int main()
{
	uint32_t n = input<uint32_t>();
	vector<event> events(2 * n);
	
	for (uint32_t i = 0; i != n; ++i)
	{
		cin >> events[2 * i].time >> events[2 * i + 1].time;
		events[2 * i    ].type = false;
		events[2 * i + 1].type = true;
		
		events[2 * i].id = events[2 * i + 1].id = i;
		events[2 * i].pri = events[2 * i + 1].pri = events[2 * i + 1].time - events[2 * i].time;
	}   
	
	auto cmp = [](event a, event b)
	{
		if (a.time < b.time)
			return true;
		else if (a.time == b.time)
		{
			if (a.type < b.type)
				return true;
			else if (a.type == b.type and a.pri < b.pri)
				return true;
		}
		return false;
	};
	std::sort(events.begin(), events.end(), cmp);
	
	uint32_t total = 0;
	uint32_t cur_order = UINT32_MAX;
	uint32_t cur_end   = UINT32_MAX;
	for (event e: events)
		if (e.type == 0 and cur_order == UINT32_MAX)
			cur_order = e.id, cur_end = e.time + e.pri, ++total;
		else if (e.type == 0 and cur_order != UINT32_MAX and cur_end > e.time + e.pri)
			cur_order = e.id, cur_end = e.time + e.pri;
		else if (e.type == 1 and cur_order == e.id)
			cur_order = UINT32_MAX, cur_end = UINT32_MAX;
        cout << total << endl;
	return 0;
}