#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 6;

int MOD;

struct Matrix {
	long long dat[N][N];
	// x, y, dx, dy, t;
	
	void clear() {
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				dat[i][j] = 0;
	}
	
	friend inline Matrix operator *(const Matrix &a, const Matrix &b) {
		Matrix c;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++) {
				c.dat[i][j] = 0;
				for(int k = 0; k < N; k++) {
					(c.dat[i][j] += a.dat[i][k] * b.dat[k][j] % MOD) %= MOD;
				}
			}
		return c;
	}
	
	void show() {
		for(int i = 0; i < N; i++, printf("\n")) {
			for(int j = 0; j < N; printf("%I64d ", dat[i][j++]));
		}
		printf("\n");
	}
};

Matrix trans, base, tmp;

long long solve(long long a, long long range) {
	if (a == 0)
		return range;
	return a;
}

int modify(int a, int b) {
	a %= b;
	if (a < 0)
		a += b;
	return a;
}

int main() {
	
	base.clear();
	for(int i = 0; i < N; i++)
		base.dat[i][i] = 1;
	trans.clear();
	trans.dat[0][0] = 2; trans.dat[0][1] = trans.dat[0][2] = trans.dat[0][4] = 1;
	trans.dat[1][1] = 2; trans.dat[1][0] = trans.dat[1][3] = trans.dat[1][4] = 1;
	trans.dat[2][0] = trans.dat[2][1] = trans.dat[2][2] = trans.dat[2][4] = 1;
	trans.dat[3][0] = trans.dat[3][1] = trans.dat[3][3] = trans.dat[3][4] = 1;
	trans.dat[4][4] = trans.dat[4][5] = 1;
	trans.dat[5][5] = 1;
	
	int n, sx, sy, dx, dy;
	long long t, tt;
	scanf("%d %d %d %d %d %I64d", &n, &sx, &sy, &dx, &dy, &t);
	tt = t;
	MOD = n;
	while(t) {
		if (t & 1) {
			base = base * trans;
		}
		t >>= 1;
		trans = trans * trans;
	}
	tmp.clear();
	tmp.dat[0][0] = sx % n;
	tmp.dat[1][0] = sy % n;
	tmp.dat[2][0] = modify(dx, n);
	tmp.dat[3][0] = modify(dy, n);
	tmp.dat[4][0] = 0;
	tmp.dat[5][0] = 1;
	tmp = base * tmp;
	printf("%I64d %I64d\n", solve(tmp.dat[0][0], n), solve(tmp.dat[1][0], n));
	return 0;
}