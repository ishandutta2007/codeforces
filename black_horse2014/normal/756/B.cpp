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

const int MAXN = 333333;

int a[MAXN];
int dp[MAXN];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 1, j = 1, k = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[i] = dp[i-1] + 20;
		while (j < i && a[i] - a[j] >= 1440) {
			j++;
		}
		while (k < i && a[i] - a[k] >= 90) {
			k++;
		}
		if (j < i) chkmin(dp[i], dp[j-1] + 120);
		if (k < i) chkmin(dp[i], dp[k-1] + 50);
		printf("%d\n", dp[i] - dp[i-1]);
	}
	return 0;
}