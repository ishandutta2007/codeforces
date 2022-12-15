#include<bits/stdc++.h>
using namespace std;

const int p = 998244353, maxn = 2000005;
struct Z {int x; Z(int x0 = 0) : x(x0) {}};
int inline check(int x) { return x >= p ? x - p : x; }
Z operator +(const Z a, const Z b) { return check(a.x + b.x); }
Z operator -(const Z a, const Z b) { return check(a.x - b.x + p); }
Z operator -(const Z a) {return check(p - a.x);}
Z operator *(const Z a, const Z b) { return 1LL * a.x * b.x % p; }
Z& operator +=(Z &a, const Z b) { return a = a + b; }
Z& operator -=(Z &a, const Z b) { return a = a - b; }
Z& operator *=(Z &a, const Z b) { return a = a * b; }
Z qpow(Z a, int k) {
	Z ans = 1;
	for (; k; a *= a, k >>= 1) if (k & 1) ans *= a;
	return ans;
}
Z fac[maxn], ifac[maxn], inv[maxn];
void init() {
	inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i < maxn; i++)
		fac[i] = fac[i - 1] * i,
		inv[i] = -inv[p % i] * (p / i),
		ifac[i] = ifac[i - 1] * inv[i];
}

int main() {
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	Z s = 0;
	for (int i = 1; i <= n; i++) s += inv[i];
	s = m * s + 1;
	s = (n + m + 1) * s * inv[m + 1];
	printf("%d\n", s);
}