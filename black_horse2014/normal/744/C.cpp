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

int n;

const int INF = 1<<30;
const int MAXN = 1<<16;

int a[2][16], c[17];
int dp[MAXN][122];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char s[3];
		scanf("%s%d%d", s, &a[0][i], &a[1][i]);
		c[i] = (s[0] == 'B');
	}
	for (int i = 0; i <= n*(n-1)/2; i++) {
		for (int j = 0; j < bit(n); j++) dp[j][i] = -INF;
	}
	dp[0][0] = 0;
	for (int i = 0; i < bit(n); i++) {
		int red = 0, blue = 0;
		for (int k = 0; k < n; k++) {
			if (i >> k & 1) {
				if (!c[k]) red++;
				else blue++;
			}
		}
		for (int k = n*(n-1)/2; k >= 0; k--) {
			if (dp[i][k] == -INF) continue;
			for (int j = 0; j < n; j++) {
				if (i >> j & 1) continue;
				int add = min(a[0][j], red);
				chkmax(dp[i | bit(j)][k + add], dp[i][k] + min(blue, a[1][j]));
			}
		}
	}
	int sum = 0, ans = 0;
	for (int i = 0; i < n; i++) sum += a[1][i], ans += a[0][i];
	int ret = INF;
	for (int i = 0; i <= n*(n-1)/2; i++) {
		if (dp[bit(n)-1][i] == -INF) continue;
		chkmin(ret, max(ans - i, sum - dp[bit(n)-1][i]));
	}
	cout << ret+n << endl;
	return 0;
}