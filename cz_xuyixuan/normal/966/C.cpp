#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 61;
const int MAXP = 1e7 + 5;
const long long INF = 9e18;
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
		int sum;
	} a[MAXP];
	int root, size;
	void insert(int &root, int depth, long long x, int d) {
		if (root == 0) root = ++size;
		a[root].sum += d;
		if (depth == -1) return;
		long long tmp = 1ll << depth;
		if (tmp & x) insert(a[root].rc, depth - 1, x, d);
		else insert(a[root].lc, depth - 1, x, d);
	}
	void insert(long long x, int d) {
		insert(root, MAXLOG, x, d);
	}
	long long query(int root, int depth, long long x, bool type) {
		if (depth == -1) return 0;
		long long tmp = 1ll << depth;
		if (type) {
			if (x & tmp) {
				if (a[a[root].rc].sum) return query(a[root].rc, depth - 1, x, type) + tmp;
				else return query(a[root].lc, depth - 1, x, type);
			} else {
				if (a[a[root].lc].sum) return query(a[root].lc, depth - 1, x, type);
				else return query(a[root].rc, depth - 1, x, type) + tmp;
			}
		} else {
			if (x & tmp) {
				if (a[a[root].lc].sum) return query(a[root].lc, depth - 1, x, type);
				else return -INF;
			} else {
				if (a[a[root].lc].sum) {
					long long tnp = query(a[root].lc, depth - 1, x, type);
					if (tnp > 0) return tnp;
				}
				if (a[a[root].rc].sum) return query(a[root].rc, depth - 1, x, true) + tmp;
				else return -INF;
			}
		}
	}
	long long query(long long x) {
		long long ans = query(root, MAXLOG, x, false);
		if (ans > 0) insert(ans, -1);
		return ans;
	}
} ST;
long long ans[MAXN];
int main() {
	int n; read(n);
	long long now = 0;
	for (int i = 1; i <= n; i++) {
		long long x; read(x);
		ST.insert(x, 1);
	}
	for (int i = 1; i <= n; i++) {
		long long tmp = ST.query(now);
		if (tmp <= 0) {
			printf("No\n");
			return 0;
		}
		now ^= tmp;
		ans[i] = tmp;
	}
	printf("Yes\n");
	for (int i = 1; i <= n; i++)
		write(ans[i]), putchar(' ');
	return 0;
}