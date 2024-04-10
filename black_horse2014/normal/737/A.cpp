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

int n, k, s, t;

int g[222222], a[222222], b[222222];

bool can(int x) {
	long long ret = 0;
	for (int i = 0; i <= k; i++) {
		long long d = g[i + 1] - g[i], y, z;
		if (d <= x) {
			y = x - d, z = 2 * (d - y);
			if (z < 0) y = d, z = 0;
			ret += y + z;
		}
		else return 0;
	}
	return ret <= t;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
	g[0] = 0, g[k + 1] = s;
	for (int i = 1; i <= k; i++) scanf("%d", &g[i]);
	sort(g + 1, g + k + 2);
	int lo = 0, hi = 1e9+7;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	int ans = 1e9 + 7;
	for (int i = 0; i < n; i++) if (b[i] >= hi) chkmin(ans, a[i]);
	if (ans > 1e9 + 5) puts("-1");
	else cout << ans << endl;
	return 0;
}