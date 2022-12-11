#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
inline LL pw(int x) { return (LL) x * x; }

int son[MAXN][2], fa[MAXN];
int get(int x, int b = 1) { return son[fa[x]][b] == x; }
int isroot(int x) { return !(get(x, 0) || get(x, 1)); }

int allv[MAXN];
struct info {
	LL a, b; // ans = ax + b
	int sz;
	friend info operator + (const info & lhs, const info & rhs) {
		info res;
		res.a = lhs.a + rhs.a;
		res.b = lhs.b + rhs.b + lhs.a * rhs.sz;
		res.sz = lhs.sz + rhs.sz;
		return res;
	}
} val[MAXN], vt[MAXN];
void add(info & x, const info & y, int co) {
	x.b += y.b * co, x.sz += y.sz * co;
	x.a += pw(y.sz) * co;
}
void update(int x) {
	val[x].sz = vt[x].sz + 1;
	val[x].a = val[x].sz * 2ll * allv[x];
	val[x].b = vt[x].b + (pw(val[x].sz) - vt[x].a) * allv[x];
	if (int t = son[x][0]) val[x] = val[t] + val[x];
	if (int t = son[x][1]) val[x] = val[x] + val[t];
}
void rotate(int x) {
	int y = fa[x], z = fa[y]; bool b = get(x);
	if (!isroot(y)) son[z][get(y)] = x;
	son[y][b] = son[x][!b], son[x][!b] = y;
	fa[x] = z, fa[y] = x; if (int t = son[y][b]) fa[t] = y;
	update(y);
}
void splay(int x) {
	for (; !isroot(x); rotate(x)) if (!isroot(fa[x]))
		rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
	update(x);
}
void access(int x) {
	int t = 0;
	while (x) {
		splay(x);
		if (int v = son[x][1])
			add(vt[x], val[v], 1);
		son[x][1] = t;
		add(vt[x], val[t], -1);
		update(x);
		t = x, x = fa[x];
	}
}
void link(int x, int y) {
	access(y); splay(y); splay(x);
	fa[x] = y;
	add(vt[y], val[x], 1);
	update(y);
}
void cut(int x) {
	access(x); splay(x);
	int y = son[x][0];
	fa[y] = son[x][0] = 0;
	update(x);
}
bool conn(int x, int y) {
	splay(y);
	while (son[y][0]) y = son[y][0];
	splay(y);
	return x == y;
}

int n;
void printans() {
	access(1);
	std::cout << (val[1].b / (double) n / n) << '\n';
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cout << std::fixed << std::setprecision(10);
	std::cin >> n;
	static int tf[MAXN];
	for (int i = 2; i <= n; ++i) std::cin >> tf[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> allv[i], update(i);
	for (int i = 2; i <= n; ++i) link(i, tf[i]);
	printans();
	int Q; std::cin >> Q;
	while (Q --> 0) {
		static char opt[10];
		int x, y;
		std::cin >> opt >> x >> y;
		if (*opt == 'V') {
			access(x); splay(x);
			allv[x] = y;
			update(x);
		} else {
			access(y); access(tf[x]);
			if (conn(x, y)) std::swap(x, y);
			cut(x); link(x, y); tf[x] = y;
		}
		printans();
	}
	return 0;
}