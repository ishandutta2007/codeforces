#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
const int INF = 2000000000;
struct node{
    pair <long long, int> p;
    long long s;
    int l, r;
}tree[maxn * 4];
int x[maxn], y[maxn], c[maxn], a[maxn];
vector <int> G[maxn];
void build(int rt, int l, int r){
	tree[rt].l = l, tree[rt].r = r, tree[rt].p.se = l;
	if (l == r)
		return;
	build(rt << 1, l, l + r >> 1);
	build(rt << 1 | 1, (l + r >> 1) + 1, r);
}
void add(int rt, int r, int x){
	if (tree[rt].l > r)
		return;
	if (tree[rt].r <= r){
		tree[rt].p.fi += x;
		tree[rt].s += x;
		return;
	}
	add(rt << 1, r, x);
	add(rt << 1 | 1, r, x);
	tree[rt].p = max(tree[rt << 1].p, tree[rt << 1 | 1].p);
	tree[rt].p.fi += tree[rt].s;
}
int main(){
	int n;
	cin >> n;
	int m = 0;
	for (int i = 1; i <= n; ++ i){
		scanf("%d %d %d", &x[i], &y[i], &c[i]);
		a[++ m] = x[i], a[++ m] = y[i];
	}
	sort(a + 1, a + 1 + m);
	m = unique(a + 1, a + 1 + m) - a - 1;
	for (int i = 1; i <= n; ++ i){
		x[i] = lower_bound(a + 1, a + 1 + m, x[i]) - a;
		y[i] = lower_bound(a + 1, a + 1 + m, y[i]) - a;
		G[max(x[i], y[i])].push_back(i);
	}
	a[0] = INF;
	int x0 = 0, y0 = 0;
	long long ans = 0;
	build(1, 1, m);
	for (int i = 1; i <= m; ++ i){
		for (int j = 0; j < G[i].size(); ++ j){
			int k = G[i][j];
			if (x[k] == i)
				add(1, y[k], c[k]);
			else
				add(1, x[k], c[k]);
		}
		add(1, i - 1, a[i - 1] - a[i]);
		if (tree[1].p.fi > ans)
			ans = tree[1].p.fi, x0 = tree[1].p.se, y0 = i;
	}
	cout << ans << endl;
	cout << a[x0] << " " << a[x0] << " " << a[y0] << " " << a[y0] << endl;
}
/*
10
10 0 -1
1 10 -4
3 6 3
4 2 -5
10 7 -1
3 7 3
3 7 -2
8 10 4
5 0 -1
2 3 3
*/