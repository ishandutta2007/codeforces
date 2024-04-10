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
bool dp[32][81][2500];

int ans[100][100], d[100], s[100], b[100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int m; scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	sort(a + 1, a + m + 1);
	dp[0][0][0] = 1;
	for (int j = 1; j <= m; j++) {
		for (int i = j; i <= 80; i++) {
			for (int k = i*30; k >= i*(i-1)/2 && k >= a[j]; k--) {
				dp[j][i][k] |= dp[j-1][i-1][k-a[j]] | dp[j][i-1][k-a[j]];
			}
		}
	}
	int n = 0;
	for (int i = 1; i <= 61; i++) if (dp[m][i][i*(i-1)/2]) { n = i; break; }
	if (n == 0) {
		puts("=(");
		return 0;
	}
	cout << n << endl;
	int cur = n, sum = n*(n-1)/2;
	for (int i = m; i > 0; i--) {
		while (cur >= i && dp[i][cur-1][sum-a[i]]) d[cur] = a[i], cur--, sum -= a[i];
		if (cur >= i && !dp[i][cur-1][sum-a[i]]) d[cur] = a[i], cur--, sum -= a[i];
	}
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + d[i];
	for (int i = n; i > 0; i--) {
		for (int j = i-1; j > 0; j--) b[j] = min(j == i-1 ? 10000 : b[j+1], s[j]-j*(j-1)/2);
		for (int j = 1; j < i; j++) ans[i][j] = 1, ans[j][i] = 0;
		for (int j = 1, k = 1; j <= i-1-d[i]; j++) {
			while (k < i && b[k] < j) k++;
			if (k < i && b[k] >= j) ans[i][k] = 0, ans[k][i] = 1, d[k]--, k++;
		}
		for (int j = 1; j < i; j++) s[j] = s[j-1] + d[j];
	}
	for (int j = 1; j <= n; j++, puts("")) for (int k = 1; k <= n; k++) printf("%d", ans[j][k]);
	return 0;
}