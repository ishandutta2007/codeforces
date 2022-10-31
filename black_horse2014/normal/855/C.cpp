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

int N, M, K, C;

const int MAXN = 110000;
const int MOD = 1e9 + 7;

int a[3], f[3][12], g[3][12];
int dp[3][11][MAXN];

VI adj[MAXN];

void dfs(int u, int p) {
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
	memset(f, 0, sizeof f);
	f[0][0] = a[0];
	f[1][1] = a[1];
	f[2][0] = a[2];
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		memset(g, 0, sizeof g);
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k <= C; k++) if (f[j][k]) {
				for (int jj = 0; jj < 3; jj++) {
					if (j == 1 && jj >= 1) continue;
					if (jj == 1 && j >= 1) continue;
					for (int kk = 0; kk <= C-k; kk++) {
						g[j][k+kk] = (g[j][k+kk] + 1LL * f[j][k] * dp[jj][kk][v]) % MOD;
					}
				}
			}
		}
		memcpy(f, g, sizeof f);
	}
	for (int i = 0; i < 3; i++) for (int j = 0; j <= C; j++) dp[i][j][u] = f[i][j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &N, &M);
	for (int i = 1; i < N; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%d%d", &K, &C);
	a[0] = K-1, a[1] = 1, a[2] = M - K;
	dfs(1, 0);
	int ans = 0;
	for (int i = 0; i < 3; i++) for (int j = 0; j <= C; j++) ans = (ans + dp[i][j][1]) % MOD;
	cout << ans << endl;
	return 0;
}