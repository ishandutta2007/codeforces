#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int cipher = -1e9;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		int tag, Max, depth;
	} a[MAXN * 2];
	int root, size, n, depth[MAXN];
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
		a[root].depth = max(a[a[root].lc].depth, a[a[root].rc].depth);
	}
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].Max = -2e9;
		a[root].tag = cipher;
		if (l == r) {
			a[root].depth = depth[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x, int *y) {
		n = x, size = 0;
		for (int i = 1; i <= n; i++)
			depth[i] = 2 * y[i];
		build(root, 1, n);
	}
	void pushdown(int root) {
		if (a[root].tag != cipher && a[root].lc) {
			a[a[root].lc].Max = a[root].tag + a[a[root].lc].depth;
			a[a[root].lc].tag = a[root].tag;
			a[a[root].rc].Max = a[root].tag + a[a[root].rc].depth;
			a[a[root].rc].tag = a[root].tag;
			a[root].tag = cipher;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, int x) {
		if (l == ql && r == qr) {
			a[root].Max = x + a[root].depth;
			a[root].tag = x;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), x);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, x);
		update(root);
	}
	void modify(int l, int r, int x) {
		modify(root, 1, n, l, r, x);
	}
	int query(int root, int l, int r, int ql, int qr, int x) {
		pushdown(root);
		int mid = (l + r) / 2;
		if (l == ql && r == qr) {
			if (l == r) {
				if (a[root].Max > x) return l;
				else return l - 1;
			}
			if (a[a[root].rc].Max > x) return query(a[root].rc, mid + 1, r, mid + 1, r, x);
			else return query(a[root].lc, l, mid, l, mid, x);
		}
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr, x);
		if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr, x);
		int tans = query(a[root].rc, mid + 1, r, mid + 1, qr, x);
		if (tans == mid) return query(a[root].lc, l, mid, ql, mid, x);
		else return tans;
	}
	int query(int l, int r, int x) {
		return query(root, 1, n, l, r, x);
	}
} ST;
vector <int> a[MAXN], points[MAXN];
int y[MAXN], t[MAXN], p[MAXN], ans[MAXN], val[MAXN];
int n, m, depth[MAXN], size[MAXN], son[MAXN];
int timer, father[MAXN], dfn[MAXN], up[MAXN];
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	size[pos] = 1, son[pos] = 0;
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos);
			size[pos] += size[x];
			if (size[x] > size[son[pos]]) son[pos] = x;
		}
}
void efs(int pos, int fa, int from) {
	up[pos] = from;
	father[pos] = fa;
	dfn[pos] = ++timer;
	points[from].push_back(pos);
	if (son[pos]) efs(son[pos], pos, from);
	for (auto x : a[pos])
		if (x != son[pos] && x != fa)
			efs(x, pos, x);
}
bool cmp(int a, int b) {
	if (t[a] + depth[y[a]] == t[b] + depth[y[b]]) return y[a] < y[b];
	else return t[a] + depth[y[a]] < t[b] + depth[y[b]];
}
int main() {
	read(n), read(m);
	for (int i = 2; i <= n + 1; i++) {
		int x; read(x), x++;
		a[x].push_back(i);
	}
	dfs(1, 0);
	efs(1, 0, 1);
	for (int i = 1; i <= m; i++) {
		read(y[i]), y[i]++;
		read(t[i]), p[i] = i;
	}
	sort(p + 1, p + m + 1, cmp);
	static int tmp[MAXN];
	for (int i = 1; i <= n + 1; i++)
		tmp[dfn[i]] = depth[i];
	ST.init(n + 1, tmp);
	ST.modify(1, 1, 2e9);
	for (int i = 1; i <= m; i++) {
		int pos = y[p[i]], x = pos, res = 0;
		while (true) {
			int f = up[x];
			int tmp = ST.query(dfn[f], dfn[x], depth[pos] + t[p[i]]);
			if (tmp == dfn[f] - 1) res += dfn[x] - dfn[f] + 1;
			else {
				res += dfn[x] - tmp;
				break;
			}
			x = father[f];
		}
		x = pos;
		ans[p[i]] = t[p[i]] + 2 * res;
		int tres = res;
		while (tres) {
			int f = up[x];
			if (tres <= dfn[x] - dfn[f] + 1) {
				ST.modify(dfn[x] - tres + 1, dfn[x], t[p[i]] + 2 * res - depth[pos]);
				break;
			} else {
				tres -= dfn[x] - dfn[f] + 1;
				ST.modify(dfn[f], dfn[x], t[p[i]] + 2 * res - depth[pos]);
			}
			x = father[f];
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}