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

int N, M, MOD;
int K;

const int MAXN = 666;

VI adj[MAXN], radj[MAXN];
int deg[MAXN], a[MAXN][MAXN], dp[MAXN][MAXN];
int Q[MAXN];
int QN;

VI S, T;

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

int main() {
	
	scanf("%d%d%d", &N, &M, &MOD);
	for (int i = 1; i <= M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
		deg[v]++;
	}
	for (int i = 1; i <= N; i++) {
		if (radj[i].empty()) S.push_back(i);
		if (adj[i].empty()) T.push_back(i);
	}
	K = S.size();
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][S[j-1]] = (i == j);
		}
		Q[QN++] = S[i-1];
	}
	for (int i = 0; i < QN; i++) {
		int u = Q[i];
		for (int k = 1; k <= K; k++) {
			if (dp[k][u]) {
				for (int j = 0; j < sz(adj[u]); j++) {
					int v = adj[u][j];
					dp[k][v] = (dp[k][v] + dp[k][u]) % MOD;
				}
			}
		}
		for (int j = 0; j < sz(adj[u]); j++) {
			int v = adj[u][j];
			if (--deg[v] == 0) Q[QN++] = v;
		}
	}
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			a[i][j] = dp[i][T[j-1]];
		}
	}
	int ans = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = i; j <= K; j++) {
			if (a[j][i]) {
				for (int k = i; k <= K; k++) swap(a[i][k], a[j][k]);
				if (j > i) ans = (MOD - ans) % MOD;
				break;
			}
		}
		if (!a[i][i]) {
			puts("0");
			return 0;
		}
		ans = 1LL * ans * a[i][i] % MOD;
		int r = modExp(a[i][i], MOD-2, MOD);
		for (int j = i+1; j <= K; j++) if (a[j][i]) {
			int s = 1LL * r * (MOD - a[j][i]) % MOD;
			for (int k = i; k <= K; k++) {
				a[j][k] = (a[j][k] + 1LL * s * a[i][k]) % MOD;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}