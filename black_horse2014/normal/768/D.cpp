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

double dp[10005][1005];
int ans[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, Q; cin >> N >> Q;
	dp[0][0] = 1;
	int P = 0;
	for (int i = 1; i <= N*10; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = dp[i-1][j] * j / N + dp[i-1][j-1] * (N - j + 1) / N;
		}
		while (P <= 1000 && dp[i][N] * 2000 > P - 1e-7) ans[P] = i, P++;
	}
	while (Q--) {
		int P; scanf("%d", &P);
		printf("%d\n", ans[P]);
	}
	return 0;
}