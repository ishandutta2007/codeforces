#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define abs(a) ((a) > 0 ? (a) : - (a))
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 2e5 + 5, M = 500;

int n, m, x, y, a[N], p[N], q[N];

struct edge {
	int final[N], next[N], to[N], tot;
	void link(int x, int y) {
		next[++ tot] = final[x], to[tot] = y, final[x] = tot;
	}
} e;

int fa[17][N], dfn[N], td, dep[N];

void dg(int x) {
	p[x] = ++ td;
	for(int i = e.final[x]; i; i = e.next[i]) {
		int y = e.to[i];
		dep[y] = dep[x] + 1;
		dg(y);
	}
	q[x] = td;
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	fd(i, 16, 0) if(dep[fa[i][x]] >= dep[y]) x = fa[i][x];
	if(x == y) return x;
	fd(i, 16, 0) if(fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}

int b[N];

int num[N];

struct Ka {
	int l, r;
} t[N];

int d[N], z[N], f[N], z0, g[N], g0;

int cmp(int x, int y) {
	return p[x] < p[y];
}

int cmp2(int x, int y) {
	return a[x]	< a[y];
}

int u[N];

struct P {
	int x, y, s;
	P (int _x = 0, int _y = 0, int _s = 0) {x = _x, y = _y, s = _s;}
};

vector<P> v[N]; int v0[N];

int du[N], ans[N], lk[N], xiu[N], xi[N];
int h[N];

int main() {
//	freopen("e.in", "r", stdin);
//	freopen("e.out", "w", stdout);
	scanf("%d %d", &n, &m);
	fo(i, 2, n) {
		scanf("%d", &fa[0][i]);
		e.link(fa[0][i], i);
	}
	dep[1] = 1; dg(1);
	fo(i, 1, 16) fo(j, 1, n) fa[i][j] = fa[i - 1][fa[i - 1][j]];
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, m) {
		scanf("%d", &b[i]);
		num[i] = num[i - 1];
		if(i % M == 1) {
			num[i] ++;
			t[num[i] - 1].r = i - 1;
			t[num[i]].l = i;
		}
	}
	t[num[m]].r = m;
	fo(k, 1, num[m]) {
		d[d[0] = 1] = 1; fo(i, t[k].l, t[k].r) d[++ d[0]] = abs(b[i]);
		sort(d + 1, d + d[0] + 1, cmp);
		int d0 = d[0]; fo(i, 2, d[0]) d[++ d0] = lca(d[i - 1], d[i]);
		sort(d + 1, d + d0 + 1, cmp);
		d[0] = 0;
		fo(i, 1, d0) if(i == 1 || d[i] != d[i - 1])
			d[++ d[0]] = d[i];
		z0 = 0;
		fo(i, 1, d[0]) {
			int x = d[i];
			while(z0 > 0 && (p[x] < p[z[z0]] || p[x] > q[z[z0]]))
				f[z[z0]] = z[z0 - 1], z0 --;
			z[++ z0] = x;
		}
		while(z0 > 0) f[z[z0]] = z[z0 - 1], z0 --;
		
//		fo(i, 1, d[0]) printf("%d ", d[i]); printf("\n");
//		fo(i, 1, d[0]) printf("%d ", f[d[i]]); printf("\n");

		int sum = 0;
		fo(i, 1, n) sum += (a[i] < 0) * !du[i];
		
		fo(i, 1, n) h[i] = lk[i] = xi[i] = xiu[i] = v0[i] = 0;
		fo(i, 1, d[0]) {
			int x = d[i]; if(x == 1) continue;
			
			u[0] = 0;
			int y = fa[0][x];
			while(y != f[x]) {
				if(!du[y]) u[++ u[0]] = y;
				y = fa[0][y];
			}
			
			sort(u + 1, u + u[0] + 1, cmp2);
			
			v[x].clear(); v[x].push_back(P(0, 0, 0));
			
			fo(i, 1, u[0]) {
				if(i == 1 || a[u[i - 1]] != a[u[i]]) {
					v0[x] ++;
					v[x].push_back(P(a[u[i]], 1, 0));
				} else v[x][v0[x]].y ++;
			}
			fo(i, 1, v0[x]) v[x][i].s = v[x][i - 1].s + v[x][i].y;
			while(lk[x] < v0[x] && v[x][lk[x] + 1].x < 0) lk[x] ++;
		}
		fo(i, t[k].l, t[k].r) {
			int x = abs(b[i]), y = b[i] > 0 ? 1 : -1;
			h[p[x]] -= y;
			if(y > 0) {
				if(a[x] + xi[x] < 0) sum --;
				du[x] = 1;
			} else {
				if(a[x] + xi[x] < 0) sum ++;
//				if(i == 501) printf("%d %d %d %d\n", sum, a[x], xi[x], x);
				du[x] = 0;
			}
			while(x > 0) {
				if(x != abs(b[i])) {
					if(!du[x]) {
						if(y > 0) if(a[x] + xi[x] == 0) sum ++;
						if(y < 0) if(a[x] + xi[x] == -1) sum --;
					}
					xi[x] -= y;
				}
				if(x == 1) break;
				sum -= v[x][lk[x]].s;
				xiu[x] -= y;
				if(lk[x] < v0[x] && v[x][lk[x] + 1].x + xiu[x] < 0) lk[x] ++;
				if(lk[x] > 0 && v[x][lk[x]].x + xiu[x] >= 0) lk[x] --;
				sum += v[x][lk[x]].s;
				x = f[x];
			}
			ans[i] = sum;
		}
		fo(i, 1, n) h[i] += h[i - 1];
		fo(i, 1, n) a[i] += h[q[i]] - h[p[i]];
		
		sum = 0;
		fo(i, 1, n) sum += (a[i] < 0) * !du[i];
//		printf("%d\n", sum);
//		fo(i, 1, n) printf("%d ", a[i]); printf("\n");
	}
	fo(i, 1, m) printf("%d ", ans[i]);
}