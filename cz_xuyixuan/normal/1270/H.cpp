#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 2e6 + 5;
const int INF  = 1e9 + 7;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		int Min, cnt, tag;
	} a[MAXM * 2];
	int n, root, size;
	void update(int root) {
		a[root].cnt = 0;
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
		if (a[a[root].lc].Min == a[root].Min) a[root].cnt += a[a[root].lc].cnt;
		if (a[a[root].rc].Min == a[root].Min) a[root].cnt += a[a[root].rc].cnt;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, size = root = 0;
		build(root, 0, n);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Min += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Min += a[root].tag;
			a[root].tag = 0;
		}
	}
	void inc(int root, int l, int r, int pos, int d) {
		if (l == r) {
			a[root].cnt += d;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= pos) inc(a[root].lc, l, mid, pos, d);
		else inc(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void inc(int x, int y) {
		inc(root, 0, n, x, y);
	}
	void add(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].Min += d;
			a[root].tag += d;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) add(a[root].lc, l, mid, ql, min(qr, mid), d);
		if (mid + 1 <= qr) add(a[root].rc, mid + 1, r, max(ql, mid + 1), qr, d);
		update(root);
	}
	void add(int l, int r, int d) {
		if (l > r) swap(l, r);
		add(root, 0, n, l, r, d);
	}
} ST;
int n, q, a[MAXN];
int main() {
	read(n), read(q);
	a[0] = 2e6 + 2, a[n + 1] = 0;
	for (int i = 1; i <= n; i++)
		read(a[i]), a[i] *= 2;
	ST.init(a[0]);
	for (int i = 1; i <= n; i++) {
		ST.inc(a[i] - 1, 1);
		ST.inc(a[i] + 1, 1);
	}
	for (int i = 1; i <= n + 1; i++)
		ST.add(a[i - 1], a[i], 1);
	while (q--) {
		int x, y; read(x), read(y);
		ST.inc(a[x] - 1, -1);
		ST.inc(a[x] + 1, -1);
		ST.add(a[x], a[x - 1], -1);
		ST.add(a[x], a[x + 1], -1);
		a[x] = y * 2;
		ST.inc(a[x] - 1, 1);
		ST.inc(a[x] + 1, 1);
		ST.add(a[x], a[x - 1], 1);
		ST.add(a[x], a[x + 1], 1);
		printf("%d\n", ST.a[ST.root].cnt / 2);
	}
	return 0;
}