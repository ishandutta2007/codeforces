#include <bits/stdc++.h>

const int MAXN = 400010;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot = 1;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, m, xs[MAXN], ys[MAXN];
int st[MAXN], top, idx;
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
typedef std::vector<pi> vpi; vi hav[MAXN]; vpi es[MAXN];
int low[MAXN], dfn[MAXN], t0t;
int fa[MAXN * 2];
void tarjan(int u, int fa = 0) {
	low[u] = dfn[u] = ++t0t;
	st[++top] = u;
	for (int i = head[u]; i; i = nxt[i]) if (i / 2 != fa / 2) {
		if (!dfn[to[i]]) {
			tarjan(to[i], i);
			low[u] = std::min(low[u], low[to[i]]);
			if (dfn[u] <= low[to[i]]) {
				++idx; int v;
				do
					::fa[v = st[top--]] = idx + n, hav[idx].push_back(v);
				while (v != to[i]);
				::fa[idx + n] = u;
				hav[idx].push_back(u);
			}
		} else low[u] = std::min(low[u], dfn[to[i]]);
	}
}
inline bool cnn(int x, int y) { return fa[x] == y || fa[y] == x; }
bool judge(int x, int y, int z) {
	if (z <= n) return false;
	return cnn(x, z) && cnn(y, z);
}
int deg[MAXN], disa[MAXN], BE;
int ins[MAXN], ste[MAXN];
int vis[MAXN * 2];
bool findcir(int u) {
	if (ins[u]) {
		if (u == BE) return true;
		return false;
	}
	ins[st[++top] = u] = true;
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[i >> 1]) {
			vis[i >> 1] = true;
			ste[top] = i;
			if (findcir(to[i])) return true;
		}
	return --top, ins[u] = false;
}
int findpath(int u, int dep = 2) {
	vis[u] = dep;
	if (ins[u]) return u;
	for (int i = head[u]; i; i = nxt[i])
		if (!vis[to[i]])
			if (int t = findpath(to[i], dep + 1))
				return t;
	vis[u] = 0;
	return 0;
}
void solve(vi ps, vpi es) {
	memset(head, 0, n + 1 << 2); tot = 1;
	for (auto t : es) {
		int u, v; std::tie(u, v) = t;
		addedge(u, v);
		++deg[u], ++deg[v];
	}
	top = 0;
	findcir(BE = *ps.begin());
	memset(vis, 0, tot + 1 << 2);
	for (int i = 1; i <= top; ++i) disa[ste[i] >> 1] = true;
	int u, v;
	for (int i = 1; i <= top; ++i) if (deg[st[i]] >= 3) {
		u = st[i]; vis[u] = 1;
		for (int i = head[u]; i; i = nxt[i]) if (!disa[i >> 1])
			if (v = findpath(to[i])) break;
		break;
	}
	int atu = std::find(st + 1, st + 1 + top, u) - st;
	int atv = std::find(st + 1, st + 1 + top, v) - st;
	int la = 0;
	for (int i = atu; ; i == top ? i = 1 : ++i) {
		++la;
		if (i == atv) break;
	}
	std::cout << la << " ";
	for (int i = atu; ; i == top ? i = 1 : ++i) {
		std::cout << st[i] << (" \n" [i == atv]);
		if (i == atv) break;
	}
	std::cout << top + 2 - la << " ";
	for (int i = atu; ; i == 1 ? i = top : --i) {
		std::cout << st[i] << (" \n" [i == atv]);
		if (i == atv) break;
	}
	int ma = 0;
	for (auto t : ps) st[vis[t]] = t, ma = std::max(ma, vis[t]);
	std::cout << ma << " ";
	for (int i = 1; i <= ma; ++i)
		std::cout << st[i] << (" \n" [i == ma]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		std::cin >> xs[i] >> ys[i];
		addedge(xs[i], ys[i]);
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i])
		top = 0, tarjan(i);
	for (int i = 1; i <= m; ++i) {
		int tar = judge(xs[i], ys[i], fa[xs[i]]) ? fa[xs[i]] : fa[ys[i]];
		es[tar - n].emplace_back(xs[i], ys[i]);
	}
	for (int i = 1; i <= idx; ++i)
		if (es[i].size() > hav[i].size()) {
			std::cout << "YES" << std::endl;
			solve(hav[i], es[i]);
			return 0;
		}
	std::cout << "NO" << std::endl;
	return 0;
}