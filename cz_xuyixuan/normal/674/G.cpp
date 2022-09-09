#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
struct info {
	int cnt;
	pair <int, int> a[6];
}; int n, p, q;
info operator + (info a, pair <int, int> x) {
	for (int i = 1; i <= a.cnt; i++)
		if (a.a[i].first == x.first) {
			a.a[i].second += x.second;
			return a;
		}
	if (a.cnt < p) a.a[++a.cnt] = x;
	else {
		pair <int, int> Min = make_pair(0, INF);
		for (int i = 1; i <= a.cnt; i++)
			if (a.a[i].second < Min.second) {
				Min.second = a.a[i].second;
				Min.first = i;
			}
		if (Min.second >= x.second) {
			for (int i = 1; i <= a.cnt; i++)
				a.a[i].second -= x.second;
		} else {
			for (int i = 1; i <= a.cnt; i++)
				a.a[i].second -= Min.second;
			x.second -= Min.second;
			a.a[Min.first] = x;
		}
	}
	return a;
}
info operator + (info a, info b) {
	for (int i = 1; i <= b.cnt; i++)
		a = a + b.a[i];
	return a;
}
info make(pair <int, int> x) {
	info ans; ans.cnt = 1;
	ans.a[1] = x;
	return ans;
}
struct SegmentTree {
	struct Node {
		int lc, rc, len, tag;
		info ans;
	} a[MAXN * 2];
	int root, size, n;
	void update(int root) {
		a[root].ans = a[a[root].lc].ans + a[a[root].rc].ans;
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag = a[root].tag;
			a[a[root].lc].ans = make(make_pair(a[root].tag, a[a[root].lc].len));
			a[a[root].rc].tag = a[root].tag;
			a[a[root].rc].ans = make(make_pair(a[root].tag, a[a[root].rc].len));
			a[root].tag = 0;
		}
	}
	void build(int &root, int l, int r, int *b) {
		root = ++size;
		a[root].len = r - l + 1;
		if (l == r) {
			a[root].ans = make(make_pair(b[l], 1));
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, b);
		build(a[root].rc, mid + 1, r, b);
		update(root);
	}
	void init(int x, int *b) {
		n = x; root = size = 0;
		build(root, 1, n, b);
	}
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag = d;
			a[root].ans = make(make_pair(d, a[root].len));
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= qr) modify(a[root].lc, l, mid, ql, qr, d);
		else if (mid + 1 <= ql) modify(a[root].rc, mid + 1, r, ql, qr, d);
		else modify(a[root].lc, l, mid, ql, mid, d), modify(a[root].rc, mid + 1, r, mid + 1, qr, d);
		update(root);
	}
	void modify(int l, int r, int d) {
		modify(root, 1, n, l, r, d);
	}
	info query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].ans;
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return query(a[root].lc, l, mid, ql, mid) + query(a[root].rc, mid + 1, r, mid + 1, qr);
	}
	info query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
int a[MAXN];
int main() {
	read(n), read(q), read(p), p = 100 / p;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	ST.init(n, a);
	for (int i = 1; i <= q; i++) {
		int opt, l, r, x;
		read(opt), read(l), read(r);
		if (opt == 1) {
			read(x);
			ST.modify(l, r, x);
		} else {
			info ans = ST.query(l, r);
			printf("%d", ans.cnt);
			for (int i = 1; i <= ans.cnt; i++)
				printf(" %d", ans.a[i]);
			printf("\n");
		}
	}
	return 0;
}