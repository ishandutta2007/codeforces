#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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
void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 1111;

int N, D, MOD;
int dp[12][MAXN];
int r[MAXN], C[MAXN];

int main() {
	
	cin >> N >> D >> MOD;
	r[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		r[i] = (LL)(MOD-r[MOD%i]) * (MOD/i) % MOD; 
	}
	if (D == 2) {
		puts("1");
		return 0;
	}
	int M = N/2;
	D--, dp[D][1] = dp[D+1][1] = 1;
	dp[0][1] = 1;
	for (int i = 1; i <= M; i++) {
		int cur = dp[D][i];
		C[0] = 1;
		for (int k = 1; k <= D+1; k++) C[k] = (LL)C[k-1] * (cur+k-1) % MOD * r[k] % MOD;
		for (int k = D+1; k > 0; k--) {
			for (int j = N; j > i; j--) {
				for (int l = k-1; l >= 0; l--) {
					if (j >= i*(k-l)) dp[k][j] = (dp[k][j] + (LL)dp[l][j-i*(k-l)] * C[k-l]) % MOD;
				}
			}
		}
	}
	int ans = dp[D+1][N];
	if (N + 1 & 1) ans = (ans + (LL)(MOD-dp[D][M])*(dp[D][M]-1) % MOD * r[2]) % MOD;
	cout << ans << endl;
	return 0;
}