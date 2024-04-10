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
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

int dp[555][555];

int main() {
	
	int n, m; cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		for (int j = m; j >= 0; j--) {
			for (int k = m-j; k >= 0; k--) {
				if (j >= x && dp[j-x][k]) {
					dp[j][k] = 1;
				}
				if (k >= x && dp[j][k-x]) {
					dp[j][k] = 1;
				}
			}
		}
	}
	vector<int> ret;
	for (int j = 0; j <= m; j++) {
		if (dp[j][m-j]) {
			ret.push_back(j);
		}
	}
	cout << ret.size() << endl;
	for (int i = 0; i < sz(ret); i++) {
		printf("%d%c", ret[i], i < sz(ret)-1 ? ' ' : '\n');
	}
	return 0;
}