#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 19;
const int M = 19;

struct Lca {
	vector<int> g[N];
	int dep[N], up[N][M];
	void add(int a, int b) {
		g[a].pb(b); g[b].pb(a);
	}
	void dfs(int v = 1, int p = 0) {
		dep[v] = dep[p] + 1;
		up[v][0] = p;
		rep(i, 1, M - 1)
			up[v][i] = up[up[v][i - 1]][i - 1];
		for (auto u : g[v])
			if (u != p)	
				dfs(u, v);
	}
	int lca(int a, int b) {
		if (dep[a] < dep[b]) swap(a, b);
		per(i, 0, M - 1)
			if (dep[up[a][i]] >= dep[b])
				a = up[a][i];
		if (a == b) return a;
		per(i, 0, M - 1)
			if (up[a][i] != up[b][i])
				a = up[a][i], b = up[b][i];
		return up[a][0];
	}
	int jump(int v, int k) {
		rep(i, 0, M - 1)
			if (k >> i & 1)
				v = up[v][i];
		return v;
	}
	int qq(int v, int u) {
		return jump(u, dep[u] - dep[v] - 1);
	}
} T;

ll ans;
int n, m, id[N], dp[N];
vector<int> g[N], rm[N];
vector<pair<int, int>> e[N];

int f(int v, int u) {
	if (v == u) return ++id[v];
	return T.qq(v, u);
}

void dfs(int v, int p) {
	map<int, int> cnt;
	map<pair<int, int>, int> pairs;
	for (auto &[a, b] : e[v]) {
		if (a > b) swap(a, b);
		cnt[a]++;
		cnt[b]++;
		pairs[{a, b}]++;
	}
	for (auto &[a, b] : e[v]) {
		ans += sz(e[v]) - 1;
		ans -= cnt[a] - 1;
		ans -= cnt[b] - 1;
		ans += pairs[{a, b}] - 1;
	}
	for (auto u : g[v])
		if (u != p)
			dfs(u, v);
}

void go(int v, int p) {
	for (auto u : g[v]) {
		if (u == p) continue;
		go(u, v);
		dp[v] += dp[u];
	}
	for (auto x : rm[v]) {
		if (x == v) continue;
		dp[T.qq(v, x)]--;
	}
	ans += ll(sz(e[v])) * dp[v];
	for (auto [a, b] : e[v]) {
		if (a <= n) ans -= dp[a];
		if (b <= n) ans -= dp[b];
	}
}
 
int main() {
	scanf("%d", &n);
	rep(i, 2, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
		T.add(a, b);
	}
	T.dfs();
	rep(i, 1, n) id[i] = n;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int c = T.lca(a, b);
		e[c].pb({f(c, a), f(c, b)});
		dp[a]++; dp[b]++; dp[c] -= 2;
		rm[c].pb(a);
		rm[c].pb(b);
	}
	dfs(1, 0);
	ans /= 2;
	go(1, 0);
	printf("%lld\n", ans);
	return 0;
}