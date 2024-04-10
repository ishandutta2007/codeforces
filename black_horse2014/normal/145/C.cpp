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

const int MOD = 1e9+7;
const int MAXN = 111111;

int val[1030], cnt[1030];
int dp[1030];

int rev[MAXN], f[MAXN], g[MAXN];
int tot;

int C(int n, int m) {
	if (m < 0 || n < m) return 0;
	int ret = 1LL*f[n]*g[m]%MOD*g[n-m]%MOD;
	return ret;
}

int get_id(int x) {
	int ret = lower_bound(val, val + tot, x) - val;
	if (ret == tot || val[ret] != x) return -1;
	return ret;
}

int main() {
	
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j < bit(i); j++) {
			int x = 0;
			for (int k = 0; k < i; k++) {
				x *= 10;
				if (j >> k & 1) {
					x += 7;
				} else {
					x += 4;
				}
			}
			val[tot++] = x;
		}
	}
	sort(val, val + tot);
	int n, m; scanf("%d%d", &n, &m);
	int r = 0;
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		int j = get_id(x);
		if (~j) cnt[j]++;
		else r++;
	}
	dp[0] = 1;
	for (int i = 0; i < tot; i++) {
		for (int j = i; j >= 0; j--) {
			dp[j+1] = (dp[j+1] + 1LL*dp[j]*cnt[i]) % MOD;
		}
	}
	rev[1] = f[1] = g[1] = g[0] = f[0] = 1;
	for (int i = 2; i < MAXN; i++) {
		rev[i] = (LL)(MOD-rev[MOD%i]) * (MOD/i) % MOD;
		f[i] = (LL)f[i-1]*i%MOD;
		g[i] = (LL)g[i-1]*rev[i]%MOD;
	}
	int ans = 0;
	for (int i = 0; i <= tot && i <= m; i++) {
		ans = (ans + (LL)C(r, m-i)*dp[i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}