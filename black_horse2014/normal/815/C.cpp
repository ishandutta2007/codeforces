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

const int INF = 1e9 + 7;

int c[5555], d[5555], dp[2][5555][5555], f[5555], g[5555], p[5555], sz[5555];

VI adj[5555];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &c[i], &d[i]);
		if (i >= 2) scanf("%d", &p[i]);
	}
	for (int i = 2; i <= n; i++) adj[p[i]].push_back(i);
	for (int i = n; i > 0; i--) {
		sz[i]++, sz[p[i]] += sz[i];
		for (int j = 1; j <= sz[i]; j++) dp[1][i][j] = dp[0][i][j] = INF;
		for (int tp = 0; tp < 2; tp++) {
			for (int j = 1; j <= sz[i]; j++) f[j] = INF; f[0] = 0;
			int cur = 0;
			for (int j = 0; j < sz(adj[i]); j++) {
				int v = adj[i][j];
				for (int k = 0; k <= sz[v] + cur; k++) g[k] = INF;
				for (int k = 0; k <= sz[v]; k++) {
					for (int l = 0; l <= cur; l++) chkmin(g[k + l], f[l] + dp[tp][v][k]);
				}
				cur += sz[v];
				for (int k = 0; k <= cur; k++) f[k] = g[k];
			}
			if (tp == 1) {
				for (int j = 1; j <= sz[i]; j++) chkmin(dp[tp][i][j], f[j-1] + c[i] - d[i]);
			} else {
				for (int j = 0; j <= sz[i]; j++) {
					chkmin(dp[tp][i][j], f[j]);
					if (j > 0) chkmin(dp[tp][i][j], f[j-1] + c[i]);
				}
			}
		}
		for (int j = 1; j <= sz[i]; j++) chkmin(dp[1][i][j], dp[0][i][j]);
	}
	for (int j = n; j >= 0; j--) {
		if (dp[1][1][j] <= m) {
			cout << j << endl;
			return 0;
		}
	}
	assert(0);
	return 0;
}