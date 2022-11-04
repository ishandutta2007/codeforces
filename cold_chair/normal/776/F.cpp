#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 8e5 + 5;

int n, m;
int x, y;
int tot = 1, fi[N], nt[N], to[N], fr[N];

void link(int x, int y) {
	nt[++ tot] = fi[x], to[tot] = y, fr[tot] = x, fi[x] = tot;
}

#define pii pair<int, int>
#define fs first
#define se second

int tra[N];

int bz[N], td;

vector<int> t[N];
#define pb push_back
#define si size()

int cmpt(int x, int y) { return x > y;}

void bfs(int x) {
	static int d[N], d0;
	int st = fr[x]; d[d0 = 1] = x;
	for(int i = 1; i <= d0; i ++) {
		int x = d[i];
		if(to[x] == st) break;
		d[++ d0] = tra[x];
	}
	td ++;
	fo(i, 1, d0) {
		bz[d[i]] = td;
		t[td].pb(to[d[i]]);
	}
	sort(t[td].begin(), t[td].end(), cmpt);
}

int p[N];

int cmpd(int x, int y) {
	ff(j, 0, t[x].si) {
		if(t[x][j] > t[y][j]) return 0;
		if(t[x][j] < t[y][j]) return 1;
	}
}

void lsp() {
	static int d[N];
	fo(i, 1, td) d[i] = i;
	sort(d + 1, d + td + 1, cmpd);
	fo(i, 1, td) p[d[i]] = i;
}

vector<int> e[N];

int cr[N];

namespace fz {
	int siz[N], bz[N], G, mx[N];
	
	void fg(int x) {
		bz[x] = 1;
		siz[x] = 1; mx[x] = 0;
		ff(_y, 0, e[x].si) {
			int y = e[x][_y]; if(bz[y]) continue;
			fg(y);
			siz[x] += siz[y];
			mx[x] = max(mx[x], siz[y]);
		}
		mx[x] = max(mx[x], siz[0] - siz[x]);
		if(mx[x] < mx[G]) G = x;
		bz[x] = 0;
	}
	
	void dg(int D, int x) {
		fg(x);
		cr[x] = D;
		bz[x] = 1;
		ff(_y, 0, e[x].si) {
			int y = e[x][_y]; if(bz[y]) continue;
			siz[0] = siz[y], G = 0, fg(y);
			dg(D + 1, G);
		}
	}
	void work() {
		siz[0] = mx[0] = td, G = 0, fg(1);
		dg(1, G);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		link(x, y); link(y, x);
	}
	fo(i, 1, n) {
		int j = i == n ? 1 : i + 1;
		link(i, j); link(j, i);
	}
	fo(i, 1, n) {
		static pii d[N]; static int d0 = 0;
		d0 = 0;
		for(int j = fi[i]; j; j = nt[j])
			d[++ d0] = pii(to[j], j);
		sort(d + 1, d + d0 + 1);
		fo(j, 1, d0) {
			int k = j == d0 ? d[1].se : d[j + 1].se;
			tra[d[j].se ^ 1] = k;
		}
	}
	fo(i, 2, tot) if(!bz[i]) {
		if(to[i] == fr[i] % n + 1) continue;
		bfs(i);
	}
	lsp();
	for(int i = 2; i <= tot; i += 2) {
		if(bz[i] && bz[i ^ 1]) {
			int x = p[bz[i]], y = p[bz[i ^ 1]];
			e[x].pb(y); e[y].pb(x);
		}
	}
	fz :: work();
	fo(i, 1, td) pp("%d ", cr[i]); hh;
}