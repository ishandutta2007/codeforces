#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 1e9 + 7;
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
		long long sum, prd, num;
	} a[MAXN * 2];
	int n, size, root;
	int pos[MAXN], val[MAXN];
	void update(int root) {
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
		a[root].prd = (a[a[root].lc].prd + a[a[root].rc].prd) % P;
		a[root].num = (a[a[root].lc].num + a[a[root].rc].num) % P;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].sum = val[l];
			a[root].num = 1ll * val[l] * l % P;
			a[root].prd = 1ll * val[l] * pos[l] % P;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		root = size = 0;
		for (int i = 1; i <= n; i++)
			read(pos[i]);
		for (int i = 1; i <= n; i++)
			read(val[i]);
		build(root, 1, n);
	}
	void modify(int root, int l, int r, int p) {
		if (l == r) {
			a[root].sum = val[l];
			a[root].num = 1ll * val[l] * l % P;
			a[root].prd = 1ll * val[l] * pos[l] % P;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= p) modify(a[root].lc, l, mid, p);
		else modify(a[root].rc, mid + 1, r, p);
		update(root);
	}
	void modify(int pos, int d) {
		val[pos] = d;
		modify(root, 1, n, pos);
	}
	ll querys(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		long long ans = 0;
		int mid = (l + r) / 2;
		if (mid >= ql) ans += querys(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += querys(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	ll querys(int l, int r) {
		if (l > r) return 0; 
		else return querys(root, 1, n, l, r);
	}
	ll queryp(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].prd;
		long long ans = 0;
		int mid = (l + r) / 2;
		if (mid >= ql) ans += queryp(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += queryp(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans % P;
	}
	ll queryp(int l, int r) {
		if (l > r) return 0; 
		else return queryp(root, 1, n, l, r);
	}
	ll queryn(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].num;
		long long ans = 0;
		int mid = (l + r) / 2;
		if (mid >= ql) ans += queryn(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += queryn(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans % P;
	}
	ll queryn(int l, int r) {
		if (l > r) return 0; 
		else return queryn(root, 1, n, l, r);
	}
	int findmid(int root, int l, int r, ll pos) {
		if (l == r) return l;
		int mid = (l + r) / 2;
		if (pos <= a[a[root].lc].sum) return findmid(a[root].lc, l, mid, pos);
		else return findmid(a[root].rc, mid + 1, r, pos - a[a[root].lc].sum);
	}
	ll mquery(int l, int r) {
		ll tmp = querys(l, r);
		ll tnp = querys(1, l - 1) + (tmp + 1) / 2;
		int mid = findmid(root, 1, n, tnp);
		ll ls = querys(l, mid) % P, rs = querys(mid, r) % P;
		ll ans = ls * pos[mid] % P - queryp(l, mid);
		ans += queryp(mid, r) - rs * pos[mid] % P;
		ans -= 1ll * mid * ls % P - queryn(l, mid);
		ans -= queryn(mid, r) - 1ll * mid * rs % P;
		ans = (ans % P + P) % P;
		return ans;
	}
} ST;
int main() {
	int n, m; read(n), read(m);
	ST.init(n);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		if (x <= 0) ST.modify(-x, y);
		else writeln(ST.mquery(x, y));
	}
	return 0;
}