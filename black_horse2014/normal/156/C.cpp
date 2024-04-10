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

const int MOD = 1e9+7;
const int MAXN = 111;

int dp[MAXN][MAXN*26];

int main() {
	
	int ncase;
	dp[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j <= i*25; j++) {
			for (int k = 0; k < 26 && k <= j; k++) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
			}
		}
	}
	for (scanf("%d", &ncase); ncase--; ) {
		char t[155]; scanf("%s", t);
		int sum = 0, len = strlen(t);
		for (int i = 0; i < len; i++) sum += t[i] - 'a';
		printf("%d\n", (dp[len][sum]+MOD-1)%MOD);
	}
	return 0;
}