#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

const int MOD = 1e9 + 7;

struct Matrix {
	int dat[2][2];
	Matrix() {}
	Matrix(int id) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				dat[i][j] = ((i == j) ? id : 0);
			}
		}
	}
	friend Matrix inline operator *(const Matrix &a, const Matrix &b) {
		Matrix c(0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					c.dat[i][j] += 1LL * a.dat[i][k] * b.dat[k][j] % MOD;
					c.dat[i][j] %= MOD;
				}
			}
		}
		return c;
	}
	friend Matrix inline operator +(const Matrix &a, const Matrix &b) {
		Matrix c(0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.dat[i][j] = a.dat[i][j] + b.dat[i][j];
				c.dat[i][j] %= MOD;
			}
		}
		return c;
	}
	void show() {
		for (int i = 0; i < 2; i++, puts(""))
			for (int j = 0; j < 2; j++) {
				printf("%d ", dat[i][j]);
			}
		puts(" ");
	}
};

const int N = 1e5 + 5;

Matrix tree[N << 2];
Matrix lazy[N << 2];

int n, m, a[N];
Matrix fib, trans;

void prepare() {
	trans = Matrix(0);
	trans.dat[0][0] = trans.dat[0][1] = trans.dat[1][0] = 1;
	fib = Matrix(0);
	fib.dat[0][0] = 1;
	fib.dat[1][0] = 0;
}

Matrix power(Matrix trans, int n) {
	Matrix ret = Matrix(1);
	for (int i = 1; i <= n; i <<= 1) {
		if (n & i) {
			ret = ret * trans;
		}
		trans = trans * trans;
	}
	return ret;
}

void build(int x, int l, int r) {
	lazy[x] = Matrix(1);
	if (l == r) {
		tree[x] = power(trans, a[l] - 1) * fib;
	} else {
		int mid = (l + r) >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
		tree[x] = tree[x << 1] + tree[x << 1 | 1];
	}
}

void push(int x) {
	tree[x << 1] = lazy[x] * tree[x << 1];
	lazy[x << 1] = lazy[x] * lazy[x << 1];

	tree[x << 1 | 1] = lazy[x] * tree[x << 1 | 1];
	lazy[x << 1 | 1] = lazy[x] * lazy[x << 1 | 1];

	lazy[x] = Matrix(1);
}

void update(int x) {
	tree[x] = tree[x << 1] + tree[x << 1 | 1];
}

void modify(int x, int l, int r, int ql, int qr, const Matrix &trans) {
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		lazy[x] = trans * lazy[x];
		tree[x] = trans * tree[x];
	} else {
		push(x);
		int mid = (l + r) >> 1;
		modify(x << 1, l, mid, ql, qr, trans);
		modify(x << 1 | 1, mid + 1, r, ql, qr, trans);
		update(x);
	}
}

Matrix ask(int x, int l, int r, int ql, int qr) {
	if (qr < l || r < ql) return Matrix(0);
	if (ql <= l && r <= qr) return tree[x];
	push(x);
	int mid = (l + r) >> 1;
	Matrix ret = ask(x << 1, l, mid, ql, qr);
	ret = ret + ask(x << 1 | 1, mid + 1, r, ql, qr);
	update(x);
	return ret;
}

int main() {
	prepare();
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int t, l, r, x;
		scanf("%d %d %d", &t, &l, &r);
		if (t == 1) {
			scanf("%d", &x);
			modify(1, 1, n, l, r, power(trans, x));
		} else {
			printf("%d\n", ask(1, 1, n, l, r).dat[0][0]);
		}
	}
	return 0;
}