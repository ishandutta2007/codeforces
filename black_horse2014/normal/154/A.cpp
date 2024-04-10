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

const int MAXN = 111111;

char s[MAXN];
int dp[MAXN];
int last[33], con[33][33];

int main() {
	
	scanf("%s", s);
	int n = strlen(s);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char t[111]; scanf("%s", t);
		int u = t[0] - 'a', v = t[1] - 'a';
		con[u][v] = con[v][u] = 1;
	}
	for (int i = 0; i < 26; i++) last[i] = n;
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		int u = s[i] - 'a';
		for (int j = 0; j < 26; j++) {
			if (con[u][j]) continue;
			chkmax(dp[i], 1 + dp[last[j]]);
		}
		last[u] = i;
		chkmax(ans, dp[i]);
	}
	printf("%d\n", n-ans);
	return 0;
}