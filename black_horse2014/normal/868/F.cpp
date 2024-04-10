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

int b[MAXN], a[MAXN];
long long dp[2][MAXN];

void solve(int now, int s, int e, int l, int r, long long add) {
	if (e < s) return;
	int m = s + e >> 1;
	long long &ret = dp[now][m], p = l;
	for (int i = s; i <= m; i++) add += b[a[i]], b[a[i]]++;
	for (int i = l; i <= r && i <= m-1; i++) {
		if (i > l) b[a[i]]--, add -= b[a[i]];
		if (ret > add + dp[!now][i]) ret = add + dp[!now][i], p = i;
	}
	for (int i = min(r, m-1); i > p; i--) add += b[a[i]], b[a[i]]++;
	solve(now, m+1, e, p, r, add);
	for (int i = p; i > l; i--) add += b[a[i]], b[a[i]]++;
	for (int i = m; i >= s; i--) b[a[i]]--, add -= b[a[i]];
	solve(now, s, m-1, l, p, add);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) dp[1][i] = dp[1][i-1] + b[a[i]], b[a[i]]++;
	for (int i = 2; i <= m; i++) {
		for (int j = 1; j <= n; j++) dp[i&1][j] = 1LL<<60;
		memset(b, 0, sizeof b);
		solve(i & 1, i, n, i-1, n-1, 0);
	}
	cout << dp[m&1][n] << endl;
	return 0;
}