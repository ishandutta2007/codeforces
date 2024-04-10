#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 100005, MAXLOG = 17, MAXQ = 100005;

int n, m, tp[MAXN], col[MAXN], tmp[MAXN], pre[MAXN][MAXLOG];
int dep[MAXN], fa[MAXN], g[MAXN], nxt[MAXN << 1], to[MAXN << 1], edgeSize;
int contain[MAXN], dfsClock, id[MAXN], bsize, bcnt[MAXN * 2];
LL cnt[MAXN][2], answer, ans[MAXQ];
struct Query{
	int u, v, oid;
	bool operator < (const Query &rhs) const{
		return bcnt[id[u]] == bcnt[id[rhs.u]] ? id[v] < id[rhs.v] : bcnt[id[u]] < bcnt[id[rhs.u]];
	}
}q[MAXQ];

void dfs(int x){
	int p; id[x] = ++ dfsClock;
	for(p = 1; (1 << p) < dep[x]; ++ p)
		pre[x][p] = pre[pre[x][p - 1]][p - 1];
	for(p = g[x]; p; p = nxt[p])
		if(to[p] != fa[x]){
			fa[to[p]] = pre[to[p]][0] = x;
			dep[to[p]] = dep[x] + 1;
			dfs(to[p]);
		}
	++ dfsClock;
}
void addEdge(int u, int v){
	nxt[++ edgeSize] = g[u];
	to[g[u] = edgeSize] = v;
}
inline int getLCA(int u, int v){
	int p;
	if(dep[u] > dep[v]) swap(u, v);
	for(p = 16; p >= 0; -- p)
		if(dep[v] - (1 << p) >= dep[u])
			v = pre[v][p];
	if(u == v) return u;
	for(p = 16; p >= 0; -- p)
		if(pre[u][p] != pre[v][p])
			u = pre[u][p], v = pre[v][p];
	return fa[u];
}
void reverse(int x){
	answer -= cnt[col[x]][0] * cnt[col[x]][1];
	if(contain[x]) -- cnt[col[x]][tp[x]];
	else ++ cnt[col[x]][tp[x]];
	answer += cnt[col[x]][0] * cnt[col[x]][1];
	contain[x] ^= 1;
}
void moveTo(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	for(; dep[u] < dep[v]; v = fa[v])
		reverse(v);
	for(; u != v; u = fa[u], v = fa[v])
		reverse(u), reverse(v);
}
int main(){
	int i, u, v, lca;
	scanf("%d", &n);
	bsize = int(sqrt(n * 2.0) + 1e-8);
	for(i = 1; i <= 2 * n; ++ i)
		bcnt[i] = (i - 1) / bsize + 1;
	for(i = 1; i <= n; ++ i)
		scanf("%d", &tp[i]);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &col[i]);
		tmp[i] = col[i];
	} sort(tmp + 1, tmp + 1 + n);
	for(i = 1; i <= n; ++ i)
		col[i] = lower_bound(tmp + 1, tmp + 1 + n, col[i]) - tmp;
	for(i = 1; i < n; ++ i){
		scanf("%d%d", &u, &v);
		addEdge(u, v), addEdge(v, u);
	} dep[1] = 1, dfs(1);
	scanf("%d", &m);
	for(i = 1; i <= m; ++ i){
		scanf("%d%d", &q[i].u, &q[i].v);
		if(id[q[i].u] > id[q[i].v])
			swap(q[i].u, q[i].v);
		q[i].oid = i;
	} sort(q + 1, q + 1 + m);
	for(i = u = v = 1; i <= m; ++ i){
		moveTo(u, q[i].u), u = q[i].u;
		moveTo(v, q[i].v), v = q[i].v;
		lca = getLCA(u, v);
		reverse(lca);
		ans[q[i].oid] = answer;
		reverse(lca);
	}
	for(i = 1; i <= m; ++ i)
		printf("%I64d\n", ans[i]);
	return 0;
}