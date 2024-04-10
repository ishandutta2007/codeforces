#include <bits/stdc++.h>
using namespace std;

const int N = 155000;
const int M = 200;
const int P = 998244353;

vector<int> adj[N];
pair<int, int> E[N];
int dp[N], f[18][N], a[N], add[N], sz[N], st[N], en[N], ans[N];
map<pair<int, int>, int> H;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	auto fast_exponentiation = [&](int a, int n, int p) {
		int ret = 1;
		for (; n; n >>= 1, a = a * 1LL * a % p) if (n & 1) ret = ret * 1LL * a % P;
		return ret;
	};
	int T = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		dp[u] = dp[p] + 1, f[0][u] = p;
		for (int i = 1; i < 18; i++) f[i][u] = f[i-1][f[i-1][u]];
		sz[u] = 1;
		st[u] = ++T;
		for (int e : adj[u]) {
			int v = E[e].first ^ E[e].second ^ u;
			if (v == p) continue;
			dfs(v, u);
			sz[u] += sz[v];
		}
		en[u] = T;
	};
	auto lca = [&](int u, int v) {
		if (dp[u] < dp[v]) swap(u, v);
		for (int i = 0, diff = dp[u] - dp[v]; (1<<i) <= diff; i++) if (diff>>i&1) u = f[i][u];
		if (u == v) return u;
		for (int i = 31-__builtin_clz(dp[u]); i >= 0; i--) if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
		return f[0][u];
	};
	auto go_up = [&](int u, int d) {
		for (int i = 17; i >= 0; i--) {
			if (d >> i & 1) u = f[i][u];
		}
		return u;
	};
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		E[i] = {u, v};
		adj[u].push_back(i);
		adj[v].push_back(i);
		H[{u, v}] = H[{v, u}] = i;
	}
	dfs(1, 0);
	int dsum = 0;
	vector<pair<int, int>> Q;
	for (int i = 1; i <= q; i++) {
		int op; cin >> op;
		if (op == 1) {
			int v, d; cin >> v >> d;
			dsum = (dsum + d) % P;
			Q.emplace_back(v, d);
		} else {
			int v; cin >> v;
			int del = 0;
			for (auto t : Q) {
				int u = t.first;
				if (u == v) continue;
				int x = lca(u, v);
				if (u != x) x = f[0][u];
				else x = go_up(v, dp[v] - dp[x] - 1);
				if (x == f[0][u]) {
					del = (del + (n - sz[u]) * 1LL * t.second) % P;
				} else {
					del = (del + sz[x] * 1LL * t.second) % P;
				}
			}
			del = (del + ans[v]) % P;
			del = del * 1LL * fast_exponentiation(n, P - 2, P) % P;
			cout << (dsum + P - del) % P << '\n';
		}
		if (i % M == 0) {
			sort(Q.begin(), Q.end());
			int last = 0;
			vector<int> V;
			for (auto t : Q) {
				if (last == t.first) add[last] = (add[last] + t.second) % P;
				else add[t.first] = t.second, V.push_back(t.first);
				last = t.first;
			}
			for (int j = 1; j <= n; j++) {
				a[j] = 0;
			}
			auto inc = [&](int l, int r, int x) {
				if (l > r) return;
				a[l] = (a[l] + x) % P;
				a[r + 1] = (a[r + 1] + P - x) % P;
			};
			for (int v : V) {
				for (int e : adj[v]) {
					int u = v ^ E[e].first ^ E[e].second;
					if (u == f[0][v]) {
						inc(1, st[v] - 1, (n - sz[v]) * 1LL * add[v] % P);
						inc(en[v] + 1, n, (n - sz[v]) * 1LL * add[v] % P);
					} else {
						inc(st[u], en[u], sz[u] * 1LL * add[v] % P);
					}
				}
			}
			for (int v : V) {
				add[v] = 0;
			}
			for (int j = 1; j <= n; j++) {
				a[j + 1] = (a[j] + a[j + 1]) % P;
			}
			for (int j = 1; j <= n; j++) {
				ans[j] = (ans[j] + a[st[j]]) % P;
			}
			Q.clear();
		}
	}
	return 0;
}