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

const int INF = 1000000000;

int n, m, q;

int a[1111][66][66];
int c[66][66];

int main() {
	
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) a[0][i][j] = INF;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				scanf("%d", &c[j][k]);
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int l = 1; l <= n; l++) {
					chkmin(c[k][l], c[k][j] + c[j][l]);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				chkmin(a[0][j][k], c[j][k]);
			}
		}
	}
	for (int k = 1; k <= 1000; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[k][i][j] = INF;
				for (int l = 1; l <= n; l++) chkmin(a[k][i][j], a[k-1][i][l] + a[0][l][j]);
			}
		}
	}
	while (q--) {
		int s, t, k; scanf("%d%d%d", &s, &t, &k);
		printf("%d\n", a[k][s][t]);
	}
	return 0;
}