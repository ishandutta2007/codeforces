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

const int MAXN = 110000;

int dp[MAXN], f[17][MAXN];
VI adj[MAXN];

inline int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	for (int i = 0, diff = dp[u] - dp[v]; (1<<i) <= diff; i++) if (diff>>i&1) u = f[i][u];
	if (u == v) return u;
	for (int i = 31-__builtin_clz(dp[u]); i >= 0; i--) if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
	return f[0][u];
}

int a[MAXN], g[17][MAXN], h[17][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, M; scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &f[0][i], &a[i]);
		if (f[0][i] == -1) f[0][i] = 0;
		dp[i] = dp[f[0][i]] + 1;
		g[0][i] = h[0][i] = a[i];
		for (int j = 1; j < 17; j++) {
			f[j][i] = f[j-1][f[j-1][i]];
			g[j][i] = min(g[j-1][i], g[j-1][f[j-1][i]]);
			h[j][i] = max(h[j-1][i], h[j-1][f[j-1][i]]);
		}
	}
	scanf("%d", &M);
	while (M--) {
		int t, u, v; scanf("%d%d%d", &t, &u, &v);
		int w = lca(u, v);
		if (w == 0) {
			puts("NO");
			continue;
		}
		if (v == w) {
			puts("NO");
			continue;
		}
		if (t == 1) {
			if (u != w) {
				puts("NO");
				continue;
			}
			int d = dp[v] - dp[w], wmax = 0;
			for (int j = 0; j < 17; j++) {
				if (d >> j & 1) chkmax(wmax, h[j][v]), v = f[j][v];
			}
			if (wmax == 0) {
				puts("YES");
			} else {
				puts("NO");
			}
		} else {
			int wmin = 1, wmax = 0;
			for (int d = dp[v] - dp[w], j = 0; j < 17; j++) {
				if (d >> j & 1) chkmin(wmin, g[j][v]), v = f[j][v];
			}
			for (int d = dp[u] - dp[w], j = 0; j < 17; j++) {
				if (d >> j & 1) chkmax(wmax, h[j][u]), u = f[j][u];
			}
			if (wmin == 1 && wmax == 0) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}
	return 0;
}