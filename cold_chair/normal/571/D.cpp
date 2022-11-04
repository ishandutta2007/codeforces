#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e6 + 5;

int n, m;
char str[10];
struct ask {
	char tp;
	int x, y;
} b[N];

#define V vector<int>
#define pb push_back
#define si size()

V e[N];
int tot, f[N], r[N], mt;

int F(int x) {
	return f[x] == x ? x : (f[x] = F(f[x]));
}

int p[N], q[N], p0;
void dg(int x) {
	p[x] = ++ p0;
	ff(j, 0, e[x].si) dg(e[x][j]);
	q[x] = p0;
}

ll t[N * 4], lz[N * 4];
int pl, pr; ll px;
#define i0 i + i
#define i1 i + i + 1
namespace t1 {
void fz(int i, int x) {
	t[i] = lz[i] = x;
}
void down(int i) {
	if(lz[i]) fz(i0, lz[i]), fz(i1, lz[i]), lz[i] = 0;
}
void add(int i, int x, int y) {
	if(y < pl || x > pr) return;
	if(x >= pl && y <= pr) {
		fz(i, px); return;
	}
	int m = x + y >> 1; down(i);
	add(i0, x, m); add(i1, m + 1, y);
}
void ft(int i, int x, int y) {
	if(x == y) {
		px = t[i]; return;
	}
	int m = x + y >> 1; down(i);
	if(pl <= m) ft(i0, x, m); else ft(i1, m + 1, y);
}
}

V ak[N];

void work_time() {
	fo(i, 1, 2 * n) f[i] = i; tot = n;
	fo(i, 1, m) if(b[i].tp == 'M') {
		int x = F(b[i].x), y = F(b[i].y);
		if(x != y) {
			tot ++;
			f[x] = tot;
			f[y] = tot;
			e[tot].pb(x); e[tot].pb(y);
			r[x] ++, r[y] ++;
		}
	}
	mt = tot;
	fo(i, 1, mt) if(!r[i])
		dg(i);
	fo(i, 1, 2 * n) f[i] = i; tot = n;
	fo(i, 1, m) {
		if(b[i].tp == 'M') {
			int x = F(b[i].x), y = F(b[i].y);
			if(x != y) {
				tot ++;
				f[x] = tot; f[y] = tot;
			}
		} else
		if(b[i].tp == 'Z') {
			int x = F(b[i].x);
			pl = p[x], pr = q[x], px = i;
			t1 :: add(1, 1, mt);
			//pp("%d %d %d\n", pl, pr, px);
		} else
		if(b[i].tp == 'Q') {
			pl = pr = p[b[i].x]; px = 0;
			t1 :: ft(1, 1, mt);
			ak[px].pb(i);
		}
	}
}

ll ans[N];

void dfs(int x) {
	p[x] = ++ p0;
	ff(j, 0, e[x].si) dfs(e[x][j]);
	q[x] = p0;
}

ll siz[N];

namespace t2 {
	void jia(int i, ll x) {
		t[i] += x, lz[i] += x;
	}
	void down(int i) {
		if(lz[i]) {
			jia(i0, lz[i]), jia(i1, lz[i]);
			lz[i] = 0;
		}
	}
	void add(int i, int x, int y) {
		if(y < pl || x > pr) return;
		if(x >= pl && y <= pr) {
			jia(i, px); return;
		}
		int m = x + y >> 1; down(i);
		add(i0, x, m); add(i1, m + 1, y);
	}
	void ft(int i, int x, int y) {
		if(x == y) {
			px = t[i]; return;
		}
		int m = x + y >> 1; down(i);
		if(pl <= m) ft(i0, x, m); else ft(i1, m + 1, y);
	}
}

void work_ans() {
	fo(i, 1, 2 * n) f[i] = i, r[i] = 0, e[i].clear(); tot = n;
	fo(i, 1, m) {
		if(b[i].tp == 'U') {
			int x = F(b[i].x), y = F(b[i].y);
			if(x != y) {
				tot ++;
				f[x] = tot, f[y] = tot;
				r[x] ++, r[y] ++;
				e[tot].pb(x), e[tot].pb(y);
			}
		}
	}
	mt = tot; p0 = 0;
	fo(i, 1, mt) if(!r[i]) dfs(i);
	fo(i, 1, n) siz[i] = 1;
	fo(i, 1, 2 * n) f[i] = i; tot = n;
	fo(i, 1, mt * 4) t[i] = lz[i] = 0;
	fo(i, 1, m) {
		if(b[i].tp == 'U') {
			int x = F(b[i].x), y =  F(b[i].y);
			if(x != y) {
				tot ++;
				f[x] = tot, f[y] = tot;
				siz[tot] = siz[x] + siz[y];
			}
		} else
		if(b[i].tp == 'A') {
			int x = F(b[i].x);
			pl = p[x], pr = q[x]; px = siz[x];
			t2 :: add(1, 1, mt);
		} else
		if(b[i].tp == 'Q') {
			pl = pr = p[b[i].x]; px = 0;
			t2 :: ft(1, 1, mt);
			ans[i] += px;
			pp("%lld\n", ans[i]);
		}
		ff(j, 0, ak[i].si) {
			int y = ak[i][j];
			pl = pr = p[b[y].x], px = 0;
			t2 :: ft(1, 1, mt);
			ans[y] -= px;
		}
	}
}

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	tot = n;
	fo(i, 1, m) {
		scanf("%s", str);
		b[i].tp = str[0];
		if(b[i].tp == 'U' || b[i].tp == 'M') {
			scanf("%d %d", &b[i].x, &b[i].y);
		} else scanf("%d", &b[i].x);
	}
	work_time();
	work_ans();
}