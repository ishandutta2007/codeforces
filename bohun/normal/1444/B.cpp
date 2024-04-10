#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using ll = long long;
using ld = long double;
using namespace std;

const int MOD = 998244353;
const int M = 1e6 + 5;

int add(int a, int b) {
	return a + b < MOD ? a + b : a + b - MOD;
} 
 
int sub(int a, int b) {
	return 0 <= a - b ? a - b : a - b + MOD;
}
 
int mul(int a, int b) {
	return ll(a) * b % MOD;
}
 
int bin_pow(int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = mul(c, a);
		a = mul(a, a);
		b >>= 1;
	}
	return c;
}

int fac[M], rev[M];

void factorials() {
	fac[0] = 1;
	rep(i, 1, M - 1) 
		fac[i] = mul(fac[i - 1], i);
	rev[M - 1] = bin_pow(fac[M - 1], MOD - 2);
	per(i, 1, M - 1)
		rev[i - 1] = mul(rev[i], i);
}

int C(int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return mul(fac[n], mul(rev[n - k], rev[k]));
}

const int N = 4e5 + 50;

int n, a[N], res;

int main() {
	factorials();
	scanf ("%d", &n);
	rep(i, 1, 2 * n) scanf ("%d", a + i);
	sort(a + 1, a + 2 * n + 1);
	int w = 0;
	rep(i, 1, n)
		w = add(w, mul(C(n - 1, i - 1), C(n, i)));
	rep(i, 1, n)
		res = sub(res, mul(a[i], w));
	rep(i, n + 1, 2 * n)
		res = add(res, mul(a[i], w));
	printf ("%d\n", mul(2, res));
}