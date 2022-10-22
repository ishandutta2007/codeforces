#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair
 
using ll = long long;
using namespace std;	

const int N = 1 << 18;

int n, f[31], sz[N], fa[N], x;
set<int> g[N];

void dfs(int v, int p, int k) {
	sz[v] = 1;
	for (auto u : g[v])
		if (u != p) {
			fa[u] = v;
			dfs(u, v, k);
			sz[v] += sz[u];
		}
	if (sz[v] == f[k - 1] || sz[v] == f[k - 2]) x = v;
}	

bool solve(int v, int k) {
	if (f[k] == 1) return 1;
	x = -1;
	dfs(v, 0, k);
	if (x == -1) return 0;
	int y = fa[x];
	g[x].erase(y);
	g[y].erase(x);
	if (sz[x] == f[k - 1]) return solve(x, k - 1) && solve(y, k - 2);
	return solve(x, k - 2) && solve(y, k - 1);
}

int main() {
	scanf("%d", &n);
	rep(i, 2, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].insert(b);
		g[b].insert(a);
	}
	f[0] = f[1] = 1;
	rep(i, 2, 30) f[i] = f[i - 1] + f[i - 2];
	int k = 0;
	while (f[k] < n) k++;
	puts(f[k] == n && solve(1, k) ? "Yes" : "No");
	return 0;
}