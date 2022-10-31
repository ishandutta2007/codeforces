#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int INF = 1e9 + 9;
const int maxn = 4e6 + 6;
struct node{ int l, r, mx, t; }tree[maxn];
void build(int rt, int l, int r){
	tree[rt].l = l, tree[rt].r = r;
	if (l == r)
		return;
	int m = l + r >> 1;
	build(rt << 1, l, m), build(rt << 1 | 1, m + 1, r);
}
void up(int rt){ tree[rt].mx = max(tree[rt << 1].mx, tree[rt << 1 | 1].mx); }
void upd(int rt, int d){ tree[rt].mx += d, tree[rt].t += d; }
void down(int rt){
	if (tree[rt].t) upd(rt << 1, tree[rt].t), upd(rt << 1 | 1, tree[rt].t), tree[rt].t = 0;
}
void add(int rt, int l, int r, int d){
	if (tree[rt].r < l || r < tree[rt].l)
		return;
	if (l <= tree[rt].l && tree[rt].r <= r){
		upd(rt, d);
		return;
	}
	down(rt);
	add(rt << 1, l, r, d), add(rt << 1 | 1, l, r, d);
	up(rt);
}
int query(int rt){
	if (tree[rt].l == tree[rt].r)
		return tree[rt].l;
	if (tree[rt].mx <= 0)
		return INF;
	down(rt);
	if (tree[rt << 1 | 1].mx > 0)
		return query(rt << 1 | 1);
	else
		return query(rt << 1);
}
int a[maxn], b[maxn];
long long read(){
	long long c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
	int n = read(), m = read();
	build(1, 1, 1e6);
	for (int i = 1; i <= n; ++ i){
		a[i] = read();
		add(1, 1, a[i], 1);
	}
	for (int i = 1; i <= m; ++ i){
		b[i] = read();
		add(1, 1, b[i], -1);
	}
	int q = read();
	while (q --){
		int t = read(), i = read(), x = read();
		if (t == 1){
			add(1, 1, a[i], -1);
			a[i] = x;
			add(1, 1, a[i], 1);
		}
		else{
			add(1, 1, b[i], 1);
			b[i] = x;
			add(1, 1, b[i], -1);
		}
		int ans = query(1);
		printf("%d\n", (ans == INF ? -1 : ans));
	}
}