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

const int MAXN = 222222;

int col[MAXN];
VI ans[2], adj[MAXN];
vector<int> V;

bool dfs(int u, int c) {
	col[u] = c;
	V.push_back(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (!~col[v]) {
			if (!dfs(v, c^1)) {
				return 0;
			}
		} else {
			if (col[v] == col[u]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	
	int n, m;cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(col, -1, sizeof col);
	for (int i = 1; i <= n; i++) {
		if (!~col[i]) {
			V.clear();
			if (!dfs(i, 0)) {
				puts("-1");
				return 0;
			}
			for (int j = 0; j < sz(V); j++) {
				ans[col[V[j]]].push_back(V[j]);
			}
		}
	}
	for (int j = 0; j < 2; j++) {
		cout << ans[j].size() << endl;
		for (int i = 0; i < sz(ans[j]); i++) {
			printf("%d%c", ans[j][i], i < sz(ans[j])-1 ? ' ' : '\n');
		}
	}
	return 0;
}