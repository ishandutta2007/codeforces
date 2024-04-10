#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define db double
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define low(a) ((a) & -(a))
using namespace std;

const int N = 2e5 + 5;

int n, w, b[N], nb[N], c[N], nc[N];
int f[2][N], g[2][N]; ll nv[N], ans;
db ti[N], ti2[N];

struct node {
	ll x, v;
} a[N];

int cmp(node a, node b) {
	return (db) - a.x / a.v < (db) -b.x / b.v;
}

int cmp2(int x, int y) {
	return ti[x] > ti[y];
}
int cmp3(int x, int y) {
	return ti2[x] > ti2[y];
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &w);
	fo(i, 1, n) scanf("%I64d %I64d", &a[i].x, &a[i].v);
	sort(a + 1, a + n + 1, cmp);
	fo(i, 1, n) nv[i] = (a[i].v > 0) ? (a[i].v - w) : (a[i].v + w);
	fo(i, 1, n) ti[i] = (nv[i] == 0) ? (1e9) : ((db) -a[i].x / nv[i]);
	fo(i, 1, n) b[i] = i;
	sort(b + 1, b + n + 1, cmp2);
	fo(i, 1, n) nb[b[i]] = i;
	
	fo(i, 1, n) ti2[i] = (a[i].v < 0) ? ((db) -a[i].x / (a[i].v - w)) :((db) -a[i].x / (a[i].v + w));
	fo(i, 1, n) c[i] = i;
	sort(c + 1, c + n + 1, cmp3);
	fo(i, 1, n) nc[c[i]] = i;
	
//	fo(i, 1, n)
//		printf("%I64d %I64d\n", a[i].x, a[i].v);
//	fo(i, 1, n) printf("%lf ", ti[i]); printf("\n");
//	fo(i, 1, n) printf("%lf ", ti2[i ]); printf("\n");
	fo(i, 1, n) {
		db nt = ti2[i]; int fu = a[i].v > 0;
		int x = 0;
		for(int l = 1, r = n; l <= r; ) {
			int m = l + r >> 1;
			if(ti[b[m]] >= nt)
				x = m, l = m + 1; else r = m - 1;
		}
		while(x) ans += f[!fu][x], x -= low(x);
		
		if(w != 0) {
			x = 0;
			for(int l = 1, r = n; l <= r; ) {
				int m = l + r >> 1;
				if(ti2[c[m]] >= nt)
					x = m, l = m + 1; else r = m - 1;
			}
			while(x) ans += g[fu][x], x -= low(x);
		}
		
		nt = ti[i];
		x = 0;
		for(int l = 1, r = n; l <= r; ) {
			int m = l + r >> 1;
			if(ti[b[m]] >= nt)
				x = m, l = m + 1; else r = m - 1;
		}
		while(x) ans += f[fu][x], x -= low(x);
		
		x = nb[i];
		while(x <= n) f[fu][x] ++, x += low(x);
		
		x = nc[i];
		while(x <= n) g[fu][x] ++, x += low(x);
	}
	printf("%I64d", ans);
}