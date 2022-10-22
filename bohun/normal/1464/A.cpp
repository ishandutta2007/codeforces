#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

vector <int> g[100005];
bool vis[100005];
int edges, ver;

void dfs(int v) {
	vis[v] = true;
	edges += sz(g[v]);
	ver++;
	for (auto u : g[v])
		if (!vis[u])
			dfs(u);
}	

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, res = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			g[i].clear(), vis[i] = 0;
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == y) 
				continue;
			x--; y--;
			g[x].pb(y);
			g[y].pb(x);		
		}
		for (int i = 0; i < n; ++i) 
			if (!vis[i]) {
				edges = ver = 0;
				dfs(i);
				res += edges / 2 + (edges / 2 == ver);
			}
		printf("%d\n", res);	
		
	}
	return 0;
}