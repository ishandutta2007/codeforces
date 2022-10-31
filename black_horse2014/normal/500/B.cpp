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

VI V, adj[333];
int a[333], vis[333];

void dfs(int u) {
	vis[u] = 1;
	V.push_back(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		char s[333]; scanf("%s", s);
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') adj[i].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			V.clear();
			dfs(i);
			sort(all(V));
			for (int j = 0; j < sz(V); j++) {
				for (int k = j+1; k < sz(V); k++) {
					if (a[V[j]] > a[V[k]]) swap(a[V[j]], a[V[k]]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}