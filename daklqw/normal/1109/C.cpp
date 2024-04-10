#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;

typedef std::vector<int> VI;
typedef long long LL;

struct info {
	LL sm, mi;
	friend info operator + (info a, info b) {
		a.mi = std::min(a.mi, b.mi + a.sm);
		a.sm += b.sm;
		return a;
	}
} tree[MAXN], val[MAXN];
int ls[MAXN], rs[MAXN], ds[MAXN];
int son[MAXN][2], fa[MAXN], idx;
int get(int x, int b = 1) { return son[fa[x]][b] == x; }
void update(int x) {
	tree[x] = tree[son[x][0]] + val[x] + tree[son[x][1]];
}
void rotate(int x) {
	int y = fa[x], z = fa[y]; bool b = get(x);
	if (z) son[z][get(y)] = x;
	son[y][b] = son[x][!b], son[x][!b] = y;
	fa[x] = z, fa[y] = x; if (int t = son[y][b]) fa[t] = y;
	update(y);
}

int rt;
void splay(int x, int to = 0) {
	if (!x) return ;
	for (; fa[x] != to; rotate(x)) if (fa[fa[x]] != to)
		rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
	update(x);
	if (to == 0) rt = x;
}

int lower_bound(int v, int up = 0) {
	int now = rt, res = 0, lst = 0;
	while (now) {
		lst = now;
		if (ls[now] <= v) res = now, now = son[now][1];
		else now = son[now][0];
	}
	splay(lst, up), splay(res, up);
	return res;
}

int leftmost(int x, int up = 0) {
	while (son[x][0]) x = son[x][0];
	splay(x, up);
	return x;
}
void calcval(int u) {
	val[u].sm = (LL) (rs[u] - ls[u]) * ds[u];
	val[u].mi = std::min(val[u].sm, 0ll);
	update(u);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cout << std::fixed << std::setprecision(8);
	int Q; std::cin >> Q;
	rt = idx = 1;
	ls[rt] = 1.5e9, rs[rt] = 1.5e9, ds[rt] = 0;
	++idx;
	ls[idx] = -1.5e9, rs[idx] = 1.5e9, ds[idx] = 0;
	fa[idx] = rt, son[rt][0] = idx;
	calcval(idx);
	calcval(rt);
	while (Q --> 0) {
		int opt, t, l, r; LL v;
		std::cin >> opt;
		if (opt == 1) {
			std::cin >> t >> v;
			int at = lower_bound(t), u = ++idx, L, R;
			ls[u] = t, ds[u] = v;
			rs[u] = rs[at], rs[at] = t;
			calcval(at);
			R = son[at][1], fa[R] = son[at][1] = 0;
			L = at;
			son[u][0] = L; fa[L] = u;
			son[u][1] = R; fa[R] = u;
			calcval(rt = u);
		} else if (opt == 2) {
			std::cin >> t;
			int at = lower_bound(t);
			int L = lower_bound(t - 1, at), R = leftmost(son[at][1], at);
			rs[L] = rs[at], calcval(L);
			fa[R] = 0; son[R][0] = L;
			fa[L] = R, update(rt = R);
		} else {
			std::cin >> l >> r >> v;
			if (!v) {
				std::cout << l << '\n';
				continue;
			}
			int R = lower_bound(r);
			R = leftmost(son[R][1]);
			int L = lower_bound(l - 1, R);
			int u = son[L][1], lst = 0, ans = 0;
			info pre = (info) {0ll, 0ll};
			while (u) {
				lst = u;
				info vn = pre + tree[son[u][0]] + val[u];
				if (vn.mi + v <= 0) ans = u, u = son[u][0];
				else pre = vn, u = son[u][1];
			}
			splay(lst, L);
			splay(u = ans, L);
			v += tree[son[u][0]].sm;
			if (ans == 0 || v + (LL) ds[u] * (r - ls[u]) > 0)
				std::cout << -1 << '\n';
			else
				std::cout << (-v / (double) ds[u] + ls[u]) << '\n';
		}
	}
	return 0;
}