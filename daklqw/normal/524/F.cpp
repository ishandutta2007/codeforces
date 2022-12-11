#include <bits/stdc++.h>

const int MAXN = 1e6 + 10;

char buf[MAXN];
int n;
int pre[MAXN], suc[MAXN];
inline int tr(int x) { return x > n ? x - n : x; }
const int MAXP = MAXN << 1;
int R[MAXP], nxt[MAXP][2], fail[MAXP];
int tot, lst, at[MAXN];
void extend(int x, int id) {
	static int p, v, t, now;
	R[now = ++tot] = R[p = lst] + 1; at[id] = lst = now;
	for (; p && !nxt[p][x]; p = fail[p]) nxt[p][x] = now;
	if (!p) fail[now] = 1;
	else {
		t = nxt[p][x];
		if (R[t] == R[p] + 1) fail[now] = t;
		else {
			R[v = ++tot] = R[p] + 1;
			memcpy(nxt[v], nxt[t], sizeof (nxt[0]));
			fail[v] = fail[t];
			fail[t] = fail[now] = v;
			for (; p && nxt[p][x] == t; p = fail[p])
				nxt[p][x] = v;
		}
	}
}
int head[MAXP], nt[MAXP];
int dep[MAXP], top[MAXP], son[MAXP], sz[MAXP];
void dfs(int u) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nt[i]) {
		dep[i] = dep[u] + 1;
		dfs(i);
		sz[u] += sz[i];
		if (sz[i] > sz[son[u]]) son[u] = i;
	}
}
void dfs2(int u) {
	if (son[u]) top[son[u]] = top[u], dfs2(son[u]);
	for (int i = head[u]; i; i = nt[i])
		if (i != son[u])
			top[i] = i, dfs2(i);
}
int LCP(int x, int y) {
	x = at[tr(x)], y = at[tr(y)];
	while (top[x] != top[y])
		dep[top[x]] > dep[top[y]] ? x = fail[top[x]] : y = fail[top[y]];
	return R[dep[x] < dep[y] ? x : y];
}
void build() {
	tot = lst = 1;
	for (int i = n; i; --i)
		extend(buf[i] == ')', i);
	for (int i = 2; i <= tot; ++i)
		nt[i] = head[fail[i]], head[fail[i]] = i;
	top[1] = 1;
	dfs(1); dfs2(1);
}
bool cmp(int x, int y) {
	int lcp = LCP(x, y);
	if (lcp + y == n + 1)
		lcp += LCP(x + lcp, 1);
	if (lcp >= n) return false;
	return buf[tr(x + lcp)] > buf[tr(y + lcp)];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf + 1;
	n = strlen(buf + 1);
	build();
	int ct = 0;
	for (int i = 1; i <= n; ++i)
		suc[i] = pre[i] = ct += buf[i] == '(' ? 1 : -1;
	for (int i = n - 1; ~i; --i)
		suc[i] = std::min(suc[i], suc[i + 1]);
	int best = -1;
	int pmin = 0;
	for (int i = 0; i <= n; ++i) {
		pmin = std::min(pmin, pre[i]);
		bool can = true;
		if (ct <= 0) {
			can &= suc[i + 1] - pre[i] - ct >= 0;
			can &= pmin + (pre[n] - pre[i]) - ct >= 0;
		}
		if (ct > 0) {
			can &= suc[i + 1] - pre[i] >= 0;
			can &= std::min(pmin, pre[i] - ct) + (pre[n] - pre[i]) >= 0;
		}
		if (can) {
			if (best == -1 || cmp(best, i + 1))
				best = i + 1;
		}
	}
	if (ct < 0)
		for (int i = 1; i <= std::abs(ct); ++i)
			std::cout << '(';
	for (int i = 0; i < n; ++i)
		std::cout << buf[tr(best + i)];
	if (ct > 0)
		for (int i = 1; i <= ct; ++i)
			std::cout << ')';
	std::cout << '\n';
	return 0;
}