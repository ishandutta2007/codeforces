#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
const int C = 10;

int n, q, a[N];
struct Node {
	int p[C];
	long long para[C];
	void init() {
		for (int i = 0; i < C; i++) p[i] = i, para[i] = 0;
	}
	void modify(int to[C]) {
		static long long tmp[C];
		for (int i = 0; i < C; i++) tmp[i] = para[i], para[i] = 0;
		for (int i = 0; i < C; i++) {
			para[to[i]] += tmp[i];
		}
		for (int i = 0; i < C; i++) tmp[i] = p[i];
		for (int i = 0; i < C; i++) {
			p[i] = to[tmp[i]];
		}
	}
	long long calc() {
		long long ret = 0;
		for (int i = 0; i < C; i++) {
			ret += para[i] * i;
		}
		return ret;
	}
}tree[N << 2];

void update(int x) {
	for (int i = 0; i < C; i++) {
		tree[x].para[i] = tree[x << 1].para[i] + tree[x << 1 | 1].para[i];
	}
}

void build(int x, int l, int r) {
	tree[x].init();
	if (l == r) {
		int v = a[l];
		long long ten = 1;
		while (v) {
			tree[x].para[v % 10] += ten;
			v /= 10;
			ten *= 10;
		}
		return ;
	}
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	update(x);
}

int trans[C];

void push(int x) {
	tree[x << 1].modify(tree[x].p);
	tree[x << 1 | 1].modify(tree[x].p);
	for (int i = 0; i < C; i++) {
		tree[x].p[i] = i;
	}
}

void modify(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		tree[x].modify(trans);
		return ;
	}
	if (qr < l || r < ql) return ;
	push(x);
	int mid = (l + r) / 2;
	modify(x << 1, l, mid, ql, qr);
	modify(x << 1 | 1, mid + 1, r, ql, qr);
	update(x);
}

long long ask(int x, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return tree[x].calc();
	if (qr < l || r < ql) return 0;
	push(x);
	int mid = (l + r) / 2;
	long long ret = ask(x << 1, l, mid, ql, qr);
	ret += ask(x << 1 | 1, mid + 1, r, ql, qr);
	update(x);
	return ret;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (int i = 0; i < q; i++) {
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if (type == 1) {
			int x, y;
			scanf("%d %d", &x, &y);
			for (int j = 0; j < C; j++) trans[j] = j;
			trans[x] = y;
			modify(1, 1, n, l, r);
		} else {
			printf("%lld\n", ask(1, 1, n, l, r));
		}
	}
}