#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
#define db double
using namespace std;

const int N = 2e5 + 5;

int n;
db w[N];
int x, y; db z;

int fi[N], nt[N * 2], to[N * 2], tot = 1; db v[N * 2];
void link(int x, int y, db z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
	nt[++ tot] = fi[y], to[tot] = x, v[tot] = z, fi[y] = tot;
}

#define cmax(a, b) ((a) < (b) ? (a) = (b) : 0)
int siz[N], mx[N], G;
int bz[N];

void fg(int x) {
	bz[x] = 1;
	mx[x] = 0; siz[x] = 1;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i];
		if(!bz[y]) fg(y), siz[x] += siz[y], cmax(mx[x], siz[y]);
	}
	cmax(mx[x], siz[0] - siz[x]);
	if(mx[x] < mx[G]) G = x;
	bz[x] = 0;
}
db dis[N], d[N], d2[N], p[N], q[N]; int d0;
int l[N], r[N];
int bx[N];
void dfs(int x) {
	bx[x] = 1;
	d[++ d0] = dis[x], d2[d0] = w[x];
	l[x] = d0;
	for(int i = fi[x]; i; i = nt[i]) if(!bx[to[i]]) {
		int y = to[i];
		dis[y] = dis[x] + v[i];
		dfs(y);
	}
	r[x] = d0;
	bx[x] = 0;
}
db ans = 1e30; int ans2;
void calc(int x) {
	db sum = 0;
	fo(i, 1, d0) sum += pow(d[i], 1.5) * d2[i];
	if(sum < ans) ans = sum, ans2 = x;
}
void dg(int x) {
	fg(x);
	d0 = 0; dis[x] = 0; dfs(x);
	calc(x);
	p[0] = 0; fo(i, 1, d0) p[i] = p[i - 1] + pow(d[i] + 1, 1.5) * d2[i];
	q[d0 + 1] = 0; fd(i, d0, 1) q[i] = q[i + 1] + pow(d[i] + 1, 1.5) * d2[i];
	int cho = 0; db ms = 1e30;
	for(int i = fi[x]; i; i = nt[i]) if(!bz[to[i]]) {
		int y = to[i];
		db sum = p[l[y] - 1] + q[r[y] + 1];
		fo(j, l[y], r[y]) sum += pow(d[j] - 1, 1.5) * d2[j];
		if(sum < ms) cho = y, ms = sum;
	}
	bz[x] = 1;
	if(cho) {
		siz[0] = siz[cho], G = 0, fg(cho);
		dg(G);
	}
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lf", &w[i]);
	fo(i, 1, n - 1) {
		scanf("%d %d %lf", &x, &y, &z);
		link(x, y, z);
	}
	siz[0] = mx[0] = n, G = 0, fg(1), dg(G);
	pp("%d %.6lf\n", ans2, ans);
}