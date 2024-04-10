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

const int MAXN = 222222;

int ans[MAXN], a[MAXN], b[MAXN];
VI adj[MAXN];

void dfs(int u, int c) {
	ans[u] = c;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (!ans[v]) dfs(v, 3-c);
	}
}

int main() {
	
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	for (int i = 1; i < 2*n; i += 2) adj[i].push_back(i+1), adj[i+1].push_back(i);
	for (int i = 1; i <= 2*n; i++) {
		if (!ans[i]) {
			dfs(i, 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d %d\n", ans[a[i]], ans[b[i]]);
	}
	return 0;
}