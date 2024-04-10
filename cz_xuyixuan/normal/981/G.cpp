#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 998244353;
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
void adds(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void times(int &x, int y) {
	x = 1ll * x * y % P;
}
struct SegmentTree {
	struct Node {
		int lc, rc, len;
		int sum, k, b;
	} a[MAXN * 2];
	int n, size, root;
	void update(int root) {
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
		if (a[root].sum >= P) a[root].sum -= P;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].len = r - l + 1;
		a[root].k = 1;
		a[root].b = 0;
		a[root].sum = 0;
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
	void pushdown(int root) {
		if (a[root].k == 1 && a[root].b == 0) return;
		times(a[a[root].lc].k, a[root].k);
		times(a[a[root].lc].b, a[root].k);
		times(a[a[root].lc].sum, a[root].k);
		adds(a[a[root].lc].b, a[root].b);
		adds(a[a[root].lc].sum, 1ll * a[root].b * a[a[root].lc].len % P);
		times(a[a[root].rc].k, a[root].k);
		times(a[a[root].rc].b, a[root].k);
		times(a[a[root].rc].sum, a[root].k);
		adds(a[a[root].rc].b, a[root].b);
		adds(a[a[root].rc].sum, 1ll * a[root].b * a[a[root].rc].len % P);
		a[root].k = 1, a[root].b = 0;
	}
	void modify(int root, int l, int r, int ql, int qr, int k, int b) {
		if (l == ql && r == qr) {
			times(a[root].k, k);
			times(a[root].b, k);
			times(a[root].sum, k);
			adds(a[root].b, b);
			adds(a[root].sum, 1ll * b * a[root].len % P);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(qr, mid), k, b);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, k, b);
		update(root);
	}
	void modify(int l, int r, int k, int b) {
		if (l > r) return;
		else modify(root, 1, n, l, r, k, b);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		int ans = 0;
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans % P;
	}
	int query(int l, int r) {
		if (l > r) return 0;
		else return query(root, 1, n, l, r);
	}
} ST;
int n, q;
set <pair <int, int> > st[MAXN];
int main() {
	read(n), read(q);
	ST.init(n);
	for (int i = 1; i <= q; i++) {
		int opt, l, r, val;
		read(opt), read(l), read(r);
		if (opt == 2) writeln(ST.query(l, r));
		else {
			read(val);
			int fl = l, fr = r, last = l;
			set <pair <int, int> > :: iterator tmp = st[val].lower_bound(make_pair(l, l)), tnp = tmp;
			if (tmp != st[val].begin()) {
				tnp--;
				if ((*tnp).second >= l) {
					if ((*tnp).second >= r) {
						ST.modify(l, r, 2, 0);
						continue;
					}
					fl = (*tnp).first;
					ST.modify(last, (*tnp).second, 2, 0);
					last = (*tnp).second + 1;
					st[val].erase(tnp);
				}
			}
			while (tmp != st[val].end() && (*tmp).second <= r) {
				ST.modify(last, (*tmp).first - 1, 1, 1);
				ST.modify((*tmp).first, (*tmp).second, 2, 0);
				last = (*tmp).second + 1;
				tnp = tmp; tmp++;
				st[val].erase(tnp);
			}
			if (tmp != st[val].end() && (*tmp).first <= r) {
				fr = (*tmp).second;
				ST.modify(last, (*tmp).first - 1, 1, 1);
				ST.modify((*tmp).first, r, 2, 0);
				st[val].erase(tmp);
			} else ST.modify(last, r, 1, 1);
			st[val].insert(make_pair(fl, fr));
		}
	}
	return 0;
}