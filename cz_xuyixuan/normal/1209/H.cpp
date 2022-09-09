#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
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
		double tag, Min;
	} a[MAXN * 2];
	int n, root, size;
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
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
	}
	void pushdown(int root) {
		if (a[root].tag != 0) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Min += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Min += a[root].tag;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, double d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Min += d;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, double d) {
		modify(root, 1, n, l, r, d);
	}
	double query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Min;
		pushdown(root);
		int mid = (l + r) / 2; double ans = 1e18;
		if (mid >= ql) chkmin(ans, query(a[root].lc, l, mid, ql, min(mid, qr)));
		if (mid + 1 <= qr) chkmin(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	double query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
int n, m, p[MAXN];
double l[MAXN], r[MAXN];
double d[MAXN], v[MAXN], L;
int main() {
	read(m), read(L);
	double last = 0;
	for (int i = 1; i <= m; i++) {
		double l, r, x;
		scanf("%lf%lf%lf", &l, &r, &x);
		if (l - last >= 1e-8) {
			d[++n] = l - last;
			v[n] = 1;
		}
		d[++n] = r - l;
		v[n] = x + 1;
		last = r;
	}
	if (L - last >= 1e-8) {
		d[++n] = L - last;
		v[n] = 1;
	}
	ST.init(n);
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		if (v[i] == 1) {
			double tl = d[i] / (v[i] + 1), tr = d[i] / v[i];
			l[i] = d[i] - tr * v[i], r[i] = d[i] - tl * v[i], ans += tr;
		} else {
			double tl = d[i] / (v[i] + 1), tr = d[i] / (v[i] - 1);
			l[i] = d[i] - tr * v[i], r[i] = d[i] - tl * v[i], ans += tr;
		}
		ST.modify(i, n, -l[i]);
	}
	sort(p + 1, p + n + 1, [&] (int x, int y) {return v[x] < v[y]; } );
	for (int i = 1; i <= n; i++) {
		int pos = p[i];
		double delta = min(r[pos] - l[pos], ST.query(pos, n));
		ST.modify(pos, n, -delta);
		ans -= delta / v[pos];
	}
	printf("%.10lf\n", ans);
	return 0;
}