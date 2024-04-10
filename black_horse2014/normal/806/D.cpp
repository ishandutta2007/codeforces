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

struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
	bool operator<(const Edge &rhs) const {
		return w < rhs.w;
	}
} E[2200000];

int dis[2200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	int m = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int x; scanf("%d", &x);
			E[m++] = Edge(i, j, x);
		}
	}
	sort(E, E + m);
	int cur = E[0].w;
	for (int i = 0; i < m; i++) E[i].w -= cur;
	long long ans = 1LL * cur * (n - 1);
	for (int i = 1; i <= n; i++) dis[i] = 1e9;
	for (int i = 0; i < m; i++) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		chkmin(dis[u], min(dis[v] + w, w + w));
		chkmin(dis[v], min(dis[u] + w, w + w));
	}
	for (int i = 1; i <= n; i++) printf("%lld\n", dis[i] + ans);
	return 0;
}