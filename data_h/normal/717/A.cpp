#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int modulo(1e9 + 7);
int pw(int x, long long n) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = (long long)res * x % modulo;
		}
		n /= 2;
		x = (long long)x * x % modulo;
	}
	return res;
}
struct Num {
	int n, sq5;
	void print() const {
		printf("%d + %dsq5\n", n, sq5);
	}
	Num(int n, int sq5) : n(n), sq5(sq5) {
	}
	Num() {
	}
	Num operator + (const Num & b) const {
		return Num((n + b.n) % modulo, (sq5 + b.sq5) % modulo);
	}
	Num operator - (const Num & b) const {
		return Num((n - b.n + modulo) % modulo, (sq5 - b.sq5 + modulo) % modulo);
	}
	Num operator * (const Num & b) const {
		return Num(((long long)n * b.n + 5ll * sq5 * b.sq5) % modulo, ((long long)n * b.sq5 + (long long)sq5 * b.n) % modulo);
	}
	bool operator == (const Num & b) const {
		return n == b.n && sq5 == b.sq5;
	}
};
Num pw(Num x, long long n) {
	Num res(1, 0);
	while(n) {
		if(n & 1) {
			res = res * x;
		}
		n /= 2;
		x = x * x;
	}
	return res;
}
const int N(222);
int coe[N], c[N][N];
Num a, b, A, B;
Num inv(const Num & x) {
	int a(x.n), b(x.sq5);
	int tmp(((long long) a * a - 5ll * b * b) % modulo);
	tmp = (tmp + modulo) % modulo;
	tmp = pw(tmp, modulo - 2);
	return Num((long long)a * tmp % modulo, (long long)(modulo - b) * tmp % modulo);
}
int calc(int k, long long r) {
	Num res(0, 0);
	for(int j(0); j <= k; j++) {
		Num tmp(c[k][j], 0);
		tmp = tmp * pw(a, j) * pw(b, k - j);
		Num q(pw(A, j) * pw(B, k - j));
		tmp = tmp * (q == Num(1, 0) ? Num((r + 1) % modulo, 0) : (Num(1, 0) - pw(q, r + 1)) * inv(Num(1, 0) - q));
		res = res + tmp;
	}
	//printf("calc %d %lld = ", k, r);
	//res.print();
	return res.n;
}
int inv2(pw(2, modulo - 2)), inv5(pw(5, modulo - 5));
int main() {
	Num sq5(0, 1);
	A = (Num(1, 0) + sq5) * Num(inv2, 0);
	B = (Num(1, 0) - sq5) * Num(inv2, 0);
	a = (B - Num(2, 0)) * inv(B - A);
	b = (Num(2, 0) - A) * inv(B - A);

	/*a.print();
	b.print();
	(a + b).print();
	(a * A + b * B).print();
	(a * A * A * A + b * B * B * B).print();*/
	for(int i(0); i <= 200; i++) {
		for(int j(0); j <= i; j++) {
			c[i][j] = (i == 0 || j == 0) ? 1 : (c[i - 1][j - 1] + c[i - 1][j]) % modulo;
		}
	}
	int k;
	long long l, r;
	cin >> k >> l >> r;
	coe[0] = 1;
	for(int i(1); i <= 200; i++) {
		coe[i] = 0;
	}
	for(int i(0); i < k; i++) {
		// *= (-i + x)
		for(int j(i + 1); j >= 0; j--) {
			coe[j] = ((long long)coe[j] * (modulo - i) + (j ? coe[j - 1] : 0)) % modulo;
		}
	}
	int ans(0);
	for(int i(0); i <= k; i++) {
		ans = (ans + (calc(i, r) - calc(i, l - 1) + modulo) * (long long)coe[i]) % modulo;
	}
	int tmp(1);
	for(int i(1); i <= k; i++) {
		tmp = (long long)tmp * i % modulo;
	}
	ans = ((long long)ans * pw(tmp, modulo - 2)) % modulo;
	cout << ans << endl;
}