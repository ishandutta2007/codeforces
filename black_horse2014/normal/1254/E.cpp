#include <bits/stdc++.h>
using namespace std;
 
const int N = 1100000;
const int P = 1e9 + 7;
 
vector<int> adj[N];
int con[N], rcon[N];
map<pair<int, int>, int> H;
pair<int, int> E[N];
int dp[N], a[N], g[N], f[20][N];
pair<int, int> chk[N];
int X[N];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	auto go = [&]() {
		cout << 0 << endl;
		exit(0);
	};
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(2 * i - 1);
		adj[v].push_back(2 * i);
		E[2 * i - 1] = {u, v};
		E[2 * i] = {v, u};
		H[{u, v}] = 2 * i - 1;
		H[{v, u}] = 2 * i;
	}
	int T = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		dp[u] = dp[p] + 1, f[0][u] = p;
		for (int i = 1; i < 20; i++) f[i][u] = f[i-1][f[i-1][u]];
		for (int e : adj[u]) {
			int v = E[e].first ^ E[e].second ^ u;
			if (v == p) continue;
			dfs(v, u);
		}
	};
	auto lca = [&](int u, int v) {
		if (dp[u] < dp[v]) swap(u, v);
		for (int i = 0, diff = dp[u] - dp[v]; (1<<i) <= diff; i++) if (diff>>i&1) u = f[i][u];
		if (u == v) return u;
		for (int i = 31-__builtin_clz(dp[u]); i >= 0; i--) if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
		return f[0][u];
	};
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) {
			if (i == a[i]) go();
			int p = lca(i, a[i]);
			int u = i, num = 0;
			while (u != p) {
				int e = H[{u, f[0][u]}];
				if (chk[e].first) go();
				chk[e] = {i, ++num};
				u = f[0][u];
			}
			int v = a[i];
			vector<int> V;
			while (v != p) {
				int e = H[{f[0][v], v}];
				if (chk[e].first) {
					go();
				}
				V.push_back(e);
				chk[e].first = i;
				v = f[0][v];
			}
			reverse(V.begin(), V.end());
			for (int e : V) {
				chk[e].second = ++num;
			}
		}
	}
	int ret = 1;
	for (int i = 1; i <= n; i++) {
		vector<int> V;
		for (int e : adj[i]) {
			int j = E[e].first ^ E[e].second ^ i;
			V.push_back(e);
			if (e & 1) V.push_back(e + 1), X[e + 1] = e;
			else V.push_back(e - 1), X[e - 1] = e;
			X[e] = e;
		}
		sort(V.begin(), V.end(), [&](int e, int f) { return chk[e] < chk[f]; });
		for (int e : adj[i]) g[e] = e;
		function<int(int)> find_set = [&](int u) {
			return g[u] == u ? u : g[u] = find_set(g[u]);
		};
		auto add_edge = [&](int x, int y) {
			con[x]++;
			rcon[y]++;
			x = find_set(x);
			y = find_set(y);
			if (x == y) return 0;
			g[x] = y;
			return 1;
		};
		int L = 0, R = 0;
		int tot = adj[i].size();
		for (int j = 0, k; j < V.size(); j = k) {
			for (k = j; k < V.size() && chk[V[j]].first == chk[V[k]].first; k++) {
				if (chk[V[j]].first) {
					if (k > j) {
						if (!add_edge(X[V[j]], X[V[k]])) go();
						tot--;
					}
				}
			}
			if (chk[V[j]].first) {
				if (k == j + 1) {
					int x = chk[V[j]].first;
					if (a[x] == i) R = X[V[j]];
					else L = X[V[j]];
				}
			}
		}
		if (rcon[L] || con[R]) go();
		for (int e : adj[i]) if (con[e] > 1 || rcon[e] > 1) go();
		tot -= !!L; tot -= !!R;
		if (L && R && find_set(L) == find_set(R) && tot >= 0) go();
		tot = max(tot, 0);
		for (int j = 1; j <= tot; j++) ret = ret * 1LL * j % P;
	}
	cout << ret << endl;
	return 0;
}