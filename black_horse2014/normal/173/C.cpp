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

const int MAXN = 555;

int a[MAXN][MAXN], s[MAXN][MAXN];
int f[MAXN];

int main() {
	
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];
		}
	}
	int ans = -2e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[0] = a[i][j];
			int L = min(min(i-1, j-1), min(n-i, m-j));
			for (int k = 1; k <= L; k++) {
				f[k] = s[i+k][j+k] - s[i+k][j-k-1] - s[i-k-1][j+k] + s[i-k-1][j-k-1] - f[k-1] - a[i-k+1][j-k];
				chkmax(ans, f[k]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}