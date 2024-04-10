#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;  

const int N = 1e5 + 5;

int n, x, y, z;
int fi[N], to[N * 2], nt[N * 2], v[N * 2], tot;

void link(int x, int y, int z) {
	nt[++ tot] = fi[x], to[tot] = y, v[tot] = z, fi[x] = tot;
}

int Q;
ll l;

int d[N], d0, bd[N];
ll dis[N];
void bfs(int st) {
	fo(i, 1, n) bd[i] = 0;
	d[d0 = 1] = st; bd[st] = 1; dis[st] = 0;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		for(int j = fi[x]; j; j = nt[j]) {
			int y = to[j];
			if(!bd[y]) bd[y] = 1, d[++ d0] = y, dis[y] = v[j] + dis[x];
		}
	}
}

int d1, d2, rt;

ll md[N];

int fa[N];
int p[N], q[N], p0;

int dep[N];

void dg(int x) {
	p[x] = ++ p0;
	dep[x] =dep[fa[x]] + 1;
	for(int i = fi[x]; i; i = nt[i]) if(to[i] != fa[x]) {
		fa[to[i]] = x;
		dg(to[i]);
	}
	q[x] = p0;
}

#define low(x) ((x) & -(x))
int f[N];

void add(int x, int y) {
	for(; x <= n; x += low(x)) f[x] += y;
}
int sum(int x) {
	int s = 0;
	for(; x; x -= low(x)) s += f[x];
	return s;
}

int cmp_d(int x, int y) {
	if(md[x] == md[y]) return dep[x] > dep[y];
	return md[x] > md[y];
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n - 1) {
		scanf("%d %d %d", &x, &y, &z);
		link(x, y, z); link(y, x, z);
	}

	bfs(1);
	d1 = 1;
	fo(i, 1, n) if(dis[i] > dis[d1]) d1 = i;
	bfs(d1);
	d2 = 1;
	fo(i, 1, n) if(dis[i] > dis[d2]) d2 = i;
	fo(i, 1, n) md[i] = dis[i];
	bfs(d2);
	fo(i, 1, n) md[i] = max(md[i], dis[i]);

	rt = 1;
	fo(i, 1, n) if(md[i] < md[rt]) rt = i;
	dg(rt);

	fo(i, 1, n) d[i] = i;
	sort(d + 1, d + d0 + 1, cmp_d);

	for(scanf("%d", &Q); Q; Q --) {
		scanf("%I64d", &l);
		int ls = 0;
		int ans = 0;
		memset(f, 0, sizeof f);
		fo(i, 1, n) {
			int x = d[i];
			add(p[x], 1);
			while(md[d[ls + 1]] > md[x] + l) {
				int y = d[++ ls];
				add(p[y], -1);
			}
			ans = max(ans, sum(q[x]) - sum(p[x] - 1));
		}
		pp("%d\n", ans);
	}
}