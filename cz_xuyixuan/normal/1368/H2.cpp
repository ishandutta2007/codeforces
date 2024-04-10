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
	int sum, cnta, cntb;
	int res[2][2][2];
};
info merge(info a, info b, int cost) {
	info ans;
	ans.sum = a.sum + b.sum;
	ans.cnta = a.cnta + b.cnta;
	ans.cntb = a.cntb + b.cntb;
	for (int k = 0; k <= 1; k++)
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++) {
		int cur = INF;
		for (int x = 0; x <= 1; x++)
		for (int y = 0; y <= 1; y++)
			chkmin(cur, a.res[k][i][x] + b.res[k][y][j] + (x != y) * cost);
		ans.res[k][i][j] = cur;
	}
	return ans;
}
info unit(int a, int b) {
	info ans;
	ans.sum = 1;
	ans.cnta = a, ans.cntb = b;
	for (int k = 0; k <= 1; k++)
	for (int i = 0; i <= 1; i++) {
		ans.res[k][i][i] = (i != a) + ((i ^ k) != b);
		ans.res[k][i][i ^ 1] = INF;
	}
	return ans;
}
struct SegmentTree {
	struct Node {
		int lc, rc; info ans;
		bool taga, tagb;
	} a[MAXN * 2];
	int n, m, root, size;
	void update(int root) {
		a[root].ans = merge(a[a[root].lc].ans, a[a[root].rc].ans, m);
	}
	void build(int &root, int l, int r, char *u, char *d) {
		root = ++size;
		if (l == r) {
			a[root].ans = unit(u[l] == 'R', d[l] == 'R');
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, u, d);
		build(a[root].rc, mid + 1, r, u, d);
		update(root);
	}
	void init(int x, int y, char *u, char *d) {
		n = x, m = y, root = size = 0;
		build(root, 1, n, u, d);
	}
	void puttag(int root, bool taga, bool tagb) {
		if (taga) {
			a[root].taga ^= true;
			a[root].ans.cnta = a[root].ans.sum - a[root].ans.cnta;
			for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++)
				swap(a[root].ans.res[0][i][j], a[root].ans.res[1][i ^ 1][j ^ 1]);
		}
		if (tagb) {
			a[root].tagb ^= true;
			a[root].ans.cntb = a[root].ans.sum - a[root].ans.cntb;
			for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++)
				swap(a[root].ans.res[0][i][j], a[root].ans.res[1][i][j]);
		}
	}
	void pushdown(int root) {
		puttag(a[root].lc, a[root].taga, a[root].tagb);
		puttag(a[root].rc, a[root].taga, a[root].tagb);
		a[root].taga = a[root].tagb = false;
	}
	void modify(int root, int l, int r, int ql, int qr, bool taga, bool tagb) {
		if (l == ql && r == qr) {
			puttag(root, taga, tagb);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), taga, tagb);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, taga, tagb);
		update(root);
	}
	void modify(bool type, int l, int r) {
		if (type) modify(root, 1, n, l, r, 0, 1);
		else modify(root, 1, n, l, r, 1, 0);
	}
	info query() {
		return a[root].ans;
	}
} UD, LR;
int n, m, q;
char L[MAXN], R[MAXN], U[MAXN], D[MAXN];
int query() {
	int ans = INF;
	info lr = LR.query(), ud = UD.query();
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++) {
		int cur = lr.res[0][i][j];
		if (i == 0) cur += ud.cnta;
		else cur += ud.sum - ud.cnta;
		if (j == 0) cur += ud.cntb;
		else cur += ud.sum - ud.cntb;
		chkmin(ans, cur);
		cur = ud.res[0][i][j];
		if (i == 0) cur += lr.cnta;
		else cur += lr.sum - lr.cnta;
		if (j == 0) cur += lr.cntb;
		else cur += lr.sum - lr.cntb;
		chkmin(ans, cur);
	}
	return ans;
}
int main() {
	read(n), read(m), read(q);
	scanf("\n%s\n%s", L + 1, R + 1);
	scanf("\n%s\n%s", U + 1, D + 1);
	LR.init(n, m, L, R), UD.init(m, n, U, D);
	printf("%d\n", query());
	for (int i = 1; i <= q; i++) {
		char c; int x, y;
		scanf("\n%c%d%d", &c, &x, &y);
		if (c == 'L') LR.modify(0, x, y);
		if (c == 'R') LR.modify(1, x, y);
		if (c == 'U') UD.modify(0, x, y);
		if (c == 'D') UD.modify(1, x, y);
		printf("%d\n", query());
	}
	return 0;
}