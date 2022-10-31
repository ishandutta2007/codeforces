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

int dp[MAXN], c[MAXN], a[MAXN], b[MAXN], sz[MAXN];
VPII adj[MAXN];

void dfs(int u, int p) {
	dp[u] = dp[p] + 1, sz[u] = 1;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i].first;
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(PII(v, w));
		adj[v].push_back(PII(u, w));
		a[i] = u, b[i] = v, c[i] = w;
	}
	dfs(1, 0);
	for (int i = 1; i < n; i++) {
		if (dp[a[i]] < dp[b[i]]) swap(a[i], b[i]);
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) ans += 1LL * sz[a[i]] * (n - sz[a[i]]) * c[i];
	int q; scanf("%d", &q);
	while (q--) {
		int e, w; scanf("%d%d", &e, &w);
		ans += 1LL * sz[a[e]] * (n - sz[a[e]]) * (w - c[e]);
		c[e] = w;
		printf("%.10lf\n", 6.0 * ans / n / (n - 1));
	}
	return 0;
}