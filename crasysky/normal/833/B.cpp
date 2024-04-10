#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;
const int INF = 1e9;
int a[maxn], pre[maxn], last[maxn], f[maxn];
struct node{ int l, r, mx, tag; }tree[maxn];
void up(int rt){ 
	tree[rt].mx = max(tree[rt << 1].mx, tree[rt << 1 | 1].mx) + tree[rt].tag; 
}
void upd(int rt, int x){ tree[rt].mx += x, tree[rt].tag += x; }
void down(int rt){
	if (tree[rt].tag){ 
		upd(rt << 1, tree[rt].tag), upd(rt << 1 | 1, tree[rt].tag);
		tree[rt].tag = 0;
	}
}
void build(int rt, int l, int r){
	tree[rt].l = l, tree[rt].r = r, tree[rt].tag = 0;
	if (l == r){
		tree[rt].mx = f[l - 1];
		return;
	}
	build(rt << 1, l, l + r >> 1);
	build(rt << 1 | 1, (l + r >> 1) + 1, r);
	up(rt);
}
void add(int rt, int l, int r, int y){
	if (tree[rt].r < l || r < tree[rt].l) return;
	if (l <= tree[rt].l && tree[rt].r <= r){ upd(rt, y); return; }
	down(rt);
	add(rt << 1, l, r, y), add(rt << 1 | 1, l, r, y);
	up(rt);
}
int query(int rt, int l, int r){
	if (tree[rt].r < l || r < tree[rt].l) return -INF;
	if (l <= tree[rt].l && tree[rt].r <= r) return tree[rt].mx;
	down(rt);
	return max(query(rt << 1, l, r), query(rt << 1 | 1, l, r));
}
int read(){
	int c = 0; char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c;
}
int main(){
	int n = read(), k = read();
	for (int i = 1; i <= n; ++ i) a[i] = read();
	for (int i = 1; i <= n; ++ i)
		pre[i] = last[a[i]], last[a[i]] = i;
	for (int j = 1; j <= k; ++ j){
		build(1, 1, n);
		for (int i = 1; i <= n; ++ i){
			if (pre[i])
				add(1, pre[i], pre[i], -INF);
			add(1, pre[i] + 1, i, 1);
			f[i] = query(1, 1, i);
		}
	}
	cout << f[n] << endl;
}