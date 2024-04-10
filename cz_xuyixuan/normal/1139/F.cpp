#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXP = 1e7 + 5;
const long long INF = 4e9;
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
		int sum;
	} a[MAXP];
	int root, size, n;
	int gmid(int l, int r) {
		return (INF + l + INF + r) / 2 - INF;
	}
	void init(int x) {
		n = x;
		root = size = 0;
	}
	void add(int &root, int l, int r, int pos, int d) {
		if (root == 0) root = ++size;
		a[root].sum += d;
		if (l == r) return;
		int mid = gmid(l, r);
		if (mid >= pos) add(a[root].lc, l, mid, pos, d);
		else add(a[root].rc, mid + 1, r, pos, d);
	}
	void add(int pos, int d) {
		add(root, -n, n, pos, d);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (root == 0) return 0;
		if (l == ql && r == qr) return a[root].sum;
		int ans = 0, mid = gmid(l, r);
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	int query(int l, int r) {
		return query(root, -n, n, l, r);
	}
} ST[2];
int n, m, tot, p[MAXN], s[MAXN], b[MAXN], x[MAXN], y[MAXN], ans[MAXN];
struct event {int timer, x, y, type; } a[MAXN];
bool cmp(event a, event b) {
	if (a.timer == b.timer) return a.type < b.type;
	else return a.timer < b.timer;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(p[i]);
	for (int i = 1; i <= n; i++)
		read(s[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 1; i <= n; i++) {
		a[++tot] = (event) {p[i], b[i] + p[i], b[i] - p[i], -1};
		a[++tot] = (event) {s[i] + 1, b[i] + p[i], b[i] - p[i], -2};
	}
	for (int i = 1; i <= m; i++)
		read(x[i]);
	for (int i = 1; i <= m; i++)
		read(y[i]);
	for (int i = 1; i <= m; i++)
		a[++tot] = (event) {x[i], x[i] + y[i], y[i] - x[i], i};
	sort(a + 1, a + tot + 1, cmp);
	ST[0].init(2e9), ST[1].init(2e9);
	int cnt = 0;
	for (int i = 1; i <= tot; i++) {
		if (a[i].type == -1) {
			cnt++;
			ST[0].add(a[i].x, 1);
			ST[1].add(a[i].y, 1);
		} else if (a[i].type == -2) {
			cnt--;
			ST[0].add(a[i].x, -1);
			ST[1].add(a[i].y, -1);
		} else ans[a[i].type] = ST[0].query(-2e9, a[i].x) + ST[1].query(a[i].y, 2e9) - cnt;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}