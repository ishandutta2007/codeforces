#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long INF = 1e18;
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
		ll tag, Max;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].tag = 0;
		a[root].Max = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Max += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Max += a[root].tag;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, ll d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Max += d;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(root);
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, ll d) {
		modify(root, 1, n, l, r, d);
	}
	ll query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2; pushdown(root);
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return max(query(a[root].lc, l, mid, ql, mid), query(a[root].rc, mid + 1, r, mid + 1, qr));
	}
	ll query(int l, int r) {
		if (l > r) return 0;
		else return query(root, 1, n, l, r);
	}
} ST;
int n, m, p, r; ll x[MAXN], y[MAXN];
vector <pair <int, int>> q[MAXN];
int main() {
	read(n), read(m), read(p), r = 1e6;
	for (int i = 1; i <= r + 1; i++)
		x[i] = y[i] = INF;
	for (int i = 1; i <= n; i++) {
		int a; ll c; read(a), read(c);
		chkmin(x[a], c);
	}
	for (int i = 1; i <= m; i++) {
		int a; ll c; read(a), read(c);
		chkmin(y[a], c);
	}
	for (int i = r; i >= 1; i--) {
		chkmin(x[i], x[i + 1]);
		chkmin(y[i], y[i + 1]);
	}
	for (int i = 1; i <= p; i++) {
		int a, b, c; read(a), read(b), read(c);
		q[a].emplace_back(b, c);
	}
	ST.init(r);
	for (int i = 1; i <= r; i++)
		if (y[i] > y[i - 1]) ST.modify(i, r, y[i - 1] - y[i]);
	ll ans = -INF;
	for (int i = 1; i <= r; i++) {
		chkmax(ans, ST.query(1, r) - x[i]);
		for (auto x : q[i])
			ST.modify(x.first + 1, r, x.second);
	}
	cout << ans << endl;
	return 0;
}