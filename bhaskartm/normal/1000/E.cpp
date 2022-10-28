
#include <bits/stdc++.h> 
using namespace std;
 
const int MAX_N = 300 * 1000 + 10;
int low[MAX_N], mx[MAX_N], t[MAX_N], tmp, ans;
vector<int> adj[MAX_N];
 
void dfs(int u, int par = -1) {
	t[u] = low[u] = ++tmp;
	for (auto v : adj[u]) {
		if (!t[v]) {
			dfs(v, u);
			ans = max(ans, mx[u] + mx[v] + (low[v] > t[u]));
			mx[u] = max(mx[u], mx[v] + (low[v] > t[u]));
			low[u] = min(low[u], low[v]);
		}
		else if (v != par)
			low[u] = min(low[u], t[v]);
	}
}
 
int main() {
	ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
 
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
 
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0), cout << ans << endl;
 
	return 0;
}