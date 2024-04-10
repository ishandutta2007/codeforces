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

const long long INF = 1LL<<40;
const int MAXN = 110000;
const int MAXM = 1100000;

VPII A[MAXM], B[MAXM];
long long dp[MAXN], f[MAXM];

void solve(int n) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) dp[i] = INF, sum += dp[i];
	for (int d = 1000000; d > 0; d--) {
		for (int j = 0; j < sz(B[d]); j++) {
			int i = B[d][j].first, c = B[d][j].second;
			if (dp[i] > c) sum += c - dp[i], dp[i] = c;
		}
		f[d] = sum;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int d, f, t, c; scanf("%d%d%d%d", &d, &f, &t, &c);
		if (!t) A[d].push_back(PII(f, c));
		else B[d].push_back(PII(t, c));
	}
	solve(n);
	long long sum = 0;
	for (int i = 1; i <= n; i++) dp[i] = INF, sum += dp[i];
	long long ans = 1LL<<60;
	for (int d = 1; d + k + 1 <= 1000000; d++) {
		for (int j = 0; j < sz(A[d]); j++) {
			int i = A[d][j].first, c = A[d][j].second;
			if (dp[i] > c) sum += c - dp[i], dp[i] = c;
		}
		chkmin(ans, sum + f[d + k + 1]);
	}
	if (ans > (1LL<<40)) ans = -1;
	cout << ans << endl;
	return 0;
}