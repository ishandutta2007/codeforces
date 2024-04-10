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

bitset<500> adj[63][2][501];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, t; scanf("%d%d%d", &u, &v, &t);
		u--, v--;
		adj[0][t][u].set(v);
	}
	for (int i = 1; i <= 60; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) if (adj[i-1][0][j][k]) adj[i][0][j] |= adj[i-1][1][k];
			for (int k = 0; k < n; k++) if (adj[i-1][1][j][k]) adj[i][1][j] |= adj[i-1][0][k];
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj[60][0][i].count() > 0) {
			puts("-1");
			return 0;
		}
	}
	bitset<500> ret, cur;
	for (int i = 0; i < n; i++) ret.set(i);
	long long ans = 0;
	int state = 0;
	for (int i = 59; i >= 0; i--) {
		cur.reset();
		for (int j = 0; j < n; j++) if (ret[j]) cur |= adj[i][state][j];
		if (cur.count() > 0) {
			ans += 1LL<<i;
			state ^= 1;
			ret = cur;
		}
	}
	if (ans >= 1000000000LL*1000000000LL) {
		puts("-1");
		return 0;
	}
	printf("%lld\n", ans);
	return 0;
}