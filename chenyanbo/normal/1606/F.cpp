#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
 
#define N	200000
#define Q	200000
 
unsigned int Z;
 
void srand_() {
	struct timeval tv;
 
	gettimeofday(&tv, NULL);
	Z = tv.tv_sec ^ tv.tv_usec | 1;
}
 
int rand_() {
	return (Z *= 3) >> 1;
}
 
void append(int **ej, int *eo, int i, int j) {
	int o = eo[i]++;
 
	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}
 
int zz[1 + N], ll[1 + N], rr[1 + N], xx[1 + N], yy[1 + N], xx_[1 + N], yy_[1 + N], u_, l_, r_;
 
int node(int x, int y) {
	static int _ = 1;
 
	zz[_] = rand_();
	xx_[_] = xx[_] = x, yy_[_] = yy[_] = y;
	return _++;
}
 
void pul(int u) {
	int l = ll[u], r = rr[u];
 
	xx_[u] = xx[u] + xx_[l] + xx_[r], yy_[u] = yy[u] + yy_[l] + yy_[r];
}
 
long long cross(int x1, int y1, int x2, int y2) {
	return (long long) x1 * y2 - (long long) x2 * y1;
}
 
void split(int u, int x, int y) {
	long long c;
 
	if (u == 0) {
		u_ = l_ = r_ = 0;
		return;
	}
	c = cross(xx[u], yy[u], x, y);
	if (c < 0) {
		split(rr[u], x, y);
		rr[u] = l_, l_ = u;
	} else if (c > 0) {
		split(ll[u], x, y);
		ll[u] = r_, r_ = u;
	} else {
		u_ = u, l_ = ll[u], r_ = rr[u];
		ll[u] = rr[u] = 0;
	}
	pul(u);
}
 
int merge(int u, int v) {
	if (u == 0)
		return v;
	if (v == 0)
		return u;
	if (zz[u] < zz[v]) {
		rr[u] = merge(rr[u], v), pul(u);
		return u;
	} else {
		ll[v] = merge(u, ll[v]), pul(v);
		return v;
	}
}
 
int tr_add(int u, int v) {
	split(u, xx[v], yy[v]);
	xx[v] += xx[u_], yy[v] += yy[u_], pul(v);
	return merge(merge(l_, v), r_);
}
 
int tr_merge(int u, int v) {
	if (v) {
		u = tr_merge(u, ll[v]), u = tr_merge(u, rr[v]);
		ll[v] = rr[v] = 0, u = tr_add(u, v);
	}
	return u;
}
 
int tr_first(int u) {
	return ll[u] == 0 ? u : tr_first(ll[u]);
}
 
int tr_remove_first(int u) {
	if (ll[u] == 0)
		return rr[u];
	ll[u] = tr_remove_first(ll[u]), pul(u);
	return u;
}
 
int tr_add_(int u, int x, int y) {
	while (u) {
		int v = tr_first(u);
 
		if (cross(x, y, xx[v], yy[v]) >= 0)
			x += xx[v], y += yy[v], u = tr_remove_first(u);
		else
			break;
	}
	return tr_add(u, node(x, y));
}
 
int tr_query(int u, int c) {
	int x = 0, y = 0;
 
	while (u)
		if (yy[u] - (long long) xx[u] * c > 0)
			x += xx_[ll[u]] + xx[u], y += yy_[ll[u]] + yy[u], u = rr[u];
		else
			u = ll[u];
	return y - x * c;
}
 
int *ej[N], eo[N], *eh[N], eo_[N], cc[Q], ans[Q], tt[N], sz[N];
 
void dfs(int p, int i) {
	int o, j_, t, y;
 
	sz[i] = 1, j_ = -1;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];
 
		if (j != p) {
			dfs(i, j);
			if (j_ == -1 || sz[j_] < sz[j])
				j_ = j;
			sz[i] += sz[j];
		}
	}
	t = j_ == -1 ? 0 : tt[j_];
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];
 
		if (j != j_)
			t = tr_merge(t, tt[j]);
	}
	y = eo[i] - (p == -1 ? 0 : 1);
	for (o = eo_[i]; o--; ) {
		int h = eh[i][o];
 
		ans[h] = y + tr_query(t, cc[h]);
	}
	tt[i] = y == 0 ? 0 : tr_add_(t, 1 - 0, y - 1);
}
 
int main() {
	int n, q, h, i, j;
 
	srand_();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		ej[i] = (int *) malloc(2 * sizeof *ej[i]);
		eh[i] = (int *) malloc(2 * sizeof *eh[i]);
	}
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		append(ej, eo, i, j), append(ej, eo, j, i);
	}
	scanf("%d", &q);
	for (h = 0; h < q; h++) {
		scanf("%d%d", &i, &cc[h]), i--;
		append(eh, eo_, i, h);
	}
	dfs(-1, 0);
	for (h = 0; h < q; h++)
		printf("%d\n", ans[h]);
	return 0;
}