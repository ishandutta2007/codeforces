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

int dp[440][440];
int C[440][440];

const int MOD = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
		}
	}
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n-j; k++) {
				int temp = 1LL * dp[i-1][j] * dp[i-1][k] % MOD;
				add(dp[i][j+k], temp);
				if (j+k+1 <= n) add(dp[i][j+k+1], temp);
				add(dp[i][j+k], 2LL * (j+k) * temp % MOD);
				if (j + k > 0) add(dp[i][j+k-1], 1LL * temp * (j+k) * (j+k-1) % MOD);
			}
		}
	}
	cout << dp[n][1] << endl;
	return 0;
}