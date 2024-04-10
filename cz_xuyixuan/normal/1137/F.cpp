#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXLOG = 20;
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
struct BinaryIndexTree {
	int n, a[MAXN * 2];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT;
struct SegmentTree {
	struct Node {
		int lc, rc;
		int tag;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].tag = 0;
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
		if (a[a[root].lc].tag == a[a[root].rc].tag) a[root].tag = a[a[root].lc].tag;
		else a[root].tag = -1;
	}
	void pushdown(int root) {
		if (a[root].tag != -1) {
			a[a[root].lc].tag = a[root].tag;
			a[a[root].rc].tag = a[root].tag;
		}
	}
	map <int, int> mp;
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr && a[root].tag != -1) {
			if (a[root].tag != 0) mp[a[root].tag] -= r - l + 1;
			a[root].tag = d, mp[a[root].tag] += r - l + 1;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(root);
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, int d) {
		mp.clear();
		modify(root, 1, n, l, r, d);
		for (auto x : mp) BIT.modify(x.first, x.second);
	}
	int query(int root, int l, int r, int pos) {
		if (a[root].tag != -1) return a[root].tag;
		int mid = (l + r) / 2;
		if (mid >= pos) return query(a[root].lc, l, mid, pos);
		else return query(a[root].rc, mid + 1, r, pos);
	}
	int query(int pos) {
		return query(root, 1, n, pos);
	}
} ST;
vector <int> a[MAXN];
int timer, dfn[MAXN], rit[MAXN], up[MAXN];
int depth[MAXN], size[MAXN], son[MAXN], father[MAXN][MAXLOG];
void dfs(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	size[pos] = 1, father[pos][0] = fa;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			dfs(a[pos][i], pos);
			size[pos] += size[a[pos][i]];
			if (size[a[pos][i]] > size[son[pos]]) son[pos] = a[pos][i];
		}
}
void efs(int pos, int fa, int from) {
	up[pos] = from;
	dfn[pos] = ++timer;
	if (son[pos]) efs(son[pos], pos, from);
	for (auto x : a[pos])
		if (x != fa && x != son[pos]) {
			efs(x, pos, x);
		}
	rit[pos] = timer;
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[x][i]] >= depth[y]) x = father[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	return father[x][0];
}
int n, m, k, pos[MAXN * 2];
int query(int x) {
	int tmp = ST.query(dfn[x]);
	return BIT.query(tmp - 1) + depth[x] + depth[pos[tmp]] - 2 * depth[lca(x, pos[tmp])] + 1;
}
void modify(int x, int y, int d) {
	while (up[x] != up[y]) {
		if (depth[up[x]] < depth[up[y]]) swap(x, y);
		ST.modify(dfn[up[x]], dfn[x], d);
		x = father[up[x]][0];
	}
	if (dfn[x] > dfn[y]) swap(x, y);
	ST.modify(dfn[x], dfn[y], d);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	efs(1, 0, 1);
	BIT.init(n + m), ST.init(n);
	int Max = 1;
	for (int i = 2; i <= n; i++) {
		modify(Max, i, i);
		pos[i] = Max, Max = i;
	}
	for (int i = 1; i <= m; i++) {
		char s[15]; int x, y;
		scanf("\n%s%d", s, &x);
		if (s[0] == 'u') modify(Max, x, i + n), pos[i + n] = Max, Max = x;
		else if (s[0] == 'w') printf("%d\n", query(x));
		else if (s[0] == 'c') {
			read(y);
			if (query(x) < query(y)) printf("%d\n", x);
			else printf("%d\n", y);
		}
	}
	return 0;
}