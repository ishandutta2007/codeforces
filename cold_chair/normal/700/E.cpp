#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 4e5 + 5;

int n;
char s[N];

#define i0 t[i].l
#define i1 t[i].r
struct tree {
	int l, r;
} t[N * 60];
int tot, g[N], pl, pr, px;

void dg(int &i, int x, int y) {
	if(!i) i = ++ tot;
	if(x == y) return;
	int m = x + y >> 1;
	if(pl <= m) dg(i0, x, m); else dg(i1, m + 1, y);
}

void merge(int &i, int x, int y) {
	if(!x || !y) {
		i = x + y; return;
	}
	i = ++ tot;
	merge(i0, t[x].l, t[y].l);
	merge(i1, t[x].r, t[y].r);
}

void qu(int i, int x, int y) {
	if(!i) return;
	if(y < pl || x > pr) return;
	if(x == y) {
		px = x; return;
	}
	int m = x + y >> 1;
	qu(i1, m + 1, y); if(!px) qu(i0, x, m);
}

int f[N], pos[N];

struct sam {
	int son[N][26], fa[N], dep[N], tot, la, ed[N];
	void build() {
		tot = la = 1;
	}
	#define push(x) dep[++ tot] = x
	int m;
	void add(int c) {
		m ++;
		int p = la;
		push(dep[p] + 1); int np = tot;
		for(; p && !son[p][c]; p = fa[p]) son[p][c] = np;
		if(!p) fa[np] = 1; else {
			int q = son[p][c];
			if(dep[p] + 1 < dep[q]) {
				 push(dep[p] + 1); int nq = tot;
				 memcpy(son[nq], son[q], sizeof son[q]);
				 fa[nq] = fa[q]; fa[q] = fa[np] = nq;
				 for(; son[p][c] == q; p = fa[p]) son[p][c] = nq;
			} else fa[np] = q;
		}
		la = np;
		pl = pr = m; dg(g[np], 1, n);
		ed[np] = m;
	}
	int d[N], d0, r[N];
	void turpo() {
		fo(i, 1, tot) r[fa[i]] ++;
		fo(i, 1, tot) if(!r[i]) d[++ d0] = i;
		for(int i = 1; i <= d0; i ++) {
			int x = d[i];
			if(fa[x]) {
				if(!(-- r[fa[x]])) d[++ d0] = fa[x];
				merge(g[fa[x]], g[fa[x]], g[x]);
				ed[fa[x]] = max(ed[fa[x]], ed[x]);
			}
		}
		fd(i, d0, 1) {
			int x = d[i]; if(x == 1) continue;
			if(fa[x] == 1) {
				f[x] = 1;
				pos[x] = x;
				continue;
			}
			pl = 1, pr = ed[x] - 1; px = 0;
			int y = pos[fa[x]];
			qu(g[y], 1, n);
			if(px - dep[y] + 1 >= ed[x] - dep[x] + 1) f[x] = f[y] + 1, pos[x] = x; else f[x] = f[y], pos[x] = y;
		}
		int ans = 0;
		fo(i, 1, tot) ans = max(ans, f[i]);
		pp("%d\n", ans);
	}
} suf;

int main() {
	//freopen("a.in", "r", stdin);
	suf.build();
	scanf("%d", &n);
	scanf("%s", s + 1);
	fo(i, 1, n) {
		suf.add(s[i] - 'a');
	}
	suf.turpo();
}