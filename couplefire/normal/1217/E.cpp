#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 200 * 1000 + 13;
const int INF = 2e9;
const int LOGN = 9;

struct node{
	int best;
	int mn[LOGN];
	node(){
		best = INF;
		forn(i, LOGN)
			mn[i] = INF;
	}
	int& operator [](int x){
		return mn[x];
	}
};

int a[N];
node t[4 * N];

void upd(node &t, int val){
	int x = val;
	forn(i, LOGN){
		if (x % 10 != 0)
			t[i] = min(t[i], val);
		x /= 10;
	}
}

node merge(node &a, node &b){
	node c;
	c.best = min(a.best, b.best);
	forn(i, LOGN){
		c[i] = min(a[i], b[i]);
		if (a[i] < INF && b[i] < INF)
			c.best = min(c.best, a[i] + b[i]);
	}
	return c;
}

void build(int v, int l, int r){
	if (l == r - 1){
		t[v] = node();
		upd(t[v], a[l]);
		return;
	}
	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m, r);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int l, int r, int pos, int val){
	if (l == r - 1){
		t[v] = node();
		upd(t[v], val);
		return;
	}
	int m = (l + r) / 2;
	if (pos < m)
		upd(v * 2, l, m, pos, val);
	else
		upd(v * 2 + 1, m, r, pos, val);
	t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int l, int r, int L, int R){
	if (l == L && r == R)
		return t[v];
	int m = (l + r) / 2;
	if (R <= m)
		return get(v * 2, l, m, L, R);
	if (L >= m)
		return get(v * 2 + 1, m, r, L, R);
	node ln = get(v * 2, l, m, L, m);
	node rn = get(v * 2 + 1, m, r, m, R);
	return merge(ln, rn);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	build(1, 0, n);
	forn(i, m){
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		--x;
		if (t == 1)
			upd(1, 0, n, x, y);
		else{
			node res = get(1, 0, n, x, y);
			printf("%d\n", res.best == INF ? -1 : res.best);
		}
	}
	return 0;
}