#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
const int P = 1e9 + 7;
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
void chkmax(int &x, int y) {x = max(x, y); }
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
struct SegmentTree {
	struct Node {
		bool tag;
		int lc, rc, len;
		long long val, sum;
	} a[MAXN * 2];
	int root, n, size;
	void update(int root) {a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum; }
	void pushdown(int root) {
		if (a[root].tag) {
			int tmp = a[root].lc;
			a[tmp].tag = true;
			a[tmp].val = a[root].val;
			a[tmp].sum = a[root].val * a[tmp].sum;
			tmp = a[root].rc;
			a[tmp].tag = true;
			a[tmp].val = a[root].val;
			a[tmp].sum = a[root].val * a[tmp].sum;
			a[root].tag = false;
		}
	}
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].len = r - l + 1;
		a[root].tag = false;
		a[root].sum = a[root].val = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x; size = 0;
		build(root, 0, n);
	}
	void modify(int root, int l, int r, int ql, int qr, long long val) {
		if (l == ql && r == qr) {
			a[root].tag = true;
			a[root].val = val;
			a[root].sum = val * a[root].len;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(qr, mid), val);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, val);
		update(root);
	}
	void modify(int l, int r, long long val) {
		if (l <= r) modify(root, 0, n, l, r, val);
	}
	long long query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		pushdown(root);
		int mid = (l + r) / 2;
		long long ans = 0;
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	long long query(int l, int r) {
		if (l <= r) return query(root, 0, n, l, r) % P;
		else return 0;
	}
} ST[2];
int k, n, m;
int l[2][MAXN], r[2][MAXN], p[2][MAXN];
vector <int> pos;
int main() {
	read(k), read(n), read(m);
	pos.push_back(1);
	pos.push_back(k + 1);
	for (int i = 1; i <= n; i++) {
		read(l[0][i]), read(r[0][i]);
		pos.push_back(l[0][i]);
		pos.push_back(r[0][i] + 1);
	}
	for (int i = 1; i <= m; i++) {
		read(l[1][i]), read(r[1][i]);
		pos.push_back(l[1][i]);
		pos.push_back(r[1][i] + 1);
	}
	sort(pos.begin(), pos.end());
	pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
	int size = pos.size() - 1;
	ST[0].init(size);
	ST[1].init(size);
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++) {
		int tl = lower_bound(pos.begin(), pos.end(), l[0][i]) - pos.begin();
		int tr = upper_bound(pos.begin(), pos.end(), r[0][i]) - pos.begin() - 1;
		chkmax(p[0][tr], tl);
	}
	for (int i = 1; i <= m; i++) {
		int tl = lower_bound(pos.begin(), pos.end(), l[1][i]) - pos.begin();
		int tr = upper_bound(pos.begin(), pos.end(), r[1][i]) - pos.begin() - 1;
		chkmax(p[1][tr], tl);
	}
	long long ans = 1;
	for (unsigned i = 0; i < pos.size() - 1; i++) {
		int len = pos[i + 1] - pos[i];
		long long tmp = (power(2, len) - 2 + P) % P;
		long long tans = tmp * (ans + ST[0].query(0, size) + ST[1].query(0, size)) % P;
		ST[0].modify(i, i, (ans + ST[1].query(0, i - 1ll)) % P);
		ST[1].modify(i, i, (ans + ST[0].query(0, i - 1ll)) % P);
		ST[0].modify(0, p[1][i], 0);
		ST[1].modify(0, p[0][i], 0);
		ans = tans;
	}
	writeln((ans + ST[0].query(0, size) + ST[1].query(0, size)) % P);
	return 0;
}