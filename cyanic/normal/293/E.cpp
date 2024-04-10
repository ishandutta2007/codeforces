#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define loop(k,a) for (int k=(a); k; k=e[k].link)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
 
const int maxn = 100005;
struct BIT {
	LL c[maxn]; int n;
	void add(int x, int y) { for (; x<=n; x+=lowbit(x)) c[x] += y; }
	LL query(int x) { if (x <= 0) return 0; LL res = 0; for (x=min(x,n); x; x-=lowbit(x)) res += c[x]; return res; }
} bit;
struct edge { int v, w, link; } e[maxn<<1];
int head[maxn], sz[maxn], vis[maxn], son[maxn];
int sum, size, n, root, L, W, p, w, cnt;
pii a[maxn]; LL ans;
 
inline void addEdge(int u, int v, int w) {
	e[++size].v = v; e[size].w = w; e[size].link = head[u]; head[u] = size;
	e[++size].v = u; e[size].w = w; e[size].link = head[v]; head[v] = size;
}
 
void dfs_size(int u, int fa) {
	sz[u] = 1; son[u] = 0;
	loop (k, head[u]) if (e[k].v != fa && !vis[e[k].v])
		dfs_size(e[k].v, u), sz[u] += sz[e[k].v], son[u] = sz[e[k].v] > sz[son[u]] ? e[k].v : son[u];
}
 
int dfs_root(int u, int fa) {
	int now = max(sz[son[u]], sum - sz[u]);
	if (2 * now <= sum) { root = u; return 1; }
	loop (k, head[u]) if (e[k].v != fa && !vis[e[k].v])
		if (dfs_root(e[k].v, u)) return 1;
	return 0;
}
 
void dfs_dist(int u, int fa, int dep, int weight) {
	a[++cnt] = make_pair(weight, dep);
	loop (k, head[u]) if (e[k].v != fa && !vis[e[k].v])
		dfs_dist(e[k].v, u, dep+1, weight + e[k].w > W ? W + 1 : weight + e[k].w);
}
 
LL calc(int u, int dep, int weight) {
	LL res = 0; cnt = 0; dfs_dist(u, 0, dep, weight); 
	int l = 0, r = cnt; sort(a+1, a+cnt+1); bit.n = cnt+1;
	while (r) {
		while (l+1 < r && a[l+1].first + a[r].first <= W) 
			bit.add(a[l+1].second+1, 1), l++;
		while (l >= r) bit.add(a[l].second+1, -1), l--;
		res += bit.query(L - a[r].second+1); r--;
	}
	while (l) bit.add(a[l].second+1, -1), l--;
	return res;
}
 
LL solve(int u) {
	dfs_size(u, 0); sum = sz[u]; dfs_root(u, 0); 
	LL ans = calc(root, 0, 0); vis[root] = 1;
	loop (k, head[root]) if (!vis[e[k].v]) 
		ans -= calc(e[k].v, 1, e[k].w), ans += solve(e[k].v);
	return ans;
}
 
int main() {
	scanf("%d%d%d", &n, &L, &W);
	rep (i, 2, n) scanf("%d%d", &p, &w), addEdge(p, i, w);
	printf("%I64d\n", solve(1));
	return 0;
}