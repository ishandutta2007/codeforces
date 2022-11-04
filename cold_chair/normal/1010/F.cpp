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

#define V vector<ll>
#define si size()
#define re resize
#define pb push_back

	namespace ntt {
		const int nm = 1 << 18;
		
		int r[nm]; ll w[nm];
		
		void build() {
			for(int i = 1; i < nm; i *= 2) {
				w[i] = 1; ll v = ksm(3, (mo - 1) / 2 / i);
				ff(j, 1, i)	w[i + j] = w[i + j - 1] * v % mo;
			}
		}
		
		ll a[nm], b[nm];
		
		void dft(ll *a, int n, int f) {
			ff(i, 0, n)  {
				r[i] = r[i / 2] / 2 + (i & 1) * (n / 2);
				if(i < r[i]) swap(a[i], a[r[i]]);
			} ll b;
			for(int i = 1; i < n; i *= 2) for(int j = 0; j < n; j += 2 * i) ff(k, 0, i)
				b = a[i + j + k] * w[i + k], a[i + j + k] = (a[j + k] - b) % mo, a[j + k] = (a[j + k] + b) % mo;
			if(f == -1) {
				reverse(a + 1, a + n);
				b = ksm(n, mo - 2);
				ff(i, 0, n) a[i] = (a[i] + mo) * b % mo;
			}
		}
		
		V operator * (V p, V q) {
			int n0 = p.si + q.si - 1, n = 1;
			
			if(n0 < 1024) {
				V z; z.clear(); z.re(n0);
				ff(i, 0, p.si) ff(j, 0, q.si)
					z[i + j] = (z[i + j] + p[i] * q[j]) % mo;
				return z;
			}
			
			while(n < n0) n *= 2;
			ff(i, 0 ,n) a[i] = b[i] = 0;
			ff(i, 0, p.si) a[i] = p[i];
			ff(i, 0, q.si) b[i] = q[i];
			dft(a, n, 1); dft(b, n, 1);
			ff(i, 0, n) a[i] = a[i] * b[i] % mo;
			dft(a, n, -1);
			p.re(n0);
			ff(i, 0, n0) p[i] = a[i];
			return p;
		}
	}

using ntt :: operator *;

V operator + (V p, V q) {
	if(p.si < q.si) p.re(q.si);
	ff(i, 0, q.si) p[i] = (p[i] + q[i]) % mo;
	return p;
}

const int N = 1e5 + 5;

int n, x, y; ll s;
int fa[N];
vector<int> e[N];
int top[N], son[N], siz[N];

void dg(int x) {
	siz[x] = 1;
	ff(_y, 0, e[x].si) {
		int y = e[x][_y]; if(y == fa[x]) continue;
		fa[y] = x;
		dg(y);
		siz[x] += siz[y];
		if(siz[y] > siz[son[x]]) son[x] = y;
	}
}

void dfs(int x) {
	if(!top[x]) top[x] = x;
	if(son[x]) top[son[x]] = top[x], dfs(son[x]);
	
	ff(_y, 0, e[x].si) {
		int y = e[x][_y]; if(y == fa[x] || y == son[x]) continue;
		dfs(y);
	}
}

int d[N], d0;

V f[N], g[N], h[N];

int cmpd(int x, int y) {
	return g[x].si < g[y].si;
}

V fz(int x, int y) {
	if(x == y) return g[d[x]];
	int m = x + y >> 1;
	return fz(x, m) * fz(m + 1, y);
}

V fz2(int x, int y) {
	if(x == y) return h[d[x]];
	int m = x + y >> 1;
	return fz2(x, m) * fz2(m + 1, y);
}

#define i0 i + i
#define i1 i + i + 1

V t[N * 4][3];

void fg(int i, int x, int y) {
	if(x == y) {
		t[i][0] = t[i][1] = g[d[x]];
		t[i][2] = h[d[x]];
		return;
	}
	int m = x + y >> 1;
	fg(i0, x, m); fg(i1, m + 1, y);
	t[i][0] = t[i0][0] * t[i1][2] + t[i0][1] * t[i1][0];
	t[i][1] = t[i0][1] * t[i1][1];
	t[i][2] = t[i0][2] * t[i1][2];
//	t[i][0].clear();
//	V s; s.re(1); s[0] = 1;
//	fo(j, x, y) {
//		s = s * g[d[j]];
//		V s2 = s;
//		fo(k, j + 1, y) s2 = s2 * h[d[k]];
//		t[i][0] = t[i][0] = s2;
//	}
}

void dd(int x) {
	ff(_y, 0, e[x].si) {
		int y = e[x][_y]; if(y == fa[x] || y == son[x]) continue;
		dd(y);
	}
	
	g[x].re(1); g[x][0] = 1;
	h[x].re(2); h[x][0] = 1; h[x][1] = -1;
	d[d0 = 1] = x;
	ff(_y, 0, e[x].si) {
		int y = e[x][_y]; if(y == fa[x] || y == son[x]) continue;
		d[++ d0] = y;
		g[y] = f[y] + h[y];
	}
	sort(d + 1, d + d0 + 1, cmpd);
	g[x] = fz(1, d0);
	h[x] = fz2(1, d0);
	
	if(son[x]) dd(son[x]);
	
	if(son[fa[x]] != x) {
		d0 = 0;
		for(int p = x; p; p = son[p]) d[++ d0] = p;
		fg(1, 1, d0);
		f[x] = t[1][0];
		h[x] = t[1][2];
//		pp("x = %d\n", x);
//		ff(j, 0, f[x].si) pp("%lld ", f[x][j]); hh;
	}
}

void End() {
	static ll v[N * 2], c[N * 2], w[N * 2], xs[N];
	
	fo(i, 0, 2 * n) v[i] = (i - n + s) % mo;
	w[0] = v[0] ? v[0] : 1;
	fo(i, 1, 2 * n) w[i] = w[i - 1] * (v[i] ? v[i] : 1) % mo;
	c[0] = v[0] ? 0 : 1;
	fo(i, 1, 2 * n) c[i] = c[i - 1] + (v[i] ? 0 : 1);
	
	ll nf = 1;
	fo(i, 1, n - 1) nf = nf * i % mo;
	nf = ksm(nf, mo - 2);
	
	fo(i, 0, n) {
		int l = -i + 1, r = -i + n - 1;
		r += n, l += n;
		if(c[r] - c[l - 1] > 0) {
			xs[i] = 0;
		} else {
			xs[i] = w[r] * ksm(w[l - 1], mo - 2) % mo * nf % mo;
		}
	}
	int m = min(n, (int) f[1].si - 1);
	ll ans = 0;
	fo(i ,0, m) ans = (ans + f[1][i] * xs[i]) % mo;
	ans = (ans % mo + mo) % mo;
	pp("%lld\n", ans);
}

int main() {
	ntt :: build();
	scanf("%d %lld", &n, &s);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		e[x].pb(y); e[y].pb(x);
	}
	dg(1);
	dfs(1);
	dd(1);
	End();
}