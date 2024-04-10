#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int MAXN = 111111;

long long d[MAXN];
int dp[MAXN], f[17][MAXN];

int st[MAXN], _st[MAXN];

set<int> S;
vector<PII> adj[MAXN];
int T;

void dfs(int u, int p) {
	st[u] = ++T, _st[T] = u, dp[u] = dp[p] + 1;
	f[0][u] = p;
	for (int i = 1; i <= 16; i++) f[i][u] = f[i-1][f[i-1][u]];
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first, w = adj[u][i].second;
		if (v == p) continue;
		d[v] = d[u] + w;
		dfs(v, u);
	}
}

int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	int d = dp[u] - dp[v];
	for (int i = 16; i >= 0; i--) if (d >> i & 1) u = f[i][u];
	if (u == v) return u;
	for (int i = 16; i >= 0; i--) {
		if (f[i][u] == f[i][v]) continue;
		u = f[i][u], v = f[i][v];
	}
	return f[0][u];
}

long long dist(int u, int v) {
	return d[u] + d[v] - 2*d[lca(u, v)];
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(PII(v, w));
		adj[v].push_back(PII(u, w));
	}
	dfs(1, 0);
	int q; scanf("%d", &q);
	long long ans = 0;
	while (q--) {
		char s[3]; scanf("%s", s);
		if (s[0] == '+') {
			int u; scanf("%d", &u);
			if (S.empty()) {
				S.insert(st[u]);
				continue;
			}
			set<int> :: iterator it = S.upper_bound(st[u]);
			int a, b;
			if (it == S.end() || it == S.begin()) {
				a = _st[*S.begin()], b = _st[*(--S.end())];
			} else {
				b = _st[*it], a = _st[*(--it)];
			}
			S.insert(st[u]);
			ans += (dist(u, a) + dist(u, b) - dist(a, b)) / 2;
		} else if (s[0] == '-') {
			int u; scanf("%d", &u);
			S.erase(st[u]);
			if (S.empty()) continue;
			set<int> :: iterator it = S.upper_bound(st[u]);
			int a, b;
			if (it == S.end() || it == S.begin()) {
				a = _st[*S.begin()], b = _st[*(--S.end())];
			} else {
				b = _st[*it], a = _st[*(--it)];
			}
			ans -= (dist(u, a) + dist(u, b) - dist(a, b)) / 2;
		} else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}