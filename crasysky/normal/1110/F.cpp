#include <iostream>
#include <vector>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
#define maxn 500005
#define INF 1LL << 60
using namespace std;
vector < pair <int, int> > G[maxn];
vector < pair < pair <int, int>, int > > Q[maxn];
int n, sze[maxn];
long long ans[maxn];
long long dis[maxn];
void dfs(int u, long long d){
	sze[u] = 1;
	if (G[u].size())
		for (int i = 0; i < G[u].size(); ++ i){
			dfs(G[u][i].fi, d + G[u][i].se);
			sze[u] += sze[G[u][i].fi];
		}
	else
		dis[u] = d;
}
struct node{
	int l, r;
	long long mn, tag;
}tree[maxn * 4];
void pushup(int rt){
	tree[rt].mn = min(tree[rt << 1].mn, tree[rt << 1 | 1].mn);
}
void build(int rt, int l, int r){
	tree[rt].l = l, tree[rt].r = r;
	if (l == r){
		tree[rt].mn = dis[l] ? dis[l] : INF;
		return;
	}
	build(rt << 1, l, l + r >> 1);
	build(rt << 1 | 1, (l + r >> 1) + 1, r);
	pushup(rt);
}
void pushdown(int rt){
	if (tree[rt].tag){
		tree[rt << 1].mn += tree[rt].tag;
		tree[rt << 1 | 1].mn += tree[rt].tag;
		tree[rt << 1].tag += tree[rt].tag;
		tree[rt << 1 | 1].tag += tree[rt].tag;
		tree[rt].tag = 0;
	}
}
void add(int rt, int l, int r, long long x){
	if (tree[rt].r < l || r < tree[rt].l)
		return;
	if (l <= tree[rt].l && tree[rt].r <= r){
		tree[rt].mn += x;
		tree[rt].tag += x;
		return;
	}
	pushdown(rt);
	add(rt << 1, l, r, x);
	add(rt << 1 | 1, l, r, x);
	pushup(rt);
}
long long query(int rt, int l, int r){
	if (tree[rt].r < l || r < tree[rt].l)
		return INF;
	if (l <= tree[rt].l && tree[rt].r <= r)
		return tree[rt].mn;
	pushdown(rt);
	return min(query(rt << 1, l, r), query(rt << 1 | 1, l, r));
}
void solve(int u){
	for (int i = 0; i < Q[u].size(); ++ i)
		ans[Q[u][i].se] = query(1, Q[u][i].fi.fi, Q[u][i].fi.se);
	for (int i = 0; i < G[u].size(); ++ i){
		int v = G[u][i].fi;
		add(1, 1, n, G[u][i].se);
		add(1, v, v + sze[v] - 1, -2 * G[u][i].se);
		solve(v);
		add(1, 1, n, -G[u][i].se);
		add(1, v, v + sze[v] - 1, 2 * G[u][i].se);
	}
}
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	n = read();
	int q = read();
	for (int i = 2; i <= n; ++ i){
		int f = read(), p = read();
		G[f].push_back(mp(i, p));
	}
	dfs(1, 0);
	build(1, 1, n);
	for (int i = 1; i <= q; ++ i){
		int v = read(), l = read(), r = read();
		Q[v].push_back(mp(mp(l, r), i));
	}
	solve(1);
	for (int i = 1; i <= q; ++ i)
		printf("%lld\n", ans[i]);
}