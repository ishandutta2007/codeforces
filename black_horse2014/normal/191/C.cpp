#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 111111;

int f[17][MAXN], dp[MAXN], cnt[MAXN];
int x[MAXN], y[MAXN];
VI adj[MAXN];

void dfs(int u, int p) {
	dp[u] = dp[p] + 1;
	f[0][u] = p;
	for (int i = 1; i <= 16; i++) f[i][u] = f[i-1][f[i-1][u]];
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
}

void solve(int u, int p) {
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		solve(v, u);
		cnt[u] += cnt[v];
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

int main() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
		x[i] = u, y[i] = v;
	}
	dfs(1, 0);
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		int w = lca(u, v);
		cnt[u]++, cnt[v]++, cnt[w] -= 2;
	}
	solve(1, 0);
	for (int i = 1; i < n; i++) {
		if (dp[x[i]] < dp[y[i]]) swap(x[i], y[i]);
		printf("%d%c", cnt[x[i]], i < n-1 ? ' ' : '\n');
	}
	return 0;
}