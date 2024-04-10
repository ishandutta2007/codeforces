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

const int MAXN = 2222222;

int seen[MAXN], dp[MAXN], a[MAXN], b[MAXN], x[MAXN];
int f[21][MAXN];

int main() {
	
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		x[a[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		b[i] = x[b[i]]; b[m + i] = b[i];
	}
	for (int i = 1; i <= n; i++) seen[i] = 2 * m + 1;
	for (int i = 0; i <= 20; i++) f[i][2 * m + 1] = 2 * m + 1;
	int ans = 0;
	for (int i = 2 * m; i > 0; i--) {
		if (!b[i]) continue;
		int j = seen[b[i] % n + 1];
		f[0][i] = j;
		for (int k = 1; k <= 20; k++) f[k][i] = f[k-1][f[k-1][i]];
		seen[b[i]] = i;
		int len = 0;
		for (int u = i, k = 20; k >= 0; k--) {
			if (f[k][u] > 2 * m || f[k][u] >= i + m) continue;
			len += bit(k), u = f[k][u];
		}
		chkmax(ans, len + 1);
	}
	cout << ans << endl;
	return 0;
}