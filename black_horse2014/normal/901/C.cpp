#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

int vis[N], a[N], b[N], pr[N], x[N];
vector<int> adj[N];
long long f[N], sum[N];
void dfs(int u, int p) {
	pr[u] = p;
	for (int e : adj[u]) {
		if (vis[e]) continue; 
		int v = a[e] ^ b[e] ^ u;
		vis[e] = 1;
		if (pr[v]) {
			int mi = v, ma = v, cur = u;
			while (cur != v) {
				mi = min(mi, cur);
				ma = max(ma, cur);
				cur = pr[cur];
			}
			x[mi] = min(x[mi], ma);
		} else {
			pr[v] = u;
			dfs(v, u);
		}
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i];
		adj[a[i]].push_back(i);
		adj[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] + i;
	for (int i = 1; i <= n; i++) x[i] = n + 1;
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		pr[i] = 1;
		dfs(i, 1);
	}
	for (int i = n - 1; i >= 1; i--) x[i] = min(x[i], x[i + 1]);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + x[i];
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		long long dap = 0;
		int pivot = lower_bound(x + l, x + r + 1, r + 1) - x;
		dap = sum[pivot - 1] - sum[l - 1] + (r - pivot + 1) * 1LL * (r + 1);
		dap -= (f[r] - f[l - 1]);
		printf("%lld\n", dap);
	}
	return 0;
}