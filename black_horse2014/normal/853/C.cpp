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

int n;

const int MAXN = 220000;

int dp[MAXN], a[MAXN], L[MAXN], R[MAXN];
long long ans[MAXN];

VI V[2][MAXN];

void add(int u) {
	for (; u <= n; u += u & -u) dp[u]++;
}

int get(int u) {
	int ret = 0;
	for (; u; u -= u & -u) ret += dp[u];
	return ret;
}

inline long long C(long long x) {
	return x * (x - 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++) {
		int l, d, r, u; scanf("%d%d%d%d", &l, &d, &r, &u);
		ans[i] = C(n) - C(l - 1) - C(n - r) - C(d - 1) - C(n - u);
		L[i] = d - 1, R[i] = u;
		if (l > 1) V[0][l - 1].push_back(i);
		if (r < n) V[1][n - r].push_back(i);
	}
	for (int t = 0; t < 2; t++) {
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) {
			add(a[i]);
			for (int j = 0; j < sz(V[t][i]); j++) {
				int k = V[t][i][j];
				ans[k] += C(get(L[k])) + C(i - get(R[k]));
			}
		}
		reverse(a + 1, a + n + 1);
	}
	for (int i = 1; i <= q; i++) printf("%lld\n", ans[i]);
	return 0;
}