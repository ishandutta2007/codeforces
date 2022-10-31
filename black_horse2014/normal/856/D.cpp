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

int n, m;

const int MAXN = 210000;

int s[MAXN], ans[2][MAXN], d[MAXN], dp[MAXN], a[MAXN], b[MAXN], c[MAXN], f[18][MAXN];
VI adj[MAXN], V[MAXN];

inline int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	for (int i = 0, diff = dp[u] - dp[v]; (1<<i) <= diff; i++) if (diff>>i&1) u = f[i][u];
	if (u == v) return u;
	for (int i = 31-__builtin_clz(dp[u]); i >= 0; i--) if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
	return f[0][u];
}

void add(int x, int y) {
	for (; x <= n; x += x & -x) d[x] += y;
}

int get(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += d[x];
	return ret;
}

int T;

void dfs(int u) {
	s[u] = ++T;
	ans[0][u] = 0;
	for (auto v : adj[u]) {
		dfs(v);
		ans[0][u] += ans[1][v];
	}
	ans[1][u] = 0;
	for (auto i : V[u]) {
		int x = s[a[i]], y = s[b[i]], z = c[i];
		chkmax(ans[1][u], get(x) + get(y) + c[i]);
	}
	add(s[u], -ans[1][u]);
	add(T + 1, ans[1][u]);
	ans[1][u] += ans[0][u];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &f[0][i]), dp[i] = dp[f[0][i]] + 1;
		for (int j = 1; j < 18; j++) f[j][i] = f[j-1][f[j-1][i]];
		adj[f[0][i]].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		V[lca(a[i], b[i])].push_back(i);
	}
	dfs(1);
	printf("%d\n", ans[1][1]);
	return 0;
}