#include<cstdio>
#include<algorithm>
#define pp printf
#define ll long long
#define low(a) ((a) & -(a))
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 2e5 + 5;

int n, x, y, c[N];
int fi[N], to[N * 2], nt[N * 2], tot, fa[N];

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

const ll inf = 1e18;

ll s[N][2], s0[N], f[N][2], son[N];

void dg(int x) {
	f[x][0] = f[x][1] = inf;
	for(int i = fi[x]; i; i = nt[i]) if(to[i] != fa[x]) {
		int y = to[i]; fa[y] = x;
		dg(to[i]);
		son[x] ++;
		s0[x] += s[y][0];
		ll z = s[y][1] - s[y][0];
		if(z < f[x][0]) f[x][1] = f[x][0], f[x][0] = z; else
		if(z < f[x][1]) f[x][1] = z;
	}
	if(son[x] == 0) {
		s[x][0] = c[x];
		s[x][1] = 0;
	} else {
		s[x][0] = s0[x] + min(0ll, f[x][0] + c[x]);
		s[x][1] = s0[x] + f[x][0];
	}
}

int bz[N];
int d[N * 2][2], bd[N][2], d0;

void ins(int x, int y) {
	if(!bd[x][y]) bd[x][y] = 1, d[++ d0][0] = x, d[d0][1] = y;
}
int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &c[i]);
	fo(i, 1, n - 1) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
	}
	dg(1);
	ins(1, 0);
	fo(i, 1, d0) {
		int x = d[i][0], y = d[i][1];
		if(son[x] == 0) {
			if(!y) bz[x] = 1;
		} else {
			if(!y) {
				if(f[x][0] + c[x] <= 0) {
					bz[x] = 1; int cnt = 0;
					for(int j = fi[x]; j; j = nt[j]) if(to[j] != fa[x]) {
						int u = to[j];
						if(s[u][1] - s[u][0] <= f[x][0]) {
							cnt ++; ins(u, 1);
						} else ins(u, 0);
					}
					if(cnt > 1) {
						for(int j = fi[x]; j; j = nt[j]) if(to[j] != fa[x]) {
							int u = to[j];
							if(s[u][1] - s[u][0] <= f[x][0]) ins(u, 0);
						}
					}
				}
				if(0 <= f[x][0] + c[x]) {
					for(int j = fi[x]; j; j = nt[j]) if(to[j] != fa[x]) ins(to[j], 0);
				}
			} else {
				int cnt = 0;
				for(int j = fi[x]; j; j = nt[j]) if(to[j] != fa[x]) {
					int u = to[j];
					if(s[u][1] - s[u][0] <= f[x][0]) {
						cnt ++; ins(u, 1);
					} else ins(u, 0);
				}
				if(cnt > 1) {
					for(int j = fi[x]; j; j = nt[j]) if(to[j] != fa[x]) {
						int u = to[j];
						if(s[u][1] - s[u][0] <= f[x][0]) ins(u, 0);
					}
				}
			}
		}
	}
	int g = 0; fo(i, 1, n) g += bz[i];
	pp("%I64d %d\n", s[1][0], g);
	fo(i, 1, n) if(bz[i]) pp("%d ", i);
}