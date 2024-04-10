#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 1e4;
vector<int> adj[MN], rev[MN], stk;
bool vis[MN], hasIn[MN], wee[MN]; int scc[MN], cc;
void fill (int x) {
	vis[x] = true;
	for (int i : rev[x]) if (!vis[i]) fill(i);
	stk.push_back(x);
}
void dfs (int x) {
	vis[x] = true; scc[x] = cc;
	for (int i : adj[x]) {
		if (!vis[i]) dfs(i);
		else if (scc[i] != scc[x]) hasIn[scc[i]] = true;
	}
}
int main () {
	int n,m; scanf ("%d %d",&n,&m);
	vector<vector<char>> grid(n+1,vector<char>(m+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf (" %c",&grid[i][j]);
		}
	}
	auto get = [&] (int x, int y) {
		return (x-1) * m + y;
	};
	vector<int> high(m+2,-1);
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) if (grid[i][j] == '#') {
			wee[get(i,j)] = true;
			if (high[j] != -1) {
				adj[get(i,j)].push_back(high[j]);
			}
			high[j] = get(i,j);
		}
		for (int j = 1; j <= m; j++) if (grid[i][j] == '#') {
			if (high[j-1] != -1) adj[get(i,j)].push_back(high[j-1]);
			if (high[j+1] != -1) adj[get(i,j)].push_back(high[j+1]);
			if (i-1 >= 1 && grid[i-1][j] == '#') adj[get(i,j)].push_back(get(i-1,j));
		}
	}
	for (int i = 1; i <= n*m; i++) {
		for (int j : adj[i]) rev[j].push_back(i);
	}
	for (int i = 1; i <= n*m; i++) if (wee[i] && !vis[i]) fill(i);
	memset(vis,0,sizeof vis);
	while (!stk.empty()) {
		int cur = stk.back(); stk.pop_back();
		if (!vis[cur]) {
			++cc;
			dfs(cur);
		}
	} 
	int ret = 0;
	for (int i = 1; i <= cc; i++) ret += !hasIn[i];
	printf ("%d\n",ret);
	return 0;
}