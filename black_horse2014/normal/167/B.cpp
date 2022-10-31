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

const int MAXN = 222;

double p[MAXN], dp[MAXN][MAXN][MAXN];
int a[MAXN];

int main() {
	
	int N, L, K; scanf("%d%d%d", &N, &L, &K);
	for (int i = 1; i <= N; i++) scanf("%lf", &p[i]), p[i] /= 100;
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]), a[i]++;
	for (int j = 0; j <= K; j++) dp[0][0][j] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j >= 0; j--) {
			for (int k = N; k >= 0; k--) {
				dp[i][j][k] = dp[i-1][j][k] * (1 - p[i]);
				if (j > 0) dp[i][j][k] += dp[i-1][j-1][max(k - a[i], 0)] * p[i];
			}
		}
	}
	double ans = 0;
	for (int i = L; i <= N; i++) ans += dp[N][i][i];
	printf("%.10lf\n", ans);
	return 0;
}