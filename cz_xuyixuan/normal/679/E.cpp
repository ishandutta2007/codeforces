#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
const ll keys[11] = {1, 42, 1764, 74088, 3111696, 130691232, 5489031744ll, 230539333248ll, 9682651996416ll, 406671383849472ll, 17080198121677824ll};
ll nxt(ll x) {return (*upper_bound(keys, keys + 11, x)) - x; }
struct SegmentTree {
	struct Node {
		int lc, rc;
		ll tag, all, Min;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
		a[root].all = (a[a[root].lc].all == a[a[root].rc].all) ? a[a[root].lc].all : 0;
	}
	void build(int &root, int l, int r, int *b) {
		root = ++size;
		if (l == r) {
			a[root].all = b[l];
			a[root].Min = nxt(b[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, b);
		build(a[root].rc, mid + 1, r, b);
		update(root);
	}
	void init(int x, int *b) {
		n = x, root = size = 0;
		build(root, 1, n, b);
	}
	void pushdown(int root) {
		if (a[root].all) {
			a[a[root].lc].all = a[root].all;
			a[a[root].lc].Min = a[root].Min;
			a[a[root].rc].all = a[root].all;
			a[a[root].rc].Min = a[root].Min;
		} else if (a[root].tag) {
			if (a[a[root].lc].all) a[a[root].lc].all += a[root].tag;
			else a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Min -= a[root].tag;
			if (a[a[root].rc].all) a[a[root].rc].all += a[root].tag;
			else a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Min -= a[root].tag;
		}
		a[root].tag = 0;
	}
	bool modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			if (a[root].Min > d) {
				a[root].Min -= d;
				if (a[root].all) a[root].all += d;
				else a[root].tag += d;
				return false;
			}
			if (l == r || a[root].all) {
				bool ans = false;
				if (nxt(a[root].all + d - 1) == 1) ans = true;
				a[root].all += d;
				a[root].Min = nxt(a[root].all);
				return ans;
			}
			pushdown(root);
			int mid = (l + r) / 2; bool ans = false;
			ans |= modify(a[root].lc, l, mid, l, mid, d);
			ans |= modify(a[root].rc, mid + 1, r, mid + 1, r, d);
			update(root);
			return ans;
		}
		pushdown(root);
		int mid = (l + r) / 2; bool ans = false;
		if (mid >= ql) ans |= modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) ans |= modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
		return ans;
	}
	void modify(int l, int r, int d) {
		bool flg = true;
		while (flg) flg = modify(root, 1, n, l, r, d);
	}
	void gvalue(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].all = d;
			a[root].Min = nxt(d);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) gvalue(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) gvalue(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void gvalue(int l, int r, int d) {
		gvalue(root, 1, n, l, r, d);
	}
	ll query(int root, int l, int r, int pos) {
		if (l == r) return a[root].all;
		int mid = (l + r) / 2; pushdown(root);
		if (mid >= pos) return query(a[root].lc, l, mid, pos);
		else return query(a[root].rc, mid + 1, r, pos);
		update(root);
	}
	ll query(int pos) {
		return query(root, 1, n, pos);
	}
} ST;
int n, m, a[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	ST.init(n, a);
	for (int i = 1; i <= m; i++) {
		int opt; read(opt);
		if (opt == 1) {
			int x; read(x);
			printf("%lld\n", ST.query(x));
		} else if (opt == 2) {
			int l, r, x; read(l), read(r), read(x);
			ST.gvalue(l, r, x);
		} else {
			int l, r, x; read(l), read(r), read(x);
			ST.modify(l, r, x);
		}
	}
	return 0;
}