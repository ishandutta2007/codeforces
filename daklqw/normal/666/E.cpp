#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>

const int MAXN = 100010;
struct PII {
	int first, second;
	explicit PII(int f = 0, int s = 0) { first = f, second = s; }
	inline bool operator < (const PII & b) const {
		return first == b.first ? second > b.second : first < b.first;
	}
} ;

int n, Q, t1, t2, t3, t4;
namespace SGT {
	const int MAXNODE = MAXN * 160;
	int ls[MAXNODE], rs[MAXNODE], tot, rt[MAXN];
	PII tree[MAXNODE];
	void insert(int & u, int l, int r, int tar) {
		if (!u) u = ++tot;
		if (l == r) return static_cast<void> (tree[u].second = l, ++tree[u].first);
		int mid = l + r >> 1;
		if (tar <= mid) insert(ls[u], l, mid, tar);
		else insert(rs[u], mid + 1, r, tar);
		tree[u] = std::max(tree[ls[u]], tree[rs[u]]);
	}
	int merge(int x, int y, int l, int r) {
		if (!x || !y) return x | y;
		int now = ++tot;
		if (l == r) {
			tree[now] = tree[x];
			tree[now].first += tree[y].first;
			return now;
		}
		const int mid = l + r >> 1;
		ls[now] = merge(ls[x], ls[y], l, mid);
		rs[now] = merge(rs[x], rs[y], mid + 1, r);
		tree[now] = std::max(tree[ls[now]], tree[rs[now]]);
		return now;
	}
	PII query(int u, int l, int r, int L, int R) {
		if (!u) return PII();
		if (L <= l && r <= R) return tree[u];
		int mid = l + r >> 1; PII res;
		if (L <= mid) res = std::max(res, query(ls[u], l, mid, L, R));
		if (mid < R) res = std::max(res, query(rs[u], mid + 1, r, L, R));
		return res;
	}
}
int nxt[MAXN][26], fail[MAXN], tot, lst, R[MAXN], v, p, now, t, fa[17][MAXN];
void insert(int x, int bel) {
	R[now = ++tot] = R[p = lst] + 1; lst = now;
	SGT::insert(SGT::rt[now], 1, n, bel);
	for (; p && !nxt[p][x]; p = fail[p]) nxt[p][x] = now;
	if (!p) fail[now] = 1;
	else {
		t = nxt[p][x];
		if (R[t] == R[p] + 1) fail[now] = t;
		else {
			R[v = ++tot] = R[p] + 1;
			memcpy(nxt[v], nxt[t], sizeof(int) * 26);
			fail[v] = fail[t]; fail[t] = fail[now] = v;
			for (; p && nxt[p][x] == t; p = fail[p]) nxt[p][x] = v;
		}
	}
}
int at[MAXN * 10], L, Lx[MAXN * 10];
char buf[MAXN], * cur, qry[MAXN * 10];
namespace G {
	int head[MAXN], nxt[MAXN], to[MAXN], t0t;
	inline void addedge(int b, int e) {
		nxt[++t0t] = head[b]; head[b] = t0t; to[t0t] = e;
	}
	void dfs(int u) {
		for (int i = head[u]; i; i = nxt[i]) {
			fa[0][to[i]] = u;
			dfs(to[i]);
			SGT::rt[u] = SGT::merge(SGT::rt[u], SGT::rt[to[i]], 1, n);
		}
	}
}
int main() {
	tot = 1;
	scanf("%s%d", qry + 1, &n);
	L = strlen(qry + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", cur = buf); lst = 1;
		while (*cur) insert(*cur++ - 'a', i);
	}
	for (int i = 2; i <= tot; ++i) G::addedge(fail[i], i); G::dfs(1);
	assert(SGT::tot <= SGT::MAXNODE);
	for (int i = 1; i != 17; ++i)
		for (int j = 1; j <= tot; ++j)
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
	int now = 1;
	int nowl = 0;
	for (int i = 1; i <= L; ++i) {
		const int ch = qry[i] - 'a';
		if (nxt[now][ch]) now = nxt[now][ch], ++nowl;
		else {
			while (now && !nxt[now][ch]) now = fail[now];
			if (!now) now = 1, nowl = 0;
			else nowl = R[now] + 1, now = nxt[now][ch];
		}
		at[i] = now; Lx[i] = nowl;
	}
	scanf("%d", &Q);
	while (Q --> 0) {
		scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
		const int L = t4 - t3 + 1;
		if (L > Lx[t4]) {
			printf("%d 0\n", t1);
			continue;
		}
		int u = at[t4];
		for (int i = 16; ~i; --i)
			if (R[fa[i][u]] >= L)
				u = fa[i][u];
		PII ret = SGT::query(SGT::rt[u], 1, n, t1, t2);
		if (ret.first == 0) ret.second = t1;
		printf("%d %d\n", ret.second, ret.first);
	}
	return 0;
}