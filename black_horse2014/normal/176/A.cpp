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

const int INF = 1e9;
const int MAXN = 111;

int a[MAXN][MAXN], b[MAXN][MAXN], dp[MAXN], c[MAXN][MAXN];
char s[111];

int main() {
	
	int n, m, p; cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 1; j <= m; j++) {
			scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			for (int k = 1; k <= p; k++) dp[k] = -INF;
			dp[0] = 0;
			for (int k = 1; k <= m; k++) {
				for (int l = p; l >= 0; l--) {
					for (int x = c[i][k]; x >= 0; x--) {
						if (x + l <= p) {
							chkmax(dp[x + l], dp[l] + x * (b[j][k] - a[i][k]));
						}
					}
				}
			}
			for (int i = 0; i <= p; i++) chkmax(ans, dp[i]);
		}
	}
	cout << ans << endl;
	return 0;
}