// Copyright (C) 2014 Sayutin Dmitry.
//
// This Program is free  software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
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


template <typename T>
inline T input()
{
	T ans;
	cin >> ans;
	return ans;
}


int main()
{
	uint32_t n = input<uint32_t>();
	uint32_t k = input<uint32_t>();
	assert(n != 0);
	vector<pair<uint32_t, uint32_t>> data(n);
	
	for (uint32_t i = 0; i < n; i++)
		data[i] = make_pair(i, input<uint32_t>());
	
	std::sort(data.begin(), data.end(), [](pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b){return a.second < b.second;});
	
	
	vector<vector<uint32_t>> ans(n);
	ans[data[0].first].push_back(data[0].second);
	
	vector<uint32_t> cur = ans[data[0].first];
	bool first_not_added = true;
	for (uint32_t i = 1; i < n; i++)
	{
		if (data[i - 1].second + first_not_added < data[i].second) // we introduce a new color here.
		{
			uint32_t left = data[i].second - data[i - 1].second;
			if (first_not_added)
			{
				first_not_added = false;
				--left;
				++cur[0];
			}
			while (left != 0)
			{
				cur.push_back(1);
				--left;
				if (cur.size() > k)
				{
					cout << "NO\n";
					return 0;
				}
			}
		}
		else
		{
			// no need to.
			if (data[i - 1].second != data[i].second)
			{
				// we introduce first plus 1.
				first_not_added = false;
				++cur[0];
			}
		}
		
		ans[data[i].first] = cur;
	}
	
	cout << "YES\n";
	for (uint32_t i = 0; i < n; i++)
	{
		for (uint32_t j = 0; j < ans[i].size(); j++)
			for (uint32_t k = 0; k < ans[i][j]; k++)
				cout << j + 1 << " ";
		endl(cout);
	}
	return 0;
}