#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;
const int M = 405, C = N / M + 5;

char s[N];
int n, q, op, x, y;
char t[N]; int len;

#define mem(a) memset(a, 0, sizeof a)

struct sam {
	int son[M * 2][26], fa[M * 2], dep[M * 2], ed[M * 2], tot, la;
	void build() {
		fo(i, 1, tot) {
			mem(son[i]);
			dep[i] = fa[i] = ed[i] = 0;
		}
		tot = la = 1;
	}
	void push(int v) {
		dep[++ tot] = v;
	}
	void add(int c) {
		int p = la; push(dep[p] + 1);
		int np = tot;
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
		ed[la] = 1;
	}
	int d[M * 2], d0, r[M * 2], f[M * 2];
	void dg(int x) {
		if(x == 1) d0 = 0;
		fo(i, 1, d0) putchar(d[i] + 'a'); hh;
		fo(j, 0, 25) if(son[x][j]) {
			d[++ d0] = j;
			dg(son[x][j]);
			d0 --;
		}
	}
	void work() {
		fo(i, 1, tot) r[i] = f[i] = 0;
		fo(i, 2, tot) r[fa[i]] ++;
		d0 = 0;
		fo(i, 1, tot) if(!r[i]) d[++ d0] = i;
		for(int i = 1; i <= tot - 1; i ++) {
			int x = d[i];
			if(!(-- r[fa[x]])) d[++ d0] = fa[x];
			f[x] += ed[x], f[fa[x]] += f[x];
		}
	}
	int qry() {
		int p = 1;
		fo(i, 1, len) p = son[p][t[i] - 'a'];
		return f[p];
	}
} a[C];

int id[N], id0, il[C], ir[C];

void build(int i) {
	a[i].build();
	fo(j, il[i], ir[i]) a[i].add(s[j] - 'a');
	a[i].work();
}

int nt[N];

void get_nt() {
	int x = 0;
	fo(i, 2, len) {
		while(x && t[x + 1] != t[i]) x = nt[x];
		x += (t[x + 1] == t[i]);
		nt[i] = x;
	}
}

int qry(int l, int r, int z) {
	if(z != -1) {
		r = min(r, z + len - 2);
		l = max(l, z - len);
	}
	int ans = 0;
	int x = 0;
	fo(i, l, r) {
		while(x && t[x + 1] != s[i]) x = nt[x];
		x += (t[x + 1] == s[i]);
		if(x == len) {
			if(z == -1) ans ++; else {
				if(i >= z && i - len + 1 < z) ans ++;
			}
		}
	}
	return ans;
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	fo(i, 1, n) {
		if(i % M == 1) il[++ id0] = i;
		id[i] = id0;
		ir[id0] = i;
	}
	fo(i, 1, id0) {
		build(i);
//		a[i].dg(1);
	}
	scanf("%d", &q);
	fo(ii, 1, q) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d", &x);
			scanf("%s", t + 1);
			len = strlen(t + 1);
			s[x] = t[1];
			build(id[x]);
		} else {
			scanf("%d %d", &x, &y);
			scanf("%s", t + 1);
			len = strlen(t + 1);
			int ans = 0;
			if(len > M) {
				get_nt();
				ans = qry(x, y, -1);
			} else {
				int l = id[x], r = id[y];
				fo(i, l + 1, r - 1) ans += a[i].qry();
				get_nt();
				if(id[x] != id[y]) {
					ans += qry(x, ir[id[x]], -1);
					ans += qry(il[id[y]], y, -1);
					fo(i, l + 1, r)	ans += qry((i - 1) == l ? x : il[i - 1], i == r ? y : ir[i], il[i]);
				} else {
					ans += qry(x, y, -1);
				}
			}
			pp("%d\n", ans);
		}
	}
}