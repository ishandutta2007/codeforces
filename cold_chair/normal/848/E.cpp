#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
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

typedef vector<ll> V;
#define pb push_back
#define si size()

namespace ntt {
	const int nm = 131072;
	ll a[nm], b[nm], w[nm]; int r[nm];
	void build() {
		for(int i = 1; i < nm; i *= 2) ff(j, 0, i)
			w[i + j] = ksm(3, (mo - 1) / 2 / i * j);
	}
	void dft(ll *a, int n, int f) {
		ff(i, 0, n) {
			r[i] = r[i / 2] / 2 + (i & 1) * (n / 2);
			if(i < r[i]) swap(a[i], a[r[i]]);
		} ll b;
		for(int i = 1; i < n; i *= 2) for(int j = 0; j < n; j += 2 * i)
			ff(k, 0, i) b = a[i + j + k] * w[i + k], a[i + j + k] = (a[j + k] - b) % mo, a[j + k] = (a[j + k] + b) % mo;
		if(f == -1) {
			reverse(a + 1, a + n);
			b = ksm(n, mo - 2);
			ff(i, 0, n) a[i] = (a[i] + mo) * b % mo;
		}
	}
	void fft(V &p, V &q) {
		int p0 = p.si + q.si - 1;
		int n = 1; while(n <= p0) n *= 2;
		ff(i, 0, n) a[i] = b[i] = 0;
		ff(i, 0, p.si) a[i] = p[i];
		ff(i, 0, q.si) b[i] = q[i];
		dft(a, n, 1); dft(b, n, 1);
		ff(i, 0, n) a[i] = a[i] * b[i] % mo;
		dft(a, n, -1);
		p.resize(p0);
		ff(i, 0, p0) p[i] = a[i];
	}
}

V operator * (V a, V b) {
	ntt :: fft(a, b);
	return a;
}

const int N = 50005;

int n;
ll f[N][2][2], g[N], h[N][2], ans;

void dp(int x, int y, int m, int u, int v) {
	V p, q;
	p.resize(m - x + 1);
	fo(i, x, m) p[i - x] = h[i][u];
	q.resize(y - x + 1);
	ff(i, 0, q.si) q[i] = f[i][u][v];
	p = p * q;
	fo(i, m + 1, y) h[i][v] = (h[i][v] + p[i - x]) % mo;
}

void dg(int x, int y) {
	if(x == y) return;
	int m = x + y >> 1;
	dg(x, m);
	fo(u, 0, 1) fo(v, 0, 1) dp(x, y, m, u, v);
	dg(m + 1, y);
}

int main() {
	ntt :: build();
	
	scanf("%d", &n);
	g[0] = 1;
	fo(i, 1, n) g[i] = ((i < 2 ? 0 : g[i - 2]) + (i < 4 ? 0 : g[i - 4])) % mo;
	fo(i, 1, n) fo(j, 0, 1) fo(k, 0, 1)
		f[i][j][k] = (i - 1 - j - k >= 0) ? g[i - 1 - j - k] * (i - 1) % mo * (i - 1) % mo: 0;
	h[0][0] = 1;
	dg(0, n - 1);
	fo(i, 0, n - 1) fo(v, 0, 1) ans = (ans + h[i][v] * f[n - i][v][0] % mo * (n - i)) % mo;
	memset(h, 0, sizeof h); h[0][1] = 1;
	dg(0, n - 1);
	fo(i, 0, n - 1) fo(v, 0, 1) ans = (ans + h[i][v] * f[n - i][v][1] % mo * (n - i)) % mo;
	
	pp("%I64d\n", ans);
}