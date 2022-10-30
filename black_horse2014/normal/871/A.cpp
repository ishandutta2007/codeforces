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

VI V;
int dp[22];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	for (int i = 1; i <= 20; i++) {
		bool flg = 0;
		for (int j = 2; !flg && j < i; j++) if (i % j == 0) flg = 1;
		if (flg) V.push_back(i);
	}
	dp[0] = 0;
	for (int i = 1; i <= 20; i++) {
		dp[i] = -1e9;
		for (int j = 0; j < sz(V) && V[j] <= i; j++) chkmax(dp[i], dp[i - V[j]] + 1);
	}
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int n; scanf("%d", &n);
		if (n <= 20) {
			if (dp[n] < 0) puts("-1");
			else printf("%d\n", dp[n]);
		} else {
			if (n % 4 == 0) printf("%d\n", n / 4);
			else if (n % 4 == 1) printf("%d\n", (n - 9) / 4 + 1);
			else if (n % 4 == 2) printf("%d\n", (n - 6) / 4 + 1);
			else printf("%d\n", (n - 15) / 4 + 2);
		}
	}
	return 0;
}