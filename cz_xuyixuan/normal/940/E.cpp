#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 20;
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
		int Min;
	} a[MAXN * 2];
	int root, size, n;
	void update(int root) {
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
	}
	void build(int &root, int l, int r, int *val) {
		root = ++size;
		if (l == r) {
			a[root].Min = val[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, val);
		build(a[root].rc, mid + 1, r, val);
		update(root);
	}
	void init(int x, int *val) {
		n = x; root = size = 0;
		build(root, 1, n, val);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Min;
		int mid = (l + r) / 2, ans = INT_MAX;
		if (mid >= ql) ans = min(ans, query(a[root].lc, l, mid, ql, min(mid, qr)));
		if (mid + 1 <= qr) ans = min(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	int query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
int n, m, a[MAXN];
long long s[MAXN], dp[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	ST.init(n, a);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + a[i];
		if (i >= m) dp[i] = min(dp[i], dp[i - m] + s[i] - s[i - m] - ST.query(i - m + 1, i));
	}
	writeln(dp[n]);
	return 0;
}