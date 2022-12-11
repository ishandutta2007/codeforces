#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 400010;
typedef long long LL;

namespace SAM {
	int nxt[MAXN][26], fail[MAXN], R[MAXN], now, tot, lst, p, v, t, at[MAXN];
	void insert(int x, int idx) {
		R[now = ++tot] = R[p = lst] + 1; at[idx] = lst = now;
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
}
int fa[19][MAXN], dep[MAXN], in[MAXN], out[MAXN];
inline int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int t = dep[x] - dep[y]; t; t -= t & -t) x = fa[__builtin_ctz(t)][x];
	for (int i = 18; ~i; --i) if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
	return x == y ? x : fa[0][x];
}
namespace G {
	int head[MAXN], nxt[MAXN], to[MAXN], tot;
	inline void addedge(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
	}
}
int txt;
void dfs1(int u) {
	in[u] = ++txt;
	for (int i = G::head[u]; i; i = G::nxt[i]) {
		dep[G::to[i]] = dep[u] + 1;
		dfs1(G::to[i]);
	}
	out[u] = txt;
}
inline bool cmp(int a, int b) { return in[a] < in[b]; }
int n, Q, ca, cb, la[MAXN], lb[MAXN], li[MAXN << 1], bak, st[MAXN], top;
int va[MAXN], vb[MAXN];
LL ans = 0;
void dfs2(int u) {
	ans += SAM::R[u] * static_cast<LL> (va[u]) * vb[u];
	for (int i = G::head[u]; i; i = G::nxt[i]) {
		dfs2(G::to[i]);
		ans += SAM::R[u] * (static_cast<LL> (va[u]) * vb[G::to[i]] + static_cast<LL> (vb[u]) * va[G::to[i]]);
		va[u] += va[G::to[i]]; vb[u] += vb[G::to[i]];
	}
}
char buf[MAXN];
int main() {
	SAM::lst = SAM::tot = 1;
	scanf("%d%d%s", &n, &Q, buf + 1);
	for (int i = n; i; --i) SAM::insert(buf[i] - 'a', i);
	for (int i = 1; i <= SAM::tot; ++i) G::addedge(fa[0][i] = SAM::fail[i], i);
	dfs1(1);
	for (int i = 1; i <= SAM::tot; ++i) G::head[i] = 0;
	for (int i = 1; i != 19; ++i)
		for (int j = 1; j <= SAM::tot; ++j)
			fa[i][j] = fa[i - 1][fa[i - 1][j]];
	while (Q --> 0) {
		G::tot = 0; bak = 0;
		scanf("%d%d", &ca, &cb);
		for (int i = 1; i <= ca; ++i) scanf("%d", la + i), ++va[li[++bak] = SAM::at[la[i]]];
		for (int i = 1; i <= cb; ++i) scanf("%d", lb + i), ++vb[li[++bak] = SAM::at[lb[i]]];
		li[++bak] = 1;
		std::sort(li + 1, li + 1 + bak, cmp);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		for (int i = bak; i > 1; --i) li[++bak] = LCA(li[i], li[i - 1]);
		std::sort(li + 1, li + 1 + bak, cmp);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		st[top = 1] = 1;
		for (int i = 2; i <= bak; ++i) {
			while (out[st[top]] < in[li[i]]) --top;
			G::addedge(st[top], li[i]);
			st[++top] = li[i];
		}
		ans = 0; dfs2(1);
		printf("%lld\n", ans);
		for (int i = 1; i <= bak; ++i) va[li[i]] = vb[li[i]] = G::head[li[i]] = 0;
	}
	return 0;
}