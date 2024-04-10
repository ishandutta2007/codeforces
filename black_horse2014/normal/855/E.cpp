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

int a[100];
long long dp[9][61][1024];
long long dp1[9][61][1024];

long long calc(int B, long long U) {
	if (U == 0) return 0;
	int n = 0;
	U++;
	while (U) a[n++] = U % B, U /= B;
	reverse(a, a + n);
	long long ret = 0;
	for (int i = 2; i <= n-1; i += 2) ret += dp[B-2][i][0];
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = (i == 0); j < a[i]; j++) ret += dp1[B-2][n-i-1][s^bit(j)];
		s ^= bit(a[i]);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q; scanf("%d", &q);
	for (int b = 2; b <= 10; b++) {
		dp[b-2][0][0] = dp1[b-2][0][0] = 1;
		for (int j = 1; j < b; j++) dp[b-2][1][bit(j)] = dp1[b-2][1][bit(j)] = 1;
		dp1[b-2][1][1] = 1;
		for (int i = 2; i <= 60; i++) {
			for (int j = 0; j < bit(b); j++) {
				for (int k = 0; k < b; k++) dp[b-2][i][j] += dp[b-2][i-1][j^bit(k)];
				for (int k = 0; k < b; k++) dp1[b-2][i][j] += dp1[b-2][i-1][j^bit(k)];
			}
		}
	}
	while (q--) {
		int B; long long L, R; scanf("%d%lld%lld", &B, &L, &R);
		printf("%lld\n", calc(B, R) - calc(B, L-1));
	}
	return 0;
}