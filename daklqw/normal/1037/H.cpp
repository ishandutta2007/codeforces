#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 400010
#define MAXNODE MAXN * 40
int ls[MAXNODE], rs[MAXNODE], t0t;
int build(int l, int r, int tar) {
	int now = ++t0t;
	if (l == r) return now;
	int mid = l + r >> 1;
	if (tar <= mid) ls[now] = build(l, mid, tar);
	else rs[now] = build(mid + 1, r, tar);
	return now;
}
int merge(int x, int y) {
	if (!x || !y) return x | y;
	int now = ++t0t;
	ls[now] = merge(ls[x], ls[y]);
	rs[now] = merge(rs[x], rs[y]);
	return now;
}
int query(int u, int l, int r, int L, int R) {
	if (!u || L > R) return 0;
	if (L <= l && r <= R) return 1;
	int mid = l + r >> 1, res = 0;
	if (L <= mid) res |= query(ls[u], l, mid, L, R);
	if (mid < R) res |= query(rs[u], mid + 1, r, L, R);
	return res;
}
void print(int x, int l, int r) {
	if (l == r) cout << l << " ";
	int mid = l + r >> 1;
	if (ls[x]) print(ls[x], l, mid);
	if (rs[x]) print(rs[x], mid + 1, r);
}
int nxt[MAXN][26], fail[MAXN], R[MAXN], tot, last, p, now, v, rt[MAXN], endpos[MAXN], t;
void insert(int x, int at) {
	R[now = ++tot] = R[p = last] + 1; endpos[last = now] = at;
	for (; p && !nxt[p][x]; p = fail[p]) nxt[p][x] = now;
	if (!p) fail[now] = 1;
	else {
		t = nxt[p][x];
		if (R[p] + 1 == R[t]) fail[now] = t;
		else {
			R[v = ++tot] = R[p] + 1;
			memcpy(nxt[v], nxt[t], sizeof(int) * 26);
			fail[v] = fail[t]; fail[t] = fail[now] = v;
			for (; p && nxt[p][x] == t; p = fail[p]) nxt[p][x] = v;
		}
	}
}
int Q, len, l, r, n, ansl, out;
char buf[MAXN];
bool chknxt(int x, int pos, int matched) {
	if (!nxt[x][pos]) return false;
	int p = nxt[x][pos];
	// cout << "QUERY " << x << " " << pos << " " << p << " " << matched << " " << l + matched << " " << r << endl;
	return query(rt[p], 1, n, l + matched, r);
}
bool dfs(int x, char * buf, int matched) {
	// cout << "DFS " << x << " " << *buf << " " << matched << endl;
	// cout << "nxt : "; for (int i = 0; i != 26; ++i) cout << nxt[x][i] << " "; cout << endl;
	if (*buf && chknxt(x, *buf - 'a', matched)) if (dfs(nxt[x][*buf - 'a'], buf + 1, matched + 1)) return true;
	for (int i = max((int)*buf - 'a' + 1, 0); i != 26; ++i)
		if (chknxt(x, i, matched)) {
			ansl = matched; out = i;
			return true;
		}
	// cout << "DFS " << x << " RETURNED WITH FALSE " << endl;
	return false;
}
int rk[MAXN], buc[MAXN];
int main() {
	tot = last = 1;
	scanf("%s%d", buf + 1, &Q);
	n = len = strlen(buf + 1);
	for (int i = 1; i <= len; ++i) insert(buf[i] - 'a', i);
	/*
	cout << endl;
	for (int i = 1; i <= tot; ++i) cout << R[i] << " "; cout << endl;
	for (int i = 1; i <= tot; ++i) cout << fail[i] << " "; cout << endl;
	for (int i = 1; i <= tot; ++i) cout << endpos[i] << " "; cout << endl;
	*/
	for (int i = 1; i <= tot; ++i) ++buc[R[i]];
	for (int i = 1; i <= len; ++i) buc[i] += buc[i - 1];
	for (int i = 1; i <= tot; ++i) rk[buc[R[i]]--] = i;
	for (int i = tot; i; --i) {
		int u = rk[i];
		if (endpos[u]) rt[u] = merge(rt[u], build(1, n, endpos[u]));
		if (fail[u]) rt[fail[u]] = merge(rt[fail[u]], rt[u]);
	}
	/*
	for (int i = 1; i <= tot; ++i) {
		cout << "TREE" << endl;
		print(rt[i], 1, n); putchar(10);
	}
	*/
	while (Q --> 0) {
		scanf("%d%d%s", &l, &r, buf + 1);
		ansl = -1; out = -1;
		if (dfs(1, buf + 1, 0)) {
			for (int i = 1; i <= ansl; ++i) putchar(buf[i]);
			if (~out) putchar(out + 'a');
			putchar(10);
		} else puts("-1");
	}

	return 0;
}