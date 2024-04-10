#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
vector<int> adj[MN];
bool vis[MN];
vector<int> cmp;
void dfs (int cur) {
	vis[cur] = true; cmp.push_back(cur);
	for (int i : adj[cur]) if (!vis[i]) {
		dfs(i);
	}
}
int main () {
	int n,m; scanf ("%d %d",&n,&m);
	while (m--) {
		int a,b; scanf ("%d %d",&a,&b);
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		cmp.clear();
		dfs(i);
		int sz = (int)cmp.size();
		for (int j : cmp) if ((int)adj[j].size() != sz - 1) {
			printf("NO\n");
			return 0;
		}
	}
	printf ("YES\n");
	return 0;
}