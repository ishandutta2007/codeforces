#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define mid ((l + r) >> 1)
#define lc (o << 1)
#define rc (o << 1 | 1)
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
 
const int maxn = 200005;
int fa[maxn][20], up[maxn][20], low[maxn][20];
int dep[maxn], in[maxn], out[maxn];
int n, m, Q, a, b, c, p, L, R, clk;
vector<int> T[maxn<<2];
vector<int> e[maxn];
 
void update(int o, int l, int r, int x, int y) {
	T[o].push_back(y);
	if (l == r) return;
	if (x <= mid) update(lc, l, mid, x, y);
	else update(rc, mid+1, r, x, y);
}
 
vector<int>::iterator it;
int query(int o, int l, int r, int x, int y, int low, int high) {
	if (l == x && y == r) {
		it = lower_bound(T[o].begin(), T[o].end(), low);
		return it != T[o].end() && *it <= high;
	}
	if (y <= mid) return query(lc, l, mid, x, y, low, high);
	if (mid < x) return query(rc, mid+1, r, x, y, low, high);
	if (query(lc, l, mid, x, mid, low, high)) return 1;
	return query(rc, mid+1, r, mid+1, y, low, high);
}
 
void modify(int &a, int b) {
	if (dep[b] < dep[a]) a = b;
}
 
void dfs1(int u) {
	in[u] = ++clk;
	for (auto v : e[u]) {
		dep[v] = dep[u] + 1;
		dfs1(v);
	}
	out[u] = clk;
}
 
void dfs2(int u) {
	for (auto v : e[u]) {
		dfs2(v);
		modify(up[u][0], up[v][0]);
	}
}
 
inline int getlca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	per (j, 17, 0)
		if (dep[fa[a][j]] >= dep[b])
			a = fa[a][j];
	if (a == b) return a;
	per (j, 17, 0)
		if (fa[a][j] != fa[b][j]) 
			a = fa[a][j], b = fa[b][j];
	return fa[a][0];
}
 
inline int calc(int a, int b) {
	int res = 0;
	per (j, 17, 0)
		if (dep[low[a][j]] > b) {
			a = up[a][j];
			res |= (1 << j);
		}
	if (dep[a] > b) return -1;
	return res;
}
 
inline int getnode(int a, int b) {
	per (j, 17, 0) if (b>>j&1) 
		a = up[a][j];
	return a;
}
 
int main() {
	scanf("%d", &n);
	rep (i, 2, n) {
		scanf("%d", &p);
		e[p].push_back(i);
		fa[i][0] = p;
	}
	fa[1][0] = 1; dep[0] = 1e9;
	dep[1] = 1; dfs1(1);
	rep (i, 1, n) rep (j, 1, 17)
		fa[i][j] = fa[fa[i][j-1]][j-1];
	scanf("%d", &m);
	rep (i, 1, n) up[i][0] = i;
	while (m--) {
		scanf("%d%d", &a, &b); c = getlca(a, b);
		update(1, 1, n, min(in[a], in[b]), max(in[a], in[b]));
		if (c == b) swap(a, b);
		if (c == a) modify(up[b][0], c);
		else {
			modify(up[a][0], c);
			modify(up[b][0], c);
		}
	}
	rep (i, 1, n*4)
		if (T[i].size()) sort(T[i].begin(), T[i].end());
	dfs2(1);
	rep (i, 1, n) {
		rep (j, 1, 19)
			up[i][j] = up[up[i][j-1]][j-1];
		low[i][0] = i; low[i][1] = up[i][0];
		rep (j, 2, 19)
			low[i][j] = up[low[i][j-1]][j-1];
	}
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &a, &b);
		c = getlca(a, b);
		if (c == b) swap(a, b);
		if (c == a) printf("%d\n", calc(b, dep[c]));
		else {
			L = calc(a, dep[c]);
			R = calc(b, dep[c]);
			if (L == -1 || R == -1) {
				puts("-1"); continue;
			}
			a = getnode(a, L - 1);
			b = getnode(b, R - 1);
			if (in[a] > in[b]) swap(a, b);
			if (query(1, 1, n, in[a], out[a], in[b], out[b])) printf("%d\n", L + R - 1);
			else printf("%d\n", L + R);
		}
	}
	return 0;
}