#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

int a[N], sz[N], f[N], vis[N], id[N];
vector<int> adj[N];

int get(int u) {
	return u == f[u] ? u : (f[u] = get(f[u]));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long dap = 0;
	for (int i = 1; i <= n; i++) 
	id[i] = i;
	sort(id + 1, id + n + 1, [](int x, int y) {
		return a[x] < a[y];
	});
	for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, vis[i] = 0;
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		vis[u] = 1;
		int cur = 1;
		long long cnt = 1;
		for (auto v: adj[u]) {
			if (!vis[v]) continue;
			int fu = get(u), fv = get(v);
			cnt += 1LL * cur * sz[fv];
			cur += sz[fv];
			f[fu] = fv;
			sz[fv] += sz[fu];
			sz[fu] = 0;
		}
		dap += cnt * a[u];
	}
	reverse(id + 1, id + n + 1);
	for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, vis[i] = 0;
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		vis[u] = 1;
		int cur = 1;
		long long cnt = 1;
		for (auto v: adj[u]) {
			if (!vis[v]) continue;
			int fu = get(u), fv = get(v);
			cnt += 1LL * cur * sz[fv];
			cur += sz[fv];
			f[fu] = fv;
			sz[fv] += sz[fu];
			sz[fu] = 0;
		}
		dap -= cnt * a[u];
	}
	cout << dap << endl;
	return 0;
}