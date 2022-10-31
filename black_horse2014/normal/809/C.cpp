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

const int MOD = 1e9 + 7;

int dp[2][4][2], sum[2][4][2];
int x[2], y[2];

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int calc(int x, int y, int m) {
	if (x == 0 || y == 0) return 0;
	x--, y--, m--;
	int n = 32 - clzi(max(max(x, y), m));
	memset(dp, 0, sizeof dp);
	memset(sum, 0, sizeof sum);
	dp[0][0][0] = 1;
	int now = 0;
	for (int i = n; i >= 0; i--) {
		now ^= 1;
		memset(dp[now], 0, sizeof dp[now]);
		memset(sum[now], 0, sizeof sum[now]);
		int a[2], b, ma[2], mb;
		a[0] = x >> i & 1, a[1] = y >> i & 1, b = m >> i & 1;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				if (j & 1) {
					ma[0] = 2;
				} else {
					ma[0] = a[0]+1;
				}
				if (j & 2) {
					ma[1] = 2;
				} else {
					ma[1] = a[1]+1;
				}
				if (k) mb = 2;
				else mb = b+1;
				for (int l = 0; l < ma[0]; l++) {
					for (int ll = 0; ll < ma[1]; ll++) {
						if ((l ^ ll) >= mb) continue;
						int nj1 = !!(((j & 1) || (l < a[0])));
						int nj2 = !!((((j & 2) > 0) || (ll < a[1])));
						int nk = !!((k || ((l ^ ll) < b)));
						add(dp[now][nj2 * 2 + nj1][nk], dp[!now][j][k]);
						add(sum[now][nj2 * 2 + nj1][nk], sum[!now][j][k] * 2 % MOD);
						if (l != ll) add(sum[now][nj2 * 2 + nj1][nk], dp[!now][j][k]);
					}
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			add(ret, sum[now][i][j]);
			add(ret, dp[now][i][j]);
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		for (int i = 0; i < 2; i++) scanf("%d%d", &x[i], &y[i]); x[0]--, y[0]--;
		int m; scanf("%d", &m);
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if (i == j) ans = (ans + calc(x[i], y[j], m)) % MOD;
				else ans = (ans + MOD - calc(x[i], y[j], m)) % MOD;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}