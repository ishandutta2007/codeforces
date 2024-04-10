#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int mo = 998244353;

const int N = 2e5 + 5;

int n, x, y;
int fi[N], to[N * 2], nt[N * 2], tot = 1;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

int fa[N], fq[N];

int d[N], d0;

ll f[N][2][2], g[2][2], h[2][2];

void dg(int x) {
	for(int i = fi[x]; i; i = nt[i]) if(to[i] != fa[x]) {
		int y = to[i];
		fa[y] = x; fq[y] = i;
		dg(y);
	}
	d0 = 0;
	for(int i = fi[x]; i; i = nt[i])
		d[++ d0] = to[i];
	reverse(d + 1, d + d0 + 1);
	fo(st, 0, 1) {
		memset(g, 0, sizeof g);
		g[0][st] = 1;
		fo(i, 1, d0) {
			memcpy(h, g, sizeof g);
			memset(g, 0, sizeof g);
			int y = d[i];
			if(y == fa[x]) {
				fo(u, 0, 1) fo(v, 0, 1) if(h[u][v]) {
					if(!u && !v) {
						g[1][0] = (g[1][0] + h[u][v]) % mo;
						g[0][1] = (g[0][1] + h[u][v]) % mo;
					} else {
						g[u][v] = (g[u][v] + h[u][v]) % mo;
					}
				}
			} else {
				fo(u, 0, 1) fo(v, 0, 1) if(h[u][v]) {
					fo(p, 0, 1) if(f[y][u][p])
						g[p][v] = (g[p][v] + h[u][v] * f[y][u][p]) % mo;
				}
			}
		}
		f[x][st][0] = (g[0][0] + g[1][0]) % mo;
		f[x][st][1] = (g[0][1] + g[1][1]) % mo;
	}
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
	}
	dg(1);
	pp("%lld\n", f[1][1][1]);
}