#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<vector<pair<int, int> > > g;

int dfs(int v, int p = -1) {
	int an = 0;
	for(int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i].first,
			dist = g[v][i].second;
		if(to == p) {
			continue;
		}
		an = max(an, dfs(to, v) + dist); 
	}
	return an;
}

int main (int argc, char *argv[])
{
	scanf("%d", &n);
	g.resize(n);
	for(int i = 0; i < n - 1; ++i) {
		int from, to, c;
		scanf("%d%d%d", &from, &to, &c);
		g[from].push_back(make_pair(to, c));
		g[to].push_back(make_pair(from, c));
	}
	ans = dfs(0);
	printf("%d", ans);

	return 0;
}