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
#include <cmath>
#include <queue>
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

uint32_t bfs(const vector<vector<uint32_t>>& graph, uint32_t a, uint32_t b)
{
	vector<uint32_t> dist(graph.size(), UINT32_MAX);
	dist[a] = 0;
	std::queue<uint32_t> q;
	q.push(a);
	
	while (not q.empty())
	{
		uint32_t v = q.front();
		q.pop();
		
		for (uint32_t u: graph[v])
			if (dist[u] == UINT32_MAX)
			{
				dist[u] = dist[v] + 1;
				q.push(u);
			}
	}
	
	return dist[b];
}

int main()
{
	std::iostream::sync_with_stdio(false);
	
	vector<vector<uint32_t>> graph(input<uint32_t>());
	vector<vector<uint32_t>> graph2(graph.size());
	for (uint32_t m = input<uint32_t>(); m != 0; --m)
	{
		uint32_t u = input<uint32_t>() - 1;
		uint32_t v = input<uint32_t>() - 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for (uint32_t i = 0; i != graph.size(); ++i)
	{
		vector<char> used(graph.size(), false);
		for (uint32_t u: graph[i])
			used[u] = true;
		used[i] = true;
		
		for (uint32_t u = 0; u != graph.size(); ++u)
			if (not used[u])
				graph2[i].push_back(u);
	}
	
	uint32_t dst = max(bfs(graph, 0, graph.size() - 1), bfs(graph2, 0, graph.size() - 1));
	
	if (dst == UINT32_MAX)
		cout << "-1\n";
	else
		cout << dst << '\n';
	
	return 0;
}