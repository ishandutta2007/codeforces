#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define low(a) ((a) & -(a))
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const ll mo = 1e9 + 7;

const int N = 2e5 + 5;

int n, x, y;
struct node {
	int final[N], to[N], next[N], tot;
	void link(int x, int y) {
		next[++ tot] = final[x], to[tot] = y, final[x] = tot;
	}
} e;

int bz[N], f[18][N / 2], dep[N], p[N], q[N], tp;
void dg(int x) {
	bz[x] = 1;
	p[x] = ++ tp;
	for(int i = e.final[x]; i; i = e.next[i]) {
		int y = e.to[i]; if(bz[y]) continue;
		f[0][y] = x; dep[y] = dep[x] + 1;
		dg(y);
	}
	q[x] = tp;
	bz[x] = 0;
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	fd(i, 17, 0) if(dep[f[i][x]] >= dep[y]) x = f[i][x];
	if(x == y) return x;
	fd(i, 17, 0) if(f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
	return f[0][x];
}

const int M = 1e7;
int bx[M + 5], pe[M], t[M + 5];
void Shai() {
	fo(i, 2, M) {
		if(!bx[i]) pe[++ pe[0]] = i, t[i] = i;
		fo(j, 1, pe[0]) {
			int k = i * pe[j];
			if(k > M) break;
			bx[k] = 1; t[k] = pe[j];
			if(i % pe[j] == 0) break;
		}
	}
}

int u[N], v[N];
void fen(int x) {
	u[0] = 0;
	while(x > 1) {
		u[++ u[0]] = t[x]; v[u[0]] = 0;
		int y = t[x]; while(x % y == 0) v[u[0]] ++, x /= y;
	}
}

int a[N], Q;

struct Ask {
	int x, y, z;
} b[N];

const int C = 5000005;
struct zhi {
	int final[M], to[C], len[C], next[C], bl[C], le[C], tot;
	void link(int x, int y, int z, int u, int v) {
		if(y == 0) return;
		next[++ tot] = final[x], to[tot] = y, len[tot] = z, bl[tot] = u, le[tot] = v, final[x] = tot;
	}
} c;

struct node2 {
	int len, x, bl, le;
} d[M];

int cmp(node2 a, node2 b) {
	return a.len < b.len;
}

int g[N];

ll ksm(ll x, ll y) {
	ll s = 1;
	for(; y; y /= 2, x = x * x % mo)
		if(y & 1) s = s * x % mo;
	return s;
}

ll ans[N];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		e.link(x, y); e.link(y, x);
	}
	dep[1] = 1; dg(1);
	fo(i, 1, 17) fo(j, 1, n) f[i][j] = f[i - 1][f[i - 1][j]];
	
	Shai();
	fo(i, 1, n) {
		scanf("%d", &a[i]);
		fen(a[i]);
		fo(j, 1, u[0]) {
			c.link(u[j], i, v[j], 0, 0);
		}
	}
	scanf("%d", &Q);
	fo(i, 1, Q) {
		ans[i] = 1;
		scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].z);
		fen(b[i].z);
		int z = lca(b[i].x, b[i].y);
		
		fo(j, 1, u[0]) {
			c.link(u[j], b[i].x, v[j], i, 1);
			c.link(u[j], b[i].y, v[j], i, 1);
			c.link(u[j], z, v[j], i, -1);
			c.link(u[j], f[0][z], v[j], i, -1);
		}
	}
	fo(ii, 2, M) if(t[ii] == ii) {
		int d0 = 0;
		for(int j = c.final[ii]; j; j = c.next[j]) {
			d[++ d0].len = c.len[j];
			d[d0].x = c.to[j];
			d[d0].bl = c.bl[j];
			d[d0].le = c.le[j];
		}
		sort(d + 1, d + d0 + 1, cmp);
		fo(i, 1, d0) {
			if(!d[i].bl) {
				x = p[d[i].x];
				while(x <= n) g[x] += d[i].len, x += low(x);
				x = q[d[i].x] + 1;
				while(x <= n) g[x] -= d[i].len, x += low(x);
			} else {
				x = p[d[i].x];
				int s = 0;
				while(x) s += g[x], x -= low(x);
				if(d[i].le == 1) ans[d[i].bl] = ans[d[i].bl] * ksm(ii, s) % mo; else ans[d[i].bl] = ans[d[i].bl] * ksm(ksm(ii, s), mo - 2) % mo;
			}
		}
		fo(i, 1, d0) if(!d[i].bl) {
			x = p[d[i].x];
			while(x <= n) g[x] -= d[i].len, x += low(x);
			x = q[d[i].x] + 1;
			while(x <= n) g[x] += d[i].len, x += low(x);
		}
		fd(i, d0, 1) {
			int s = 0;
			if(!d[i].bl) {
				x = p[d[i].x];
				while(x <= n) g[x] ++, x += low(x);
				x = q[d[i].x] + 1;
				while(x <= n) g[x] --, x += low(x);
			} else {
				x = p[d[i].x];
				int s = 0;
				while(x) s += g[x], x -= low(x);
				if(d[i].le == 1) ans[d[i].bl] = ans[d[i].bl] * ksm(ii, s * d[i].len) % mo; else ans[d[i].bl] = ans[d[i].bl] * ksm(ksm(ii, s * d[i].len), mo - 2) % mo;
			}
		}
		fd(i, d0, 1) if(!d[i].bl) {
			x = p[d[i].x];
			while(x <= n) g[x] --, x += low(x);
			x = q[d[i].x] + 1;
			while(x <= n) g[x] ++, x += low(x);
		}
	}
	fo(i, 1, Q) printf("%I64d\n", ans[i]);
}