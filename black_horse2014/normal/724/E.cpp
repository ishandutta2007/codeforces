#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
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

const long long INF = 1LL << 60;
const int MAXN = 11111;

int a[MAXN], b[MAXN];
long long dp[MAXN];

int main() {
	int N, C; scanf("%d%d", &N, &C);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= N; i++) dp[i] = INF;
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + b[i];
		for (int j = i - 1; j > 0; j--) dp[j] = min(dp[j] + a[i] + 1LL * j * C, dp[j - 1] + b[i]);
		dp[0] = dp[0] + a[i];
	}
	long long ans = INF;
	for (int j = 0; j <= N; j++) chkmin(ans, dp[j]);
	cout << ans << endl;
	return 0;
}