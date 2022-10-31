#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> L(n + 1), R(n + 1);
	const int N = 1e5 + 1;
	const int P = 1e9 + 7;
	vector<vector<int>> V(N + 1);
	vector<int> r(N);
	for (int i = 1; i < N; i++) {
		r[i] = i == 1 ? 1 : r[P % i] * 1LL * (P - P / i) % P;
	}
	for (int i = 1; i <= n; i++) {
		cin >> L[i] >> R[i];
		V[L[i]].push_back(i);
		V[R[i] + 1].push_back(-i);
	}
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> sz(n + 1), par(n + 1), dp(n + 1), fst(n + 1), st(n + 1);
	function<void(int, int)> dfs = [&](int u, int p) {
		sz[u] = 1;
		par[u] = p;
		dp[u] = dp[p] + 1;
		for (int v : adj[u]) {
			if (v == p) {
				continue;
			}
			dfs(v, u);
			sz[u] += sz[v];
		}
	};
	dfs(1, 0);
	int pn = 0;
	function<void(int, int)> hld = [&](int u, int hd) {
		fst[u] = hd;
		st[u] = ++pn;
		int w = 0;
		for (int v : adj[u]) {
			if (v != par[u] && sz[w] < sz[v]) {
				w = v;
			}
		}
		if (w) {
			hld(w, hd);
		}
		for (int v : adj[u]) {
			if (v != par[u] && v != w) {
				hld(v, v);
			}
		}
	};
	hld(1, 1);
	// add x to [l, r]
	// f[k] = a[k] * k + b[k]
	vector<int> a(n + 1), b(n + 1);
	auto add = [&](int u, int x, int y) {
		for (; u <= n; u += u & -u) {
			a[u] = (a[u] + x) % P;
			b[u] = (b[u] + y) % P;
		}
	};
	auto get_sum = [&](int u) {
		int coeff = u, ra = 0, rb = 0;
		for (; u; u -= u & -u) {
			ra = (ra + a[u]) % P;
			rb = (rb + b[u]) % P;
		}
		return (ra * 1LL * coeff + rb) % P;
	};
	auto query = [&](int l, int r) {
		return (get_sum(r) + P - get_sum(l - 1)) % P;
	};
	auto process = [&](int l, int r, int x) {
		add(l, x, (l - 1) * 1LL * (P - x) % P);
		add(r + 1, P - x, r * 1LL * x % P);
	};
	int ans = 0, S = 0, T = 0;
	auto modify = [&](int v, int x) {
		int ret = 0;
		{
			int u = v;
			while (u) {
				ret = (ret + query(st[fst[u]], st[u])) % P;
				u = par[fst[u]];
			}
		}
		{
			int u = v;
			while (u) {
				process(st[fst[u]], st[u], x);
				u = par[fst[u]];
			}
		}
		ans = (ans + (S * 1LL * dp[v] + T + (P - 2) * 1LL * ret) % P * x) % P;
		S = (S + x) % P;
		T = (T + dp[v] * 1LL * x) % P;
	};
	int ret = 0;
	for (int i = 1; i < N; i++) {
		for (int x : V[i]) {
			if (x > 0) {
				modify(x, r[R[x] - L[x] + 1]);
			} else {
				x = -x;
				modify(x, P - r[R[x] - L[x] + 1]);
			}
		}
		ret = (ret + ans) % P;
	}
	for (int i = 1; i <= n; i++) {
		ret = ret * 1LL * (R[i] - L[i] + 1) % P;
	}
	cout << ret << endl;
	return 0;
}