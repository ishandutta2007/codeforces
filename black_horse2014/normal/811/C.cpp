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

int L[5555], R[5555], a[5555], dp[5555], seen[5555];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (!L[a[i]]) L[a[i]] = i;
		R[a[i]] = i;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		if (i == R[a[i]]) {
			int rr = i, ll = i, cur = 0;
			memset(seen, 0, sizeof seen);
			for (int j = i; j >= 1; j--) {
				chkmin(ll, L[a[j]]);
				chkmax(rr, R[a[j]]);
				if (rr > i) break;
				if (!seen[a[j]]) cur ^= a[j], seen[a[j]] = 1;
				if (ll == j) chkmax(dp[i], dp[j-1] + cur);
			}
		}
	}
	cout << dp[n] << endl;
	return 0;
}