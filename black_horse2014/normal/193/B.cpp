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

int n, u, r;
int a[33], b[33], c[33], p[33], d[33];

long long ans;

void dfs(int cur, int state, long long ret) {
	if (cur == u) {
		chkmax(ans, ret);
		return;
	}
	if (cur + u + 1 & 1) chkmax(ans, ret);
	int e[33];
	for (int i = 1; i <= n; i++) e[i] = d[i];
	long long nret = 0;
	for (int i = 1; i <= n; i++) d[i] = e[p[i]] + r, nret += 1LL * d[i] * c[i];
	dfs(cur + 1, state, nret);
	if (cur >= 1 && (state >> (cur-1) & 1)) return;
	nret = 0;
	for (int i = 1; i <= n; i++) d[i] = e[i] ^ b[i], nret += 1LL * d[i] * c[i];
	dfs(cur + 1, state | bit(cur), nret);
}

int main() {
	
	scanf("%d%d%d", &n, &u, &r);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	long long ret = 0;
	for (int i = 1; i <= n; i++) d[i] = a[i], ret += 1LL * a[i] * c[i];
	ans = -(1LL<<60);
	dfs(0, 0, ret);
	cout << ans << endl;
	return 0;
}