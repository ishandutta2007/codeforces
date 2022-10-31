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

double dp[2][2222][2222];
double p[2222], u[2222];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &u[i]);
	int now = 0;
	for (int i = 1; i <= n; i++) {
		now ^= 1;
		for (int j = 1; j <= a && j <= i; j++) dp[now][j][0] = max(dp[!now][j][0], dp[!now][j-1][0] + p[i]);
		for (int k = 1; k <= b && k <= i; k++) dp[now][0][k] = max(dp[!now][0][k], dp[!now][0][k-1] + u[i]);
		for (int j = max(1, a - (n - i)); j <= i && j <= a; j++) {
			for (int k = max(1, b - (n - i)); k <= i && k <= b; k++) {
				dp[now][j][k] = max(dp[!now][j][k], dp[!now][j-1][k-1] + p[i] + u[i] - p[i] * u[i]);
				chkmax(dp[now][j][k], dp[!now][j-1][k] + p[i]);
				chkmax(dp[now][j][k], dp[!now][j][k-1] + u[i]);
			}
		}
	}
	printf("%.12lf\n", dp[now][a][b]);
	return 0;
}