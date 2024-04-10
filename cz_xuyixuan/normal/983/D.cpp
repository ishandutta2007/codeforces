#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXP = 400005;
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
struct Heap {
	priority_queue <int> Main, Delt;
	void push(int x) {Main.push(x); }
	void delt(int x) {Delt.push(x); }
	int query() {
		while (!Delt.empty() && Main.top() == Delt.top()) {
			Main.pop();
			Delt.pop();
		}
		if (Main.empty()) return -1;
		else return Main.top();
	}
};
struct SegmentTree {
	struct Node {
		Heap heap;
		int Max, Min, lc, rc;
	} a[MAXP];
	int n, root, size;
	bool ans[MAXN];
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].Max = -1;
		a[root].Min = 0;
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
		int col = a[root].heap.query();
		if (a[root].lc == 0) {
			if (col != -1 && !ans[col]) a[root].Max = col;
			else a[root].Max = -1;
			if (col != -1) a[root].Min = col;
			else a[root].Min = 0;
		} else {
			int childmax = max(a[a[root].lc].Max, a[a[root].rc].Max);
			int childmin = min(a[a[root].lc].Min, a[a[root].rc].Min);
			if (col != -1 && col > childmax) {
				if (ans[col] || col < childmin) a[root].Max = -1;
				else a[root].Max = col;
			} else a[root].Max = childmax;
			if (col != -1) a[root].Min = max(col, childmin);
			else a[root].Min = childmin;
		}
	}
	void insert(int root, int l, int r, int ql, int qr, int val) {
		if (l == ql && r == qr) {
			a[root].heap.push(val);
			update(root);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) insert(a[root].lc, l, mid, ql, min(mid, qr), val);
		if (mid + 1 <= qr) insert(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, val);
		update(root);
	}
	void insert(int l, int r, int val) {
		insert(root, 1, n, l, r, val);
	}
	void delt(int root, int l, int r, int ql, int qr, int val) {
		if (l == ql && r == qr) {
			a[root].heap.delt(val);
			update(root);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) delt(a[root].lc, l, mid, ql, min(mid, qr), val);
		if (mid + 1 <= qr) delt(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, val);
		update(root);
	}
	void delt(int l, int r, int val) {
		delt(root, 1, n, l, r, val);
	}
	void maintain(int root, int l, int r, int tmp) {
		if (a[root].Max != tmp) return;
		if (l == r) {
			update(root);
			return;
		}
		int mid = (l + r) / 2;
		maintain(a[root].lc, l, mid, tmp);
		maintain(a[root].rc, mid + 1, r, tmp);
		update(root);
	}
	void maintain() {
		while (a[root].Max != -1) {
			int tmp = a[root].Max;
			ans[tmp] = true;
			maintain(root, 1, n, tmp);
		}
	}
	int query(int n) {
		int sum = 1;
		for (int i = 1; i <= n; i++)
			sum += ans[i];
		return sum;
	}
} ST;
vector <int> l[MAXN], r[MAXN], val[MAXN];
int n, xl[MAXN], xr[MAXN], yl[MAXN], yr[MAXN];
int xn, ym, top, tmp[MAXN];
int main() {
	read(n);
	top = 0;
	for (int i = 1; i <= n; i++) {
		read(xl[i]), read(yl[i]);
		read(xr[i]), read(yr[i]);
		tmp[++top] = xl[i];
		tmp[++top] = xr[i];
	}
	sort(tmp + 1, tmp + top + 1);
	xn = top = unique(tmp + 1, tmp + top + 1) - tmp - 1;
	for (int i = 1; i <= n; i++) {
		xl[i] = lower_bound(tmp + 1, tmp + top + 1, xl[i]) - tmp;
		xr[i] = lower_bound(tmp + 1, tmp + top + 1, xr[i]) - tmp;
	}
	top = 0;
	for (int i = 1; i <= n; i++) {
		tmp[++top] = yl[i];
		tmp[++top] = yr[i];
	}
	sort(tmp + 1, tmp + top + 1);
	ym = top = unique(tmp + 1, tmp + top + 1) - tmp - 1;
	for (int i = 1; i <= n; i++) {
		yl[i] = lower_bound(tmp + 1, tmp + top + 1, yl[i]) - tmp;
		yr[i] = lower_bound(tmp + 1, tmp + top + 1, yr[i]) - tmp;
	}
	ST.init(ym - 1);
	for (int i = 1; i <= n; i++) {
		l[xl[i]].push_back(yl[i]);
		r[xl[i]].push_back(yr[i] - 1);
		val[xl[i]].push_back(i);
		l[xr[i]].push_back(yl[i]);
		r[xr[i]].push_back(yr[i] - 1);
		val[xr[i]].push_back(-i);
	}
	for (int i = 1; i <= xn; i++) {
		for (unsigned j = 0; j < l[i].size(); j++)
			if (val[i][j] > 0) ST.insert(l[i][j], r[i][j], val[i][j]);
			else ST.delt(l[i][j], r[i][j], -val[i][j]);
		ST.maintain();
	}
	writeln(ST.query(n));
	return 0;
}