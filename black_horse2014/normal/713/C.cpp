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

long long dp[3333][3333], pd[3333][3333];
long long a[3333], b[3333], c[3333];

const long long INF = 1LL<<60;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int bn = 0;
	b[bn++] = 0;
	for (int i = 1; i <= n; i++) b[bn++] = a[i] - i;
	sort(b, b + bn);
	bn = unique(b, b + bn) - b;
	for (int i = 0; i <= n; i++) c[i] = lower_bound(b, b + bn, a[i] - i) - b;
	dp[0][0] = 0;
	for (int i = 0; i <= bn; i++) pd[0][i] = INF;
	pd[0][c[0]] = 0;
	for (int i = 1; i <= bn; i++) chkmin(pd[0][i], pd[0][i-1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) dp[i][j] = INF;
		for (int j = 0; j < i; j++) chkmin(dp[i][j], dp[i-1][j] + abs(a[j] + i-j - a[i]));
		long long sum = 0;
		for (int j = i-1; j >= 0; j--) {
			chkmin(dp[i][i], sum + pd[j][c[i]]);
			if (j > 0) sum += abs(a[j] + i - j - a[i]);
		}
		chkmin(dp[i][i], sum);
		for (int j = 0; j <= bn; j++) pd[i][j] = INF;
		for (int j = 0; j <= i; j++) chkmin(pd[i][c[j]], dp[i][j]);
		for (int j = 1; j <= bn; j++) chkmin(pd[i][j], pd[i][j-1]);
	}
	long long ans = INF;
	for (int i = 0; i <= n; i++) chkmin(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}