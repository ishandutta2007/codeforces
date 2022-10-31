#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
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

bool dp[205][2048], a[205][2048], b[205][2048];
int sz[205];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char s[444]; scanf("%s", s);
		int L = strlen(s);
		a[i][1] = b[i][1] = dp[i][1] = 1, sz[i] = L;
		for (int j = 0; j < L; j++) {
			for (int cur = 1, k = 0; k < 10 && j + k < L; k++) {
				cur = cur * 2 + s[j + k] - '0', dp[i][cur] = 1;
				if (j == 0) a[i][cur] = 1;
				if (j + k == L-1) b[i][cur] = 1;
			}
		}
	}
	scanf("%d", &m);
	for (int i = n + 1; i <= n + m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		sz[i] = min(20, sz[u] + sz[v]);
		for (int j = 1; j < 2048; j++) dp[i][j] |= dp[u][j] | dp[v][j], a[i][j] |= a[u][j], b[i][j] |= b[v][j];
		for (int j = 1; j < 2048; j++) if (b[u][j]) {
			for (int k = 1; k < 2048; k++) if (a[v][k]) {
				int l = bit(31 - clzi(k)), cur = (j - 1) * l + k;
				if (cur >= 2048) break;
				dp[i][cur] = 1;
				if (sz[v] <= 10 && k >= bit(sz[v])) b[i][cur] = 1;
				if (sz[u] <= 10 && j >= bit(sz[u])) a[i][cur] = 1;
			}
		}
		int ans = 0;
		for (int j = 1; j <= 10; j++) {
			int flg = 1;
			for (int k = bit(j); flg && k < bit(j+1); k++) flg &= dp[i][k];
			if (flg) ans = j;
			else break;
		}
		cout << ans << endl;
	}
	return 0;
}