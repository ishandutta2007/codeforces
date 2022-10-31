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

int dp[2][32];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= 31; i++) dp[0][i] = -1e9;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x); x /= 100; sum += x;
		int now = i & 1;
		for (int j = 0; j <= 31; j++) dp[now][j] = -1e9;
		for (int j = 0; j <= 31 - x / 10; j++) chkmax(dp[now][j + x / 10], dp[!now][j]);
		for (int j = 0; j <= 31; j++) chkmax(dp[now][max(j - x, 0)], dp[!now][j] + min(j, x));
		for (int j = 30; j >= 0; j--) chkmax(dp[now][j], dp[now][j + 1]);
	}
	int ans = 0;
	for (int j = 0; j <= 31; j++) chkmax(ans, dp[n&1][j]);
	cout << (sum - ans) * 100 << endl;
	return 0;
}