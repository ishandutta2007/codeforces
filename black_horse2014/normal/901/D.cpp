#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

vector<int> cand, adj[N];
int cn, coe[N], vis[N], dp[N], c[N], pr[N], x[N], y[N];
long long val[N], add[N];
void dfs(int u, int p, int f) {
	val[f] = c[u];
	for (int e : adj[u]) {
		int v = x[e] ^ y[e] ^ u;
		if (v == p) continue;
		if (pr[v] || v == 1) {
			vis[e] = 1;
		} else {
			dp[v] = dp[u] + 1;
			pr[v] = u;
			dfs(v, u, e);
			val[f] -= val[e];
		}
	}
}

int f(int x) {
	return x & 1 ? -1 : 1;
}

void dfs1(int u, int p, int f) {
	for (int e : adj[u]) {
		int v = x[e] ^ y[e] ^ u;
		if (vis[e] || v == p) continue;
		dfs1(v, u, e);
		add[u] -= add[v];
	}
	val[f] -= add[u];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i];
		adj[x[i]].push_back(i);
		adj[y[i]].push_back(i);
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= m; i++) if (vis[i]) {
		coe[i] = f(dp[x[i]]) + f(dp[y[i]]);
		if (coe[i]) cn++, cand.push_back(i);
	}
	long long tot = 0;
	for (int e : adj[1]) if (!vis[e]) tot += val[e];
	tot = c[1] - tot;
	if (tot & 1) return puts("NO"), 0;
	if (!cn && tot) return puts("NO"), 0;
	tot /= 2;
	int sgn = tot < 0 ? -1 : 1;
	tot = abs(tot);
	if (cn) {
		long long ave = tot / cn;
		for (int i = 0; i < cn; i++) {
			int e = cand[i];
			int xx = sgn * ave + (i < tot % cn ? sgn : 0);
			if (dp[x[e]] & 1) xx = -xx;
			add[x[e]] += xx;
			add[y[e]] += xx;
			val[e] = xx;
		}
	}
	dfs1(1, 0, 0);
	cout <<"YES"<<endl;
	for (int i = 1; i <= m; i++) cout << val[i] << " ";
	cout << endl;
	return 0;
}