#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;
 
void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
 
int main() {
	int n;
	scanf("%d", &n);
	g.resize(n + 5);
	gr.resize(n + 5);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			int k;
			scanf("%d", &k);
			if (k > 0 && i != j)
			{
				g[i].push_back(j);
				gr[j].push_back(i);
			}
		}
	}
	
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	int cc = 0;
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			++cc;
			component.clear();
		}
	}

	if (cc == 1)
	{
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}