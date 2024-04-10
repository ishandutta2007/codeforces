#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXP = 4e6 + 5;
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
		int Max;
	} a[MAXP];
	int size, tot, n, root[MAXN];
	void init(int x, int y) {
		size = 0;
		tot = x; n = y;
		memset(root, 0, sizeof(root));
	}
	void modify(int &root, int l, int r, int pos, int val) {
		if (root == 0) root = ++size;
		chkmax(a[root].Max, val);
		if (l == r) return;
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val);
		else modify(a[root].rc, mid + 1, r, pos, val);
	}
	void modify(int x, int y, int val) {
		modify(root[x], 0, n, y, val);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (root == 0) return 0;
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2, ans = 0;
		if (mid >= ql) chkmax(ans, query(a[root].lc, l, mid, ql, min(mid, qr)));
		if (mid + 1 <= qr) chkmax(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	int query(int x, int y) {
		if (y == 0) return 0;
		else return query(root[x], 0, n, 0, y - 1);
	}
} ST;
int n, m, dp[MAXN];
int main() {
	read(n), read(m);
	ST.init(n, 1e5);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		dp[i] = ST.query(x, z) + 1;
		ST.modify(y, z, dp[i]);
	}
	int Max = 0;
	for (int i = 1; i <= m; i++)
		chkmax(Max, dp[i]);
	writeln(Max);
	return 0;
}