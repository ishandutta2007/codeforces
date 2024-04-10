#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5, MOD = 1e9 + 7;
vector<int> adj[MN];
bool vis[MN]; int saw;
void dfs (int cur) {
	vis[cur] = true; ++saw;
	for (int i : adj[cur]) if (!vis[i]) dfs(i);
}
void solve () {
	int n; scanf ("%d",&n);
	for (int i = 1; i <= n; i++){
		 adj[i].clear();
		 vis[i] = false;
	 }
	int ret = 1, cnt = 0;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <=n; i++) {
		int b; scanf ("%d",&b);
		adj[a[i]].push_back(b); adj[b].push_back(a[i]);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		saw = 0;
		dfs(i);
		if (saw > 1) ++cnt;
	}
	while (cnt--) ret = ret * 2LL % MOD;
	printf ("%d\n",ret);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}
//aba aba
//012 345

//ab a ba
//01 2 34