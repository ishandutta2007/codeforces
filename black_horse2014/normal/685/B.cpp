#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

const int MAXN = 333333;

vector<int> adj[MAXN];
int ans[MAXN], sz[MAXN], f[MAXN];

void dfs(int u) {
	sz[u] = 1, ans[u] = u;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		dfs(v), sz[u] += sz[v];
	}
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (sz[v] > sz[u] / 2) {
			ans[u] = ans[v];
			break;
		}
	}
	while (1) {
		if (sz[ans[u]] * 2 >= sz[u]) {
			return;
		}
		ans[u] = f[ans[u]];
	}
}

int main() {
	int n, q; cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &f[i]);
		adj[f[i]].push_back(i);
	}
	dfs(1);
	while (q--) {
		int u; scanf("%d", &u); printf("%d\n", ans[u]);
	}
	return 0;
}