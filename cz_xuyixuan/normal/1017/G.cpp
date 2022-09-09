#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
struct info {int a, b; };
info operator + (info x, info y) {
	x.a += y.a;
	x.b += y.a;
	chkmax(x.b, y.b);
	return x;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		info ans;
		bool tag;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].ans = a[a[root].lc].ans + a[a[root].rc].ans;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].ans = (info) {-1, 0};
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 1, n);
	}
	void pushdown(int root, int l, int r) {
		if (a[root].tag) {
			int mid = (l + r) / 2;
			a[a[root].lc].ans = (info) {-(mid - l + 1), 0};
			a[a[root].lc].tag = true;
			a[a[root].rc].ans = (info) {-(r - mid), 0};
			a[a[root].rc].tag = true;
			a[root].tag = false;
		}
	}
	void inc(int root, int l, int r, int pos) {
		if (l == r) {
			a[root].ans.a++;
			a[root].ans.b++;
			return;
		}
		pushdown(root, l, r);
		int mid = (l + r) / 2;
		if (mid >= pos) inc(a[root].lc, l, mid, pos);
		else inc(a[root].rc, mid + 1, r, pos);
		update(root);
	}
	void inc(int pos) {
		inc(root, 1, n, pos);
	}
	void dec(int root, int l, int r, int pos, int delta) {
		if (l == r) {
			a[root].ans.a -= delta;
			a[root].ans.b -= delta;
			return;
		}
		pushdown(root, l, r);
		int mid = (l + r) / 2;
		if (mid >= pos) dec(a[root].lc, l, mid, pos, delta);
		else dec(a[root].rc, mid + 1, r, pos, delta);
		update(root);
	}
	void dec(int pos, int delta) {
		dec(root, 1, n, pos, delta);
	}
	info query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].ans;
		pushdown(root, l, r);
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return query(a[root].lc, l, mid, ql, mid) + query(a[root].rc, mid + 1, r, mid + 1, qr);
	}
	info query(int l, int r) {
		return query(root, 1, n, l, r);
	}
	void clear(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) {
			a[root].tag = true;
			a[root].ans = (info) {-(r - l + 1), 0};
			return;
		}
		pushdown(root, l, r);
		int mid = (l + r) / 2;
		if (mid >= ql) clear(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) clear(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		update(root);
	}
	void clear(int l, int r) {
		clear(root, 1, n, l, r);
	}
} ST;
int n, m;
int size[MAXN], depth[MAXN];
int timer, dfn[MAXN], rit[MAXN];
int son[MAXN], up[MAXN], father[MAXN];
vector <int> a[MAXN];
void dfs(int pos) {
	size[pos] = 1, son[pos] = 0;
	for (unsigned i = 0; i < a[pos].size(); i++) {
		int tmp = a[pos][i];
		depth[tmp] = depth[pos] + 1;
		father[tmp] = pos;
		dfs(tmp);
		size[pos] += size[tmp];
		if (size[tmp] > size[son[pos]]) son[pos] = tmp;
	}
}
void efs(int pos, int from) {
	dfn[pos] = ++timer;
	up[pos] = from;
	if (son[pos]) efs(son[pos], from);
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != son[pos]) efs(a[pos][i], a[pos][i]);
	rit[pos] = timer;
}
int query(int pos) {
	info ans = ST.query(dfn[up[pos]], dfn[pos]);
	pos = father[up[pos]];
	while (pos != 0) {
		ans = ST.query(dfn[up[pos]], dfn[pos]) + ans;
		pos = father[up[pos]];
	}
	return max(ans.a, ans.b);
}
void modify(int pos) {
	ST.dec(dfn[pos], query(pos));
	if (dfn[pos] != rit[pos]) ST.clear(dfn[pos] + 1, rit[pos]);
}
int main() {
	read(n), read(m);
	for (int i = 2; i <= n; i++) {
		int x; read(x);
		a[x].push_back(i);
	}
	dfs(1);
	efs(1, 1);
	ST.init(n);
	for (int i = 1; i <= m; i++) {
		int type, pos;
		read(type), read(pos);
		if (type == 1) ST.inc(dfn[pos]);
		if (type == 2) modify(pos);
		if (type == 3) {
			int tmp = query(pos);
			if (tmp != 0) printf("black\n");
			else printf("white\n");
		}
	}
	return 0;
}