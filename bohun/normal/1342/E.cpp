#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int mod = 998244353;
const int nax = 5e5 + 100;

int pt(int a, int b) {
	if (b == 0) return 1;
	if (b&1) return 1LL * a * pt(a, b - 1) % mod;
	return pt(1LL * a * a % mod, b / 2);
}

int n, k;
int res;
int fac[nax], rev[nax];

int qq(int n, int k) {
	if (n < k) return 0LL;
	return 1LL * fac[n] * rev[k] % mod * rev[n - k] % mod;
}

int main() {
	fac[0] = rev[0] = 1;
	rep(i, 1, nax - 1) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
	scanf ("%d%d", &n, &k);
	if (k == 0) {
		res = 1;
		rep(i, 1, n) {
			res = 1LL * res * i % mod;
		}
		printf ("%d\n", res);
		return 0;
	}
	int g = n - k;
	if (g < 0) {
		printf ("0\n");
		return 0;
	}
	res = pt(g, n);
	rep(i, 1, g) {
		int a = 1LL * qq(g, i) * pt(g - i, n) % mod;
		if (i % 2 == 1) res = (res - a + mod) % mod;
		else res = (res + a) % mod;
	}
	printf ("%lld\n", 2LL * res * qq(n, g) % mod);
	
	
	return 0;
}