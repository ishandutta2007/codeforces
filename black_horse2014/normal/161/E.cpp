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

const int MAXN = 100000;

int chk[MAXN];
int prm[MAXN], prn;

PII b[100];
int pw[11], pw1[11];
int dp[6][161111];
int a[11][11];

int main() {

	for (int i = 2; i < MAXN; i++) if (!chk[i]) {
		prm[prn++] = i;
		for (int j = 2*i; j < MAXN; j += i) chk[j] = 1;
	}
	pw1[0] = pw[0] = 1;
	for (int d = 1; d <= 5; d++) {
		pw1[d] = pw1[d-1] * 11, pw[d] = pw[d-1] * 10;
		for (int i = 0; i < prn && prm[i] < pw[d]; i++) {
			int x = prm[i], nx = 0;
			for (int j = 0; j < d; j++) {
				int y = (x / pw[j]) % 10;
				nx += y * pw1[j];
			}
			dp[d][nx]++;
		}
		for (int j = 0; j < d; j++) {
			for (int x = 0; x < pw1[d]; x++) {
				if ((x / pw1[j]) % 11 == 10) {
					for (int k = 0, y = x - pw1[j]; k < 10; k++, y -= pw1[j]) {
						dp[d][x] += dp[d][y];
					}
				}
			}
		}
	}
	for (int i = 6; i <= 9; i++) pw[i] = pw[i-1] * 10;
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int x; scanf("%d", &x);
		vector<int> d;
		while (x > 0) d.pb(x % 10), x /= 10;
		reverse(all(d));
		int n = d.size();
		for (int i = 0; i < n; i++) a[i][0] = a[0][i] = d[i];
		int xn = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				b[xn++] = PII(i, j);
			}
		}
		unsigned long long ans = 0;
		for (int s = 0; s < pw[xn]; s++) {
			for (int j = 0; j < xn; j++) {
				int r = b[j].first, c = b[j].second;
				a[r][c] = a[c][r] = (s / pw[j]) % 10;
			}
			int cur = 1;
			for (int i = 1; i < n; i++) {
				int t = 0; a[i][i] = 10;
				for (int j = 0; j < n; j++) t *= 11, t += a[i][j];
				cur *= dp[n][t];
			}
			ans += cur;
		}
		printf("%llu\n", ans);
	}
	return 0;
}