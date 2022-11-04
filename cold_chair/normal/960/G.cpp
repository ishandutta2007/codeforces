#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int mo = 998244353;

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

const int nm = 1 << 18;

#define V vector<ll>
#define si size()
#define re resize

ll inv[nm];

namespace ntt {
	ll w[nm], a[nm], b[nm];
	int r[nm];
	void build() {
		inv[0] = inv[1] = 1;
		ff(i, 2, nm) inv[i] = (ll) (mo - (mo / i)) * inv[mo % i] % mo;
		for(int i = 1; i < nm; i *= 2) {
			w[i] = 1; ll v = ksm(3, (mo - 1) / 2 / i);
			ff(j, 1, i) w[i + j] = w[i + j - 1] * v % mo;
		}
	}
	void dft(ll *a, int n, int f) {
		ff(i, 0, n) {
			r[i] = r[i / 2] / 2 + (i & 1) * (n / 2);
			if(i < r[i]) swap(a[i], a[r[i]]);
		} ll v;
		for(int i = 1; i < n; i *= 2) for(int j = 0; j < n; j += 2 * i) ff(k, 0, i) {
			v = a[i + j + k] * w[i + k], a[i + j + k] = (a[j + k] - v) % mo, a[j + k] = (a[j + k] + v) % mo;
		}
		if(f == -1) {
			reverse(a + 1, a + n);
			v = ksm(n, mo - 2);
			ff(i, 0, n) a[i] = (a[i] + mo) * v % mo;
		}
	}
	V operator * (V p, V q) {
		int n0 = p.si + q.si - 1, n = 1;
		while(n < n0) n *= 2;
		ff(i, 0, n) a[i] = b[i] = 0;
		ff(i, 0, p.si) a[i] = p[i];
		ff(i, 0, q.si) b[i] = q[i];
		dft(a, n, 1); dft(b, n, 1);
		ff(i, 0, n) a[i] = a[i] * b[i] % mo;
		dft(a, n, -1);
		p.re(n0);
		ff(i, 0, n0) p[i] = a[i];
		return p;
	}
	void dft(V &p, int f) {
		int n = p.si;
		ff(i, 0, n) a[i] = p[i];
		dft(a, n, f);
		ff(i, 0, n) p[i] = a[i];
	}
}

using ntt :: operator *;
using ntt :: dft;

V qni(V a) {
	int n0 = a.si;
	V b; b.re(1); b[0] = ksm(a[0], mo - 2);
	for(int n = 2; n < n0 * 2; n *= 2) {
		V c = a; c.re(n); c.re(2 * n);
		b.re(2 * n);
		dft(c, 1); dft(b, 1);
		ff(i, 0, 2 * n) b[i] = (2 * b[i] - c[i] * b[i] % mo * b[i]) % mo;
		dft(b, -1); b.re(n);
	}
	b.re(n0); return b;
}

V qd(V a) {
	int n0 = a.si;
	ff(i, 0, n0 - 1) a[i] = a[i + 1] * (i + 1) % mo;
	return a;
}

V jf(V a) {
	int n0 = a.si; a.re(n0 + 1);
	fd(i, n0, 1) a[i] = a[i - 1] * inv[i] % mo;
	a[0] = 0;
	return a;
}

V ln(V a) {
	int n0 = a.si;
	V b = qd(a) * qni(a);
	b.re(n0); b = jf(b); b.re(n0);
	return b;
}

V exp(V a) {
	int n0 = a.si;
	V b; b.re(1); b[0] = 1;
	for(int n = 2; n < 2 * n0; n *= 2) {
		V c = a; c.re(n);
		V d = b; d.re(n); d = ln(d);
		ff(i, 0, n) c[i] = (c[i] - d[i]) % mo;
		c[0] ++;
		b = b * c;
		b.re(n);
	}
	b.re(n0); return b;
}

const int N = 1e5 + 5;

int n, a, b;

ll fac[N], nf[N];

ll C(int n, int m) {
	return fac[n] * nf[n - m] % mo * nf[m] % mo;
}

ll S(int n, int m) {
	if(m == 0) return n == 0;
	V x; x.re(n);
	fo(i, 1, n) x[i - 1] = fac[i - 1] * nf[i] % mo;
	x = ln(x);
	ff(i, 0, n) x[i] = x[i] * m % mo;
	x = exp(x);
	return x[n - m] * fac[n] % mo * nf[m] % mo;
}

int main() {
	ntt :: build();
	scanf("%d %d %d", &n, &a, &b);
	fac[0] = 1; fo(i, 1, n) fac[i] = fac[i - 1] * i % mo;
	nf[n] = ksm(fac[n], mo - 2); fd(i, n, 1) nf[i - 1] = nf[i] * i % mo;
	if(a + b - 1 > n || a == 0 || b == 0) {
		pp("0\n"); return 0;
	}
	pp("%lld\n", S(n - 1, a - 1 + b - 1) * C(a - 1 + b - 1, a - 1) % mo);
}