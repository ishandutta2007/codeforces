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

const int INF = 0x3f3f3f3f;
const int MAXN = 88;

int dp[2][MAXN][MAXN][MAXN];
VPII adj[MAXN];

int f[MAXN], g[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, K, M; cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(PII(v, w));
	}
	if (K == 1) {
		puts("0");
		return 0;
	}
	memset(dp, 0x3f, sizeof dp);
	for (int s = 0; s < N; s++) {
		for (int e = s+2; e <= N+1; e++) {
			for (int i = s+1; i < e; i++) {
				for (int j = 0; j < sz(adj[i]); j++) {
					int k = adj[i][j].first, w = adj[i][j].second;
					if (k < i) {
						if (s < k) chkmin(dp[1][s][i][k], w);
					}
					if (k > i) {
						if (e > k) chkmin(dp[1][i][e][k], w);
					}
				}
			}
		}
	}
	int now = 1;
	for (int t = 2; t < K; t++) {
		now ^= 1;
		memset(dp[now], 0x3f, sizeof dp[now]);
		for (int i = 1; i <= N; i++) {
			for (int s = 0; s < i; s++) {
				int cur = INF;
				for (int e = N+1; e > i; e--) chkmin(cur, dp[!now][s][e][i]);
				f[s] = cur;
			}
			for (int e = i+1; e <= N+1; e++) {
				int cur = INF;
				for (int s = 0; s < i; s++) chkmin(cur, dp[!now][s][e][i]);
				g[e] = cur;
			}
			for (int j = 0; j < sz(adj[i]); j++) {
				int k = adj[i][j].first, w = adj[i][j].second;
				if (k < i) {
					for (int s = 0; s < k; s++) chkmin(dp[now][s][i][k], f[s] + w);//, cerr << t << ' ' << s << ' ' << i << ' ' << k << ' ' << f[s] + w << endl;
				}
				if (k > i) {
					for (int e = k+1; e <= N+1; e++) chkmin(dp[now][i][e][k], g[e] + w);//, cerr << t << ' ' << i << ' ' << e << ' ' << k << ' ' << g[e] + w << endl;
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 2; j <= N+1; j++) {
			for (int k = 1; k <= N; k++) chkmin(ans, dp[now][i][j][k]);
		}
	}
	if (ans == INF) puts("-1");
	else printf("%d\n", ans);
	return 0;
}