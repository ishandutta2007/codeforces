#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int MOD = 1e9 + 7;
const int pod = (1 << 17);

struct matrix {
	int t[2][2];
	matrix() {
		memset(t, 0, sizeof(t));
	}
	matrix operator *(matrix a) {
		matrix b = matrix();
		rep(k, 0, 1) rep(i, 0, 1) rep(j, 0, 1) 
			b.t[i][j] = (b.t[i][j] + (LL) t[i][k] * a.t[k][j]) % MOD;
		return b;
	}
	matrix operator +(matrix a) {
		matrix b = matrix();
		rep(i, 0, 1) rep(j, 0, 1)
			b.t[i][j] = (t[i][j] + a.t[i][j]) % MOD;
		return b;
	}
};

matrix pot(matrix a, int k) {
	matrix b = matrix();
	rep(i, 0, 1) b.t[i][i] = 1;
	while (k) {
		if (k & 1) b = b * a;
		a = a * a;
		k /= 2;
	}
	return b;
}

matrix sum[2 * pod], lazy[2 * pod];

void of(int v) {
	lazy[v] = matrix();
	rep(i, 0, 1) lazy[v].t[i][i] = 1;
}

void push(int v) {
	for (auto u : {2 * v, 2 * v + 1}) {
		lazy[u] = lazy[u] * lazy[v];
		sum[u] = sum[u] * lazy[v];
	}
	of(v);
}

void add(int x, int y, matrix &z, int v = 1, int l = 0, int r = pod - 1) {
	if (x <= l && r <= y) {
		sum[v] = sum[v] * z;
		lazy[v] = lazy[v] * z;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	if (x <= m) add(x, y, z, 2 * v, l, m);
	if (m < y) add(x, y, z, 2 * v + 1, m + 1, r);
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

matrix query(int x, int y, int v = 1, int l = 0, int r = pod - 1) {
	if (x <= l && r <= y) return sum[v];
	push(v);
	int m = (l + r) / 2;
	matrix res = matrix();
	if (x <= m) res = res + query(x, y, 2 * v, l, m);
	if (m < y) res = res + query(x, y, 2 * v + 1, m + 1, r);
	return res;
}

int n, q, a, b, c, d;

int main() {	
	rep(i, 1, 2 * pod - 1) {
		sum[i] = matrix();
		lazy[i] = matrix();
	}
	matrix fib;
	fib.t[0][0] = 0;
	fib.t[0][1] = 1;
	fib.t[1][0] = 1;
	fib.t[1][1] = 1;
	
	matrix p = matrix();
	p.t[0][0] = 1;
	p.t[0][1] = 1;
	
	scanf ("%d%d", &n, &q);
	rep(i, 1, n) {
		scanf ("%d", &a);
		sum[i + pod] = p * pot(fib, a - 1);
	}
	per(i, 1, pod - 1) {
		sum[i] = sum[2 * i] + sum[2 * i + 1];
		of(i);
	}
	while (q--) {
		scanf ("%d%d%d", &a, &b, &c);
		if (a == 1) {
			scanf ("%d", &d);
			matrix x = pot(fib, d);
			add(b, c, x);
		}
		else printf ("%d\n", query(b, c).t[0][0]);
	}
		
		
	
	
	return 0;
}