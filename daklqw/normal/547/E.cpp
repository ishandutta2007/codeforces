#include <bits/stdc++.h>

const int MAXN = 400010;
typedef std::vector<int> VI;
typedef long long LL;
int nxt[MAXN][26], R[MAXN], fail[MAXN], tot, lst;
void ins(int x) {
	static int now, p, v, t;
	R[now = ++tot] = R[p = lst] + 1; lst = now;
	for (; p && !nxt[p][x]; p = fail[p]) nxt[p][x] = now;
	if (!p) fail[now] = 1;
	else {
		t = nxt[p][x];
		if (R[t] == R[p] + 1) fail[now] = t;
		else {
			R[v = ++tot] = R[p] + 1;
			memcpy(nxt[v], nxt[t], 104);
			fail[v] = fail[t]; fail[t] = fail[now] = v;
			for (; p && nxt[p][x] == t; p = fail[p]) nxt[p][x] = v;
		}
	}
}
int n, Q;
VI li[MAXN >> 1];
int in[MAXN], out[MAXN], sz[MAXN], tree[MAXN];
int up[MAXN];
namespace G {
	int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
	int idx;
	void addedge(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
	}
	void dfs(int u) {
		if (!up[u]) up[u] = u;
		in[u] = ++idx;
		for (int i = head[u]; i; i = nxt[i]) {
			if (R[to[i]] == R[u]) up[to[i]] = up[u];
			dfs(to[i]);
		}
		out[u] = idx;
	}
}
LL ansl[MAXN * 2];
std::vector<std::pair<int, int> > qry[MAXN >> 1];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	tot = 1;
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i) {
		static char buf[MAXN >> 1];
		std::cin >> buf; int l = strlen(buf);
		lst = 1;
		for (int j = 0; j < l; ++j)
			ins(buf[j] - 'a'), li[i].push_back(lst);
	}
	for (int i = 2; i <= tot; ++i)
		G::addedge(fail[i], i);
	G::dfs(1);
	for (int i = 1, l, r, x; i <= Q; ++i) {
		std::cin >> l >> r >> x;
		qry[r].emplace_back(li[x].back(), i);
		qry[l - 1].emplace_back(-li[x].back(), i);
	}
	auto absx = [] (int x) { return x < 0 ? -x : x; };
	for (int i = 1; i <= n; ++i) {
		for (auto t : li[i])
			for (int x = in[up[t]]; x <= tot; x += x & -x) ++tree[x];
		for (auto r : qry[i]) {
			LL v = 0; int _t, t, id; std::tie(t, id) = r;
			_t = absx(t);
			for (int x = out[up[_t]]; x; x &= x - 1) v += tree[x];
			for (int x = in[up[_t]] - 1; x; x &= x - 1) v -= tree[x];
			ansl[id] += t / _t * v;
		}
	}
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}