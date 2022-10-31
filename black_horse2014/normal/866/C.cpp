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

const double inf = 1e15;
int f[55], s[55], p[55];

double dp[5500][55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, R; cin >> N >> R;
	for (int i = 0; i < N; i++) scanf("%d%d%d", &f[i], &s[i], &p[i]);
	for (int i = R; i <= R+100; i++) for (int j = 0; j <= N; j++) dp[i][j] = inf;
	dp[R][N] = 0;
	double lo = 0, hi = 1e14;
	for (int t = 0; t < 100; t++) {
		double mid = (lo + hi) / 2;
		for (int i = R-1; i >= 0; i--) {
			for (int j = N-1; j >= 0; j--) {
				dp[i][j] = (f[j] + min(dp[i+f[j]][j+1], mid)) * p[j] / 100 + (s[j] + min(mid, dp[i+s[j]][j+1])) * (100 - p[j]) / 100;
			}
		}
		if (dp[0][0] > mid) lo = mid;
		else hi = mid;
	}
	printf("%.15lf\n", hi);
	return 0;
}