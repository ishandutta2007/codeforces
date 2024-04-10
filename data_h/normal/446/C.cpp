#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 333333, MOD = (int)(1e9 + 9);

int a[N];
int n, m;

struct Matrix {
	int dat[3][3];
	void clear() {
		memset(dat, 0, sizeof(dat));
	}
	void setOne() {
		clear();
		for(int i = 0; i < 3; i++) {
			dat[i][i] = 1;
		}
	}
	friend Matrix operator *(const Matrix &a, const Matrix &b) {
		Matrix c;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++) {
				c.dat[i][j] = 0;
				for(int k = 0; k < 3; k++) {
					(c.dat[i][j] += 1LL * a.dat[i][k] * b.dat[k][j] % MOD) %= MOD;
				}
			}
		return c;
	}
};

Matrix base[N], trans;
int sum[N << 2], ta[N << 2], tb[N << 2];

void build(int x, int l, int r) {
	ta[x] = tb[x] = 0;
	if (l == r) {
		sum[x] = a[l] % MOD;
		return ;
	}
	int mid = (l + r) / 2;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % MOD;
}

void update(int x) {
	sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % MOD;
}


void add(int x, int a, int b, int span) {
	(ta[x] += a) %= MOD;
	(tb[x] += b) %= MOD;
	(sum[x] += 
		(1LL * b * base[span].dat[2][0] + 
		 1LL * a * base[span].dat[2][1] + 
		 1LL * a * base[span].dat[2][2]) % MOD
	    ) %= MOD;
}

void pushDown(int x, int l, int r) {
	add(x << 1, ta[x], tb[x], (r + l) / 2 - l);
	int dist = ((l + r) >> 1) + 1 - l;
	int b = (1LL * tb[x] * base[dist].dat[0][0] % MOD + 1LL * ta[x] * base[dist].dat[0][1] % MOD) % MOD;
	int a = (1LL * tb[x] * base[dist].dat[1][0] % MOD + 1LL * ta[x] * base[dist].dat[1][1] % MOD) % MOD;
	add(x << 1 | 1, a, b, r - (l + r) / 2 - 1);
	ta[x] = tb[x] = 0;
}

int ask(int x, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
		return 0;
	if (ql <= l && r <= qr) {
		return sum[x];
	}
	pushDown(x, l, r);
	long long result = 0;
	int mid = (l + r) >> 1;
	result = (ask(x << 1, l, mid, ql, qr) + ask(x << 1 | 1, mid + 1, r, ql, qr)) % MOD;
	update(x);
	return result;
}

void insert(int x, int l, int r, int ql, int qr) {
	if (ql > r || qr < l)
		return ;
	if (ql <= l && r <= qr) {
		int dist = l - ql;
		int b = (base[dist].dat[0][0] + base[dist].dat[0][1]) % MOD;
		int a = (base[dist].dat[1][0] + base[dist].dat[1][1]) % MOD;
		add(x, a, b, r - l);
		return ;
	}
	pushDown(x, l, r);
	int mid = (l + r) >> 1;
	insert(x << 1, l, mid, ql, qr);
	insert(x << 1 | 1, mid + 1, r, ql, qr);
	update(x);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
		
	base[0].setOne();
	trans.clear();
	trans.dat[0][0] = trans.dat[0][1] = trans.dat[1][0] = trans.dat[2][0] = trans.dat[2][2] = 1;
	for(int i = 1; i <= n; i++) {
		base[i] = trans * base[i - 1];
	}
	build(1, 1, n);
	for(int i = 1; i <= m; i++) {
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		if (type == 1) {
			insert(1, 1, n, l, r);
		} else {
			printf("%d\n", ask(1, 1, n, l, r));
		}
	}
	return 0;
}