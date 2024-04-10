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

const int MAXN = 155;

char s[MAXN];
int a[MAXN];
int dp[MAXN][MAXN], f[MAXN][MAXN][MAXN], g[MAXN][MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%s", s+1);
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++) f[i][i][0] = g[i][i] = 0;
	for (int i = 1; i <= n; i++) f[i][i+1][0] = a[1], f[i][i+1][1] = 0, g[i][i+1] = a[1], chkmax(dp[i][i+1], a[1]);
	for (int l = 2; l <= n; l++) {
		for (int st = 1, en = l; st <= n-l+1; en++, st++) {
			for (int mid = st+1; mid <= en; mid++) {
				if (s[st] == s[mid] && ~g[mid+1][en+1]) {
					for (int k = 0; k <= mid-st-1; k++) {
						if (~f[st+1][mid][k]) {
							chkmax(f[st][en+1][k+2], f[st+1][mid][k] + g[mid+1][en+1]);
						}
					}
				}
			}
			for (int mid = st; mid <= en-1; mid++) if (~g[mid+1][en+1]) {
				for (int k = 0; k <= mid-st+1; k++) {
					if (~f[st][mid+1][k]) chkmax(f[st][en+1][k], g[mid+1][en+1] + f[st][mid+1][k]);
				}
			}
			for (int mid = en-1; mid >= st; mid--) if (~g[st][mid]) {
				for (int k = 0; k <= en-mid+1; k++) {
					if (~f[mid][en+1][k]) chkmax(f[st][en+1][k], g[st][mid] + f[mid][en+1][k]);
				}
			}
			if (~g[st+1][en+1]) {
				chkmax(f[st][en+1][1], g[st+1][en+1]);
			}
			for (int mid = en-1; mid >= st; mid--) {
				if (s[mid] == s[en] && ~g[st][mid]) {
					for (int k = 0; k <= en-mid-1; k++) {
						if (~f[mid+1][en][k]) {
							chkmax(f[st][en+1][k+2], f[mid+1][en][k] + g[st][mid]);
						}
					}
				}
			}
			if (~g[st][en]) {
				chkmax(f[st][en+1][1], g[st][en]);
			}
			for (int j = 1; j <= l; j++) {
				if (~a[j] && ~f[st][en+1][j]) chkmax(g[st][en+1], f[st][en+1][j] + a[j]);
			}
			f[st][en+1][0] = g[st][en+1];
			chkmax(dp[st][en+1], dp[st+1][en+1]);
			chkmax(dp[st][en+1], dp[st][en]);
			chkmax(dp[st][en+1], g[st][en+1]);
			for (int mid = st; mid <= en; mid++) {
				chkmax(dp[st][en+1], dp[st][mid+1]+dp[mid+1][en+1]);
				chkmax(dp[st][en+1], dp[st][mid]+dp[mid][en+1]);
				if (s[st] == s[mid] && ~g[st][mid+1]) {
					chkmax(dp[st][en+1], g[st][mid+1] + dp[mid+1][en+1]);
				}
				if (s[mid] == s[en] && ~g[mid][en+1]) {
					chkmax(dp[st][en+1], g[mid][en+1] + dp[st][mid]);
				}
			}
		}
	}
	cout << dp[1][n+1] << endl;
	return 0;
}