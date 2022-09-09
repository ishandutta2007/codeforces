#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
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
		vector <int> tag;
	} a[MAXN * 2];
	int n, size, root;
	bitset <MAXN> ans;
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
	void modify(int root, int l, int r, int ql, int qr, int x) {
		if (l == ql && r == qr) {
			a[root].tag.push_back(x);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(qr, mid), x);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, x);
	}
	void modify(int l, int r, int x) {
		if (l > r) return;
		else modify(root, 1, n, l, r, x);
	}
	void work(int pos, bitset <MAXN> now) {
		for (auto x : a[pos].tag)
			now |= now << x;
		if (a[pos].lc == 0) {
			ans |= now;
			return;
		}
		work(a[pos].lc, now);
		work(a[pos].rc, now);
	}
	void getans() {
		work(root, 1);
		vector <int> finalans;
		for (int i = 1; i <= n; i++)
			if (ans[i]) finalans.push_back(i);
		writeln(finalans.size());
		for (auto x : finalans)
			printf("%d ", x);
	}
} ST;
int n, m;
int main() {
	read(n), read(m);
	ST.init(n);
	for (int i = 1; i <= m; i++) {
		int l, r, x;
		read(l), read(r), read(x);
		ST.modify(l, r, x);
	}
	ST.getans();
	return 0;
}