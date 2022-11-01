#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

const int N = 3e5 + 7;

struct Node {
	long long lv, rv, lazy;
	int ans, lup, ldown, rup, rdown, ansl, ansr, size;
	void init(int v) {
		lv = rv = v;
		lazy = 0;
		ans = lup = ldown = rup = rdown = ansl = ansr = size = 1;
	}
	void add(long long d) {
		lv += d, rv += d, lazy += d;
	}
};

Node tree[N << 2];
int n, a[N];

void update(int x, int lc, int rc) {
	tree[x].size = tree[lc].size + tree[rc].size;
	tree[x].lv = tree[lc].lv;
	tree[x].rv = tree[rc].rv;

	long long delta = tree[lc].rv - tree[rc].lv;
	tree[x].ans = max(tree[lc].ans, tree[rc].ans);
	tree[x].ansl = tree[lc].ansl;
	tree[x].lup = tree[lc].lup;
	tree[x].ldown = tree[lc].ldown;
	tree[x].ansr = tree[rc].ansr;
	tree[x].rup = tree[rc].rup;
	tree[x].rdown = tree[rc].rdown;
	if (delta > 0) {
		if (tree[x].ansl == tree[lc].size) {
			tree[x].ansl += tree[rc].lup;
		}
		if (tree[rc].rdown == tree[rc].size) {
			tree[x].ansr = tree[lc].ansr + tree[rc].rdown;
		}
		tree[x].ans = max(tree[x].ans, tree[lc].ansr + tree[rc].lup);
		if (tree[x].lup == tree[lc].size) {
			tree[x].lup += tree[rc].lup;
		}
		if (tree[x].rdown == tree[rc].size) {
			tree[x].rdown += tree[lc].rdown;
		}
	} else if (delta < 0) {
		if (tree[x].ansr == tree[rc].size) {
			tree[x].ansr += tree[lc].rup;
		}
		if (tree[lc].ldown == tree[lc].size) {
			tree[x].ansl = tree[lc].ldown + tree[rc].ansl;
		}
		tree[x].ans = max(tree[x].ans, tree[lc].rup + tree[rc].ansl);
		if (tree[x].rup == tree[rc].size) {
			tree[x].rup += tree[lc].rup;
		}
		if (tree[x].ldown == tree[lc].size) {
			tree[x].ldown += tree[rc].ldown;
		}
	}
}

void build(int x, int l, int r) {
	if (l == r) {
		tree[x].init(a[l]);
	} else {
		int mid = (l + r) >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		update(x, x << 1, x << 1 | 1);
	}
}

void insert(int x, int l, int r, int ql, int qr, int d) {
	if (r < ql || qr < l) return ;
	if (ql <= l && r <= qr) {
		tree[x].add(d);
	} else {
		tree[x << 1].add(tree[x].lazy);
		tree[x << 1 | 1].add(tree[x].lazy);
		tree[x].lazy = 0;
		int mid = (l + r) >> 1;
		insert(x << 1, l, mid, ql, qr, d);
		insert(x << 1 | 1, mid + 1, r, ql, qr, d);
		update(x, x << 1, x << 1 | 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);
		insert(1, 1, n, l, r, d);
		printf("%d\n", tree[1].ans);
	}
}