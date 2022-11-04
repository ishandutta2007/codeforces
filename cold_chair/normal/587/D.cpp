#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1.6e6 + 5;

int n, m;
struct edge {
	int x, y, z, t;
} b[N];

#define V vector<int>
#define pb push_back
#define si size()

V e[N];

int fi[N], nt[N], to[N], tot = 1;

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fi[x] = tot;
}

int td, pr[N], sf[N];

int cmpe(int x, int y) {
	return b[x].z < b[y].z;
}

void build_graph() {
	td = m * 2;
	fo(i, 1, n) {
		fd(j, e[i].si - 1, 0) {
			int x = e[i][j];
			sf[j] = ++ td;
			if(j < e[i].si - 1) link(sf[j], sf[j + 1]);
			link(sf[j], 2 * x);
		}
		ff(j, 0, e[i].si) {
			int x = e[i][j];
			pr[j] = ++ td;
			if(j > 0) link(pr[j], pr[j - 1]);
			link(pr[j], 2 * x);
			if(j > 0) link(2 * x - 1, pr[j - 1]);
			if(j < e[i].si - 1) link(2 * x - 1, sf[j + 1]);
		}
		sort(e[i].begin(), e[i].end(), cmpe);
		ff(j, 1, e[i].si) {
			int x = e[i][j], y = e[i][j - 1];
			if(j > 1 && b[x].z == b[y].z && b[x].z == b[e[i][j - 2]].z) {
				pp("No\n"); exit(0);
			}
			if(b[x].z == b[y].z) {
				link(2 * x, 2 * y - 1);
				link(2 * y, 2 * x - 1);
			}
		}
	}
}

int ntot, nfi[N], ntd;
void save() {
	fo(i, 1, td) nfi[i] = fi[i];
	ntot = tot;
}
void cancel() {
	fo(i, 1, td) fi[i] = nfi[i];
	tot = ntot;
}
int dfn[N], low[N], dfn0;
int z[N], z0, bz[N], bl[N], bl0;
void dg(int x) {
	dfn[x] = low[x] = ++ dfn0;
	bz[x] = 1; z[++ z0] = x;
	for(int i = fi[x]; i; i = nt[i]) {
		int y = to[i];
		if(!dfn[y]) dg(y), low[x] = min(low[x], low[y]); else
			if(bz[y]) low[x] = min(low[x], dfn[y]);
	}
	if(low[x] >= dfn[x]) {
		++ bl0;
		do bz[z[z0]] = 0, bl[z[z0]] = bl0; while(z[z0 --] != x);
	}
}
int pd(int mi) {
	fo(i, 1, m) if(b[i].t > mi) {
		link(2 * i - 1, 2 * i);
	}
	fo(i, 1, td) dfn[i] = low[i] = 0;
	dfn0 = bl0 = 0;
	fo(i, 1, td) if(!dfn[i])
		dg(i);
	int ky = 1;
	fo(i, 1, m) if(bl[2 * i] == bl[2 * i - 1]) 
		ky = 0;
	cancel();
	return ky;
}

vector<int> w[N];
int cr[N], r[N], dl[N], d[N], d0;

void turpo() {
	d0 = 0;
	fo(i, 1, td) if(!r[i]) d[++ d0] = i;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		if(!cr[i]) {
			cr[i] = 1;
			cr[dl[i]] = 2;
		}
		ff(j, 0, w[x].si) {
			int y = w[x][j];
			if(!(-- r[y])) d[++ d0] = y;
		}
	}
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d %d %d %d", &b[i].x, &b[i].y, &b[i].z, &b[i].t);
		e[b[i].x].pb(i); e[b[i].y].pb(i);
	}
	build_graph();
	save();
	int ans = -1;
	{
		for(int l = 0, r = 1e9; l <= r; ) {
			int mi = l + r >> 1;
			if(pd(mi)) ans = mi, r = mi - 1; else l = mi + 1;
		}
	}
	if(ans == -1) {
		pp("No\n");
		return 0;
	}
	pp("Yes\n");
	fo(i, 1, m) if(b[i].t > ans) {
		link(2 * i - 1, 2 * i);
	}
	fo(i, 1, td) dfn[i] = low[i] = 0;
	dfn0 = bl0 = 0;
	fo(i, 1, td) if(!dfn[i])
		dg(i);
	fo(i, 1, td) {
		for(int j = fi[i]; j; j = nt[j]) {
			int x = bl[i], y = bl[to[j]];
			if(x != y) {
				w[y].pb(x); r[x] ++;
			}
		}
	}
	fo(i, 1, m) {
		int x = bl[2 * i], y = bl[2 * i - 1];
		dl[x] = y; dl[y] = x;
	}
	turpo();
	int ans2 = 0;
	fo(i, 1, m) if(cr[bl[2 * i - 1]] == 1)
		ans2 ++;
	pp("%d %d\n", ans, ans2);
	fo(i, 1, m) if(cr[bl[2 * i - 1]] == 1)
		pp("%d ", i); hh;
}