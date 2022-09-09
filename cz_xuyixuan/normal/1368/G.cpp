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
struct SegmentTree {
	struct Node {
		int lc, rc;
		int tag, Min, cnt;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].tag = 0;
		a[root].Min = 0;
		a[root].cnt = r - l + 1;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].cnt = 0;
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
		if (a[a[root].lc].Min == a[root].Min) a[root].cnt += a[a[root].lc].cnt;
		if (a[a[root].rc].Min == a[root].Min) a[root].cnt += a[a[root].rc].cnt;
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Min += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Min += a[root].tag;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Min += d;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(root);
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, int d) {
		modify(root, 1, n, l, r, d);
	}
	int query() {
		if (a[root].Min == 0) return a[root].cnt;
		else return 0;
	}
} ST;
vector <char> c[MAXN];
vector <int> point[MAXN];
void getLRUD(char &x) {
	x = getchar();
	while (x != 'L' && x != 'R' && x != 'U' && x != 'D') x = getchar();
}
int n, m, tot; ll ans;
bool visa[MAXN], visb[MAXN];
vector <int> a[MAXN], b[MAXN];
int timer, dfn[MAXN], rit[MAXN];
void getans(int pos) {
	ST.modify(dfn[pos], rit[pos], 1);
	ans += tot - ST.query();
	for (auto x : a[pos]) getans(x);
	ST.modify(dfn[pos], rit[pos], -1);
}
void dfs(int pos) {
	dfn[pos] = ++timer;
	for (auto x : b[pos]) dfs(x);
	rit[pos] = timer;
}
int main() {
	read(n), read(m);
	for (int i = 0; i <= n + 1; i++) {
		c[i].resize(m + 2);
		point[i].resize(m + 2);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		getLRUD(c[i][j]);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		char cur = c[i][j];
		if (cur == 'L' || cur == 'U') point[i][j] = ++tot;
		if (cur == 'R') point[i][j] = point[i][j - 1];
		if (cur == 'D') point[i][j] = point[i - 1][j];
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		char cur = c[i][j]; int x = 0;
		if (cur == 'L') x = point[i][j + 2];
		if (cur == 'R') x = point[i][j - 2];
		if (cur == 'U') x = point[i + 2][j];
		if (cur == 'D') x = point[i - 2][j];
		if (x != 0) {
			if ((i + j) & 1) a[x].push_back(point[i][j]), visa[point[i][j]] = true;
			else b[x].push_back(point[i][j]), visb[point[i][j]] = true;
		}
	}
	ST.init(tot);
	for (int i = 1; i <= tot; i++)
		if (!visb[i]) dfs(i);
	for (int i = 1; i <= tot; i++)
		if (!visa[i]) getans(i);
	cout << ans << endl;
	return 0;
}