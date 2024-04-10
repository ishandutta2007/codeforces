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

const int MAXN = 2222;

char s[MAXN], t[MAXN];
int dp[MAXN][MAXN];

int main() {
	
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	int ans = m;
	for (int i = 0; i < m; i++) dp[n][i] = m-i;
	for (int i = n-1; i >= 0; i--) {
		for (int j = m-1; j >= 0; j--) {
			dp[i][j] = dp[i+1][j+1] + (s[i] != t[j]);
			chkmin(ans, dp[i][j] + j);
		}
	}
	cout << ans << endl;
	return 0;
}