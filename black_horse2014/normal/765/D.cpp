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

int f[111111], g[111111], h[111111], vis[111111];
VI adj[111111];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]);
		adj[f[i]].push_back(i);
		vis[f[i]] = 1;
	}
	int m = 0, m1 = 0;
	for (int i = 1; i <= n; i++) if (vis[i] == 1) m++;
	for (int i = 1; i <= n; i++) if (f[i] == i) m1++;
	if (m != m1) {
		puts("-1");
		return 0;
	}
	for (int i = 1, j = 1; i <= m; i++) {
		while (!vis[j]) j++;
		h[i] = j, g[j] = i;
		for (int k = 0; k < sz(adj[j]); k++) g[adj[j][k]] = i;
		j++;
	}
	cout << m << endl;
	for (int i = 1; i <= n; i++) printf("%d ", g[i]);
	puts("");
	for (int i = 1; i <= m; i++) printf("%d ", h[i]);
	puts("");
	return 0;
}