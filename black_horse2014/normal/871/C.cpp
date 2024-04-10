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

const int MAXN = 2e5 + 5;

int x[MAXN], y[MAXN], a[MAXN], b[MAXN];
int cnt[MAXN], edge[MAXN], pw[MAXN];
int f[MAXN];

int find_set(int u) {
	return f[u] == u ? u : f[u] = find_set(f[u]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		x[i] = a[i], y[i] = b[i];
	}
	sort(x, x + n);
	sort(y, y + n);
	int r = unique(x, x + n) - x;
	int c = unique(y, y + n) - y;
	for (int i = 0; i < n; i++) a[i] = lower_bound(x, x + r, a[i]) - x;
	for (int i = 0; i < n; i++) b[i] = lower_bound(y, y + c, b[i]) - y + r;
	for (int i = 0; i < r + c; i++) f[i] = i;
	for (int i = 0; i < n; i++) {
		int u = find_set(a[i]), v = find_set(b[i]);
		if (u != v) f[u] = v;
	}
	for (int i = 0; i < r + c; i++) cnt[find_set(i)]++;
	for (int i = 0; i < n; i++) {
		int u = find_set(a[i]);
		edge[u]++;
	}
	int ans = 1, MOD = 1e9 + 7;
	for (int i = 0; i <= r + c; i++) pw[i] = (i == 0 ? 1 : pw[i-1] * 2 % MOD);
	for (int i = 0; i < r + c; i++) {
		if (cnt[i] <= edge[i]) ans = 1LL * pw[cnt[i]] * ans % MOD;
		else ans = 1LL * (pw[cnt[i]] + MOD - 1) * ans % MOD;
	}
	printf("%d\n", ans);
	return 0;
}