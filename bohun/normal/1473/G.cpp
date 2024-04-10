#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
 
using ll = long long;
using namespace std;

#define poly vector<int>

const int MOD = 998244353;
const int G = 5;

int add(int a, int b) {
	if (a + b < MOD) return a + b;
	return a + b - MOD;
}

int sub(int a, int b) {
	if (0 <= a - b) return a - b;
	return a - b + MOD;
}

int mul(int a, int b) {
	return ll(a) * b % MOD;
}

int bin_pow(int a, ll b) {
	int c = 1;
	while (b) {
		if (b & 1)
			c = mul(c, a);
		a = mul(a, a);
		b >>= 1;
	}
	return c;
}

void fft(poly &a, bool inv) {
	int n = sz(a), j = 0;
	rep(i, 1, n - 1) {
		int bit = n >> 1;
		while (bit & j) {
			j ^= bit;
			bit >>= 1;
		}
		j ^= bit;
		if (i < j) swap(a[i], a[j]);
	}
	
	for (int len = 1; len < n; len <<= 1) {
		int root = bin_pow(G, (MOD - 1) / (2 * len));
		if (inv) root = bin_pow(root, MOD - 2);
		for (int i = 0; i < n; i += 2 * len) {
			int w = 1;
			rep(j, 0, len - 1) {
				int u = a[i + j], v = mul(a[i + j + len], w);
				a[i + j] = add(u, v);
				a[i + j + len] = sub(u, v);
				w = mul(w, root);
			}
		}
	}
	
	if (inv) {
		int y = bin_pow(n, MOD - 2);
		for (auto &x : a)
			x = mul(x, y);
	}
}

poly operator *(poly a, poly b) {
	int n = 1;
	while (n < sz(a) + sz(b)) n <<= 1;
	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);
	rep(i, 0, n - 1)
		a[i] = mul(a[i], b[i]);
	fft(a, true);
	return a;
}

const int M = 1e6;

int fac[M], rev[M];

void init() {
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

int n, a, b;

int main() {
	init();
	scanf("%d", &n);
	poly ans = {1};
	rep(i, 1, n) {
		scanf("%d%d", &a, &b);
		int h1 = sz(ans) - 1, h2 = sz(ans) + a - b - 1;
		poly curr(h1 + h2 + 1);
		rep(i, -h2, h1)
			curr[h1 - i] = C(a + b, i + a);
		curr = curr * ans;
		poly nans;
		rep(sz, 0, h2)
			nans.pb(curr[sz + h1]);
		ans = nans;
	}
	printf("%lld\n", accumulate(ans.begin(), ans.end(), 0LL) % MOD);
	return 0;
}