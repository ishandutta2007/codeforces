#include <bits/stdc++.h>

const int MAXN = 100010;
const int MAXP = MAXN * 11;
int n, m, K, Q;
int val[MAXP], mn[MAXP], son[MAXP][2], fa[MAXP];
int xs[MAXP], ys[MAXP];
int gmin(int x, int y) { return val[x] < val[y] ? x : y; }
int get(int x, bool b = 1) { return son[fa[x]][b] == x; }
int isroot(int x) { return !(get(x, 0) || get(x, 1)); }
void update(int x) {
	mn[x] = x;
	if (int t = son[x][0]) mn[x] = gmin(mn[x], mn[t]);
	if (int t = son[x][1]) mn[x] = gmin(mn[x], mn[t]);
}
void rotate(int x) {
	int y = fa[x], z = fa[y]; bool b = get(x);
	if (!isroot(y)) son[z][get(y)] = x;
	son[y][b] = son[x][!b]; son[x][!b] = y;
	fa[y] = x, fa[x] = z; if (int t = son[y][b]) fa[t] = y;
	update(y);
}
int tag[MAXP];
void mkrev(int x) { tag[x] ^= 1, std::swap(son[x][0], son[x][1]); }
void pushdown(int x) {
	if (int & v = tag[x]) {
		if (son[x][0]) mkrev(son[x][0]);
		if (son[x][1]) mkrev(son[x][1]);
		v = 0;
	}
}
void splay(int x) {
	static int st[MAXP], top;
	st[top = 1] = x;
	for (int y = x; !isroot(y); st[++top] = y = fa[y]) ;
	while (top) pushdown(st[top--]);
	for (; !isroot(x); rotate(x)) if (!isroot(fa[x]))
		rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
	update(x);
}
void access(int x) {
	for (int t = 0; x; son[x][1] = t, update(x), t = x, x = fa[x]) splay(x);
}
void mkroot(int x) {
	access(x); splay(x); mkrev(x);
}
void split(int x, int y) {
	mkroot(x); access(y); splay(y);
}
void link(int x, int y) {
	mkroot(x); fa[x] = y;
}
void cut(int x, int y) {
	split(x, y); son[y][0] = fa[x] = 0; update(y);
}
bool conn(int x, int y) {
	split(x, y);
	while (true) {
		pushdown(y);
		if (!son[y][0]) break;
		y = son[y][0];
	}
	splay(y);
	return y == x;
}
std::vector<int> hav[MAXN], qs[MAXN];
int ls[MAXN], tr[MAXN], ansl[MAXN];
void add(int x, int v) { for (; x; x &= x - 1) tr[x] += v; }
int qry(int x) {
	int r = 0; for (; x <= n; x += x & -x) r += tr[x]; return r;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K >> m;
	for (int i = 1, b, e; i <= m; ++i) {
		std::cin >> b >> e;
		if (b > e) std::swap(b, e);
		hav[e].push_back(b);
	}
	std::cin >> Q;
	for (int i = 1, r; i <= Q; ++i)
		std::cin >> ls[i] >> r, qs[r].push_back(i);
	for (int i = 1; i <= n; ++i) val[i] = n + 1, update(i);
	for (int i = 1; i <= n; ++i) {
		for (auto t : hav[i]) {
			static int idx = 0;
			int x = t, y = i, p = ++idx + n;
			if (conn(x, y)) {
				int t = mn[x];
				cut(xs[t], t), cut(ys[t], t);
				add(val[t], -1);
			}
			xs[p] = x, ys[p] = y, val[p] = x;
			update(p);
			link(x, p), link(y, p);
			add(val[p], 1);
		}
		for (auto t : qs[i])
			ansl[t] = i - ls[t] + 1 - qry(ls[t]);
	}
	for (int i = 1; i <= Q; ++i) std::cout << ansl[i] << '\n';
	return 0;
}