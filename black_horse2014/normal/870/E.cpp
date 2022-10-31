#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const int MOD = 1e9+7;
vector<int> vx, vy;
int x[N], y[N];
vector<int> adj[N * 2];
int vis[N * 2], cn[N * 2], T, pw[N * 2], eg[N * 2]; 

void dfs(int u) {
	vis[u] = T;
	for (int v : adj[u]) if (!vis[v]) dfs(v);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		vx.push_back(x[i]), vy.push_back(y[i]);
	}
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	int X = vx.size(), Y = vy.size();
	for (int i = 1; i <= n; i++) {
		x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
		y[i] = X + lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
		adj[x[i]].push_back(y[i]);
		adj[y[i]].push_back(x[i]);
	}
	int nn = X + Y;
	for (int i = 0; i < nn; i++) if (!vis[i]) T++, dfs(i);
	for (int i = 0; i < nn; i++) cn[vis[i]]++;
	for (int i = 1; i <= n; i++) {
		assert(vis[x[i]] == vis[y[i]]);
		eg[vis[x[i]]]++;
	}
	int dap = 1;
	pw[0] = 1;
	for (int i = 1; i <= nn; i++) pw[i] = pw[i - 1] * 2 % MOD;
	for (int i = 1; i <= T; i++) dap = dap * 1LL * (pw[cn[i]] - (cn[i] > eg[i])) % MOD;
	cout << dap << endl;
	return 0;
}