#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
double getp() {
	double x, y;
	read(x), read(y);
	return x / y;
}
struct info {
	double LtoR;
	double RtoR;
};
info operator + (info a, info b) {
	info ans;
	ans.LtoR = a.LtoR * b.LtoR / (1.0 - (1.0 - b.LtoR) * a.RtoR);
	ans.RtoR = b.RtoR + (1.0 - b.RtoR) * a.RtoR * b.LtoR / (1.0 - (1.0 - b.LtoR) * a.RtoR);
	return ans;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		info ans;
	} a[MAXN * 2];
	int n, size, root;
	void update(int root) {
		a[root].ans = a[a[root].lc].ans + a[a[root].rc].ans;
	}
	void build(int &root, int l, int r, double *val) {
		root = ++size;
		if (l == r) {
			a[root].ans = (info) {val[l], val[l]};
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, val);
		build(a[root].rc, mid + 1, r, val);
		update(root);
	}
	void init(int x, double *val) {
		n = x;
		root = size = 0;
		build(root, 1, n, val);
	}
	void modify(int root, int l, int r, int pos, double val) {
		if (l == r) {
			a[root].ans = (info) {val, val};
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val);
		else modify(a[root].rc, mid + 1, r, pos, val);
		update(root);
	}
	void modify(int pos, double val) {
		modify(root, 1, n, pos, val);
	}
	info query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].ans;
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return query(a[root].lc, l, mid, ql, mid) + query(a[root].rc, mid + 1, r, mid + 1, qr);
	}
	double query(int l, int r) {
		info ans = query(root, 1, n, l, r);
		return ans.LtoR;
	}
} ST;
int n, q; double a[MAXN];
int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++)
		a[i] = getp();
	ST.init(n, a);
	for (int i = 1; i <= q; i++) {
		int opt, l, r, x; read(opt);
		if (opt == 1) {
			read(x);
			a[x] = getp();
			ST.modify(x, a[x]);
		} else {
			read(l), read(r);
			printf("%.10lf\n", ST.query(l, r));
		}
	}
	return 0;
}