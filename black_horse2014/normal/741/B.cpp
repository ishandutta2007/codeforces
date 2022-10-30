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

int n, m, c;

const int MAXN = 1111;

int w[MAXN], b[MAXN], chk[MAXN];
VI V, adj[MAXN];

int dp[2][MAXN];

void dfs(int u) {
	chk[u] = 1; V.pb(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (!chk[v]) dfs(v);
	}
}

int main() {
	
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	int now = 0;
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			V.clear();
			dfs(i);
			now ^= 1;
			memcpy(dp[now], dp[!now], sizeof dp[now]);
			int sw = 0, sb = 0;
			for (int j = 0; j < V.size(); j++) {
				int u = V[j];
				sw += w[u], sb += b[u];
				for (int k = 0; k <= c - w[u]; k++) {
					chkmax(dp[now][k + w[u]], dp[!now][k] + b[u]);
				}
			}
			for (int k = 0; k <= c - sw; k++) {
				chkmax(dp[now][k + sw], dp[!now][k] + sb);
			}
		}
	}
	printf("%d\n", dp[now][c]);
	return 0;
}