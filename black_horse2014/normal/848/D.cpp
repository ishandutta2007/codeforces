#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

int g[55], dp[55][55], ans[55][55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	dp[0][1] = ans[0][1] = 1;
	g[1] = 1;
	for (int i = 2; i <= n; i++) g[i] = 1LL * (MOD - g[MOD % i]) * (MOD / i) % MOD;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= i-1; k++) {
			int s = 0, t = 0;
			for (int j = max(k+2, i-k+2); j > 0; j--) {
				s = (s + ans[k][j-1]) % MOD;
				t = (t + ans[i-k-1][j-1]) % MOD;
				dp[i][j] = (dp[i][j] + 1LL * s * t) % MOD;
			}
		}
		for (int j = 1; j <= i+1; j++) {
			dp[i][j] = (dp[i][j] - dp[i][j+1] + MOD) % MOD;
			if (dp[i][j] == 0) continue;
			for (int k = n; k >= i; k--) {
				for (int l = k+1; l >= j; l--) {
					int cur = 1;
					for (int r = 1; r <= k; r++) {
						if (i * r > k || (j - 1) * r > l - 1) break;
						cur = 1LL * cur * (dp[i][j] + r - 1) % MOD * g[r] % MOD;
						ans[k][l] = (ans[k][l] + 1LL * ans[k-r*i][l-r*(j-1)] * cur) % MOD;
					}
				}
			}
		}
	}
	cout << ans[n][m] << endl;
	return 0;
}