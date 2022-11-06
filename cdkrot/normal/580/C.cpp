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

void dfs(const vector<vector<uint32_t>>& graph, const vector<char>& has_cat, vector<pair<uint32_t, uint32_t>>& DP, uint32_t v)
{
	for (auto u: graph[v])
		if (DP[u] == make_pair(UINT32_MAX, UINT32_MAX))
		{
			DP[u].second = (has_cat[u] ? DP[v].second + 1 : 0);
			DP[u].first  = max(DP[v].first, DP[u].second);
			
			dfs(graph, has_cat, DP, u);
		}
}

int main()
{
	uint32_t n, m;
	cin >> n >> m;
	
	vector<char> has_cat(n);
	for (uint32_t i = 0; i != n; ++i)
		has_cat[i] = input<char>() - '0';
	
	vector<vector<uint32_t>> graph(n);
	for (uint32_t i = 1; i != n; ++i)
	{
		uint32_t u = input<uint32_t>() - 1;
		uint32_t v = input<uint32_t>() - 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	// [max on path, cur streak].
	vector<pair<uint32_t, uint32_t>> DP(n, make_pair(UINT32_MAX, UINT32_MAX));
	DP[0] = make_pair(has_cat[0], has_cat[0]);
	
	dfs(graph, has_cat, DP, 0);
	
	uint32_t ans = 0;
	for (uint32_t i = 1; i != n; ++i)
		if (graph[i].size() == 1 and DP[i].first <= m)
			++ans;
	
	cout << ans << endl;
	return 0;
}