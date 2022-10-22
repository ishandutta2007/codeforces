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
 
using ll = long long;
using ld = long double;
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

const int N = 1e6 + 500;

int n, x, y, a[N], dp[N];

int main() {
	scanf ("%d%d%d", &n, &x, &y);
	poly A(x + 1), B(x + 1);
	rep(i, 1, n + 1) {
		scanf ("%d", a + i);
		A[a[i]] = 1;
		B[x - a[i]] = 1;
	}
	poly C = A * B;
	fill(dp, dp + N, -1);
	rep(i, 1, 2 * (x + y)) {
		int rem = i - 2 * y;
		if (rem <= 0 || rem % 2) continue;
		if (x + rem / 2 < sz(C) && C[x + rem / 2]) dp[i] = i;
	}
	rep(i, 1, 2 * (x + y))
		rep(j, 1, (N - 1) / i)
			dp[i * j] = max(dp[i * j], dp[i]);
	int q;
	scanf ("%d", &q);
	while (q--) {
		int a;
		scanf ("%d", &a);
		printf ("%d ", dp[a]);
	}
	return 0;
}