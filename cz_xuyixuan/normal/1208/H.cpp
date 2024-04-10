#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 1e9 + 7;
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
struct info {int r, b; };
// H Bigger -> Blue
// info.r -> At least H = info.r && a red son gives blue
// info.b -> At least H = info.b && a blue son gives blue
// info.r > info.b
info operator + (info a, info b) {
	info ans;
	ans.r = min(max(a.r, b.b), b.r);
	ans.b = min(max(a.b, b.b), b.r);
	return ans;
}
int n, q, h, c[MAXN]; vector <int> a[MAXN];
int father[MAXN], size[MAXN], son[MAXN];
int timer, dfn[MAXN], rit[MAXN], home[MAXN];
int down[MAXN], up[MAXN];
info red() {return (info) {INF, INF}; }
info blue() {return (info) {-INF, -INF}; }
struct SegmentTree {
	struct Node {
		int lc, rc;
		info sum;
	} a[MAXN * 2];
	int root, size, n;
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].sum = a[a[root].rc].sum + a[a[root].lc].sum;
	}
	void modify(int root, int l, int r, int pos, info val) {
		if (l == r) {
			a[root].sum = val;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val);
		else modify(a[root].rc, mid + 1, r, pos, val);
		update(root);
	}
	void modify(int pos, info val) {
		modify(root, 1, n, pos, val);
	}
	info query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return query(a[root].rc, mid + 1, r, mid + 1, qr) + query(a[root].lc, l, mid, ql, mid);
	}
	int query(int l, int r) {
		info ans = query(root, 1, n, l, r);
		assert(ans.r == ans.b);
		return ans.r;
	}
} ST;
void dfs(int pos, int fa) {
	size[pos] = 1;
	father[pos] = fa;
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos), size[pos] += size[x];
			if (size[x] > size[son[pos]]) son[pos] = x;
		}
}
map <int, int> light[MAXN];
info now[MAXN]; int value[MAXN];
int d[MAXN], cntr[MAXN], cntb[MAXN];
void efs(int pos, int fa, int from) {
	up[pos] = from;
	dfn[pos] = ++timer;
	home[timer] = pos;
	if (son[pos]) {
		d[pos]++;
		efs(son[pos], pos, from);
		down[pos] = down[son[pos]];
	} else down[pos] = pos;
	for (auto x : a[pos])
		if (x != fa && x != son[pos]) {
			efs(x, pos, x), d[pos]++;
		}
	rit[pos] = timer;
}
void updatenow(int pos) {
	while (d[pos] - 2 * (cntb[pos] + 1) > now[pos].b) {
		now[pos].b++;
		cntb[pos] += light[pos][now[pos].b];
	}
	while (d[pos] - 2 * (cntb[pos] + 1 - light[pos][now[pos].b]) <= now[pos].b - 1) {
		cntb[pos] -= light[pos][now[pos].b];
		now[pos].b--;
	}
	while (d[pos] - 2 * (cntr[pos]) > now[pos].r) {
		now[pos].r++;
		cntr[pos] += light[pos][now[pos].r];
	}
	while (d[pos] - 2 * (cntr[pos] - light[pos][now[pos].r]) <= now[pos].r - 1) {
		cntr[pos] -= light[pos][now[pos].r];
		now[pos].r--;
	}
}
void init(int pos, int fa) {
	if (son[pos]) init(son[pos], pos);
	else {
		if (c[pos] == 0) now[pos] = red();
		else now[pos] = blue();
		ST.modify(dfn[pos], now[pos]);
		return;
	}
	for (auto x : a[pos])
		if (x != fa && x != son[pos]) {
			init(x, pos);
			int res = ST.query(dfn[x], dfn[down[x]]);
			light[pos][res]++;
			if (res <= now[pos].b) cntb[pos]++;
			if (res <= now[pos].r) cntr[pos]++;
		}
	updatenow(pos);
	ST.modify(dfn[pos], now[pos]);
}
void modify(int pos) {
	pos = up[pos];
	while (pos != 1) {
		int f = father[pos];
		
		light[f][value[pos]]--;
		if (value[pos] <= now[f].b) cntb[f]--;
		if (value[pos] <= now[f].r) cntr[f]--;
		value[pos] = ST.query(dfn[pos], dfn[down[pos]]);
		light[f][value[pos]]++;
		if (value[pos] <= now[f].b) cntb[f]++;
		if (value[pos] <= now[f].r) cntr[f]++;
		
		updatenow(f);
		ST.modify(dfn[f], now[f]);
		pos = up[f];
	}
}
int main() {
	read(n), read(h);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		read(c[i]);
	dfs(1, 0);
	efs(1, 0, 1);
	ST.init(n);
	init(1, 0);
	for (int i = 1; i <= n; i++)
		if (up[i] == i) {
			value[i] = ST.query(dfn[i], dfn[down[i]]);
		}
	read(q);
	while (q--) {
		int opt, x; read(opt);
		if (opt == 1) {
			read(x);
			int res = ST.query(dfn[x], dfn[down[x]]);
			printf("%d\n", res <= -h);
		}
		if (opt == 2) {
			read(x), read(c[x]);
			if (c[x] == 1) now[x] = blue();
			else now[x] = red();
			ST.modify(dfn[x], now[x]);
			modify(x);
		}
		if (opt == 3) {
			read(h);
		}
	}
	return 0;
}