#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXP = 1e7 + 5;
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
	int n, a[MAXN];
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
struct SegmentTreeMerging {
	struct Node {
		int lc, rc;
		int sum;
	} a[MAXP];
	int size, n;
	void init(int x) {
		n = x;
		size = 0;
	}
	void update(int root) {
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
	}
	void modify(int &root, int l, int r, int pos) {
		if (root == 0) {
			root = ++size;
			a[root].lc = 0;
			a[root].rc = 0;
			a[root].sum = 0;
		}
		if (l == r) {
			a[root].sum++;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos);
		else modify(a[root].rc, mid + 1, r, pos);
		update(root);
	}
	void modify(int &root, int val) {
		modify(root, 1, n, val);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (root == 0) return 0;
		if (l == ql && r == qr) return a[root].sum;
		int mid = (l + r) / 2, ans = 0;
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	int query(int root, int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
int n, m, k, timer, dfn[MAXN], rit[MAXN];
int depth[MAXN], father[MAXN][MAXLOG];
vector <pair <int, int>> b[MAXN];
vector <int> a[MAXN], c[MAXN]; ll ans, res;
void work(int pos, int fa) {
	dfn[pos] = ++timer;
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
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
int climb(int x, int y) {
	for (int i = 0; y != 0; i++)
		if (y & (1 << i)) {
			y ^= 1 << i;
			x = father[x][i];
		}
	return x;
}
int walk(int x, int y, int steps) {
	int z = lca(x, y);
	if (depth[x] + depth[y] - 2 * depth[z] < steps) return -1;
	if (depth[x] - depth[z] >= steps) return climb(x, steps);
	steps = depth[x] + depth[y] - 2 * depth[z] - steps;
	return climb(y, steps);
}
void workV(int pos, int fa) {
	for (auto x : b[pos]) {
		int tmp = walk(pos, x.first, k);
		if (tmp != -1) ans += BIT.query(dfn[tmp], rit[tmp]);
		tmp = walk(pos, x.second, k);
		if (tmp != -1) ans += BIT.query(dfn[tmp], rit[tmp]);
	}
	for (auto x : b[pos]) {
		BIT.modify(dfn[x.first], 1);
		BIT.modify(dfn[x.second], 1);
	}
	for (auto x : a[pos])
		if (x != fa) workV(x, pos);
}
int points[MAXN], cnt, cmt;
void addedge(int x, int y) {
	c[x].push_back(y);
	c[y].push_back(x);
}
void build(vector <int> a) {
	static int vis[MAXN], task = 0;
	task++, cnt = cmt = 0;
	auto mark = [&] (int x) {
		if (vis[x] != task) {
			vis[x] = task;
			points[++cnt] = x;
		}
	};
	for (auto x : a) mark(x); mark(1);
	sort(points + 1, points + cnt + 1, [&] (int x, int y) {return dfn[x] < dfn[y];});
	int top = 0; cmt = cnt; static int Stack[MAXN];
	for (int i = 1; i <= cnt; i++) {
		int x = points[i];
		while (top >= 2 && depth[lca(x, Stack[top])] <= depth[Stack[top - 1]]) {
			addedge(Stack[top], Stack[top - 1]);
			top--;
		}
		if (top == 0 || lca(x, Stack[top]) == Stack[top]) Stack[++top] = x;
		else {
			int y = lca(x, Stack[top]);
			points[++cmt] = y;
			addedge(Stack[top], y);
			Stack[top] = y;
			Stack[++top] = x;
		}
	}
	while (top >= 2) {
		addedge(Stack[top], Stack[top - 1]);
		top--;
	}
}
int sz[MAXN];
void dfsT(int pos, int fa, int req) {
	for (auto x : c[pos])
		if (x != fa) {
			dfsT(x, pos, req);
			if (depth[pos] >= req) res += 1ll * sz[pos] * sz[x];
			sz[pos] += sz[x];
		}
}
ll workT(vector <int> a, int req) {
	res = 0;
	for (int i = 1; i <= cmt; i++)
		sz[points[i]] = 0;
	for (auto x : a)
		if (depth[x] >= req) {
			res += sz[x]++;
		}
	dfsT(1, 0, req);
	return res;
}
void clear() {
	for (int i = 1; i <= cmt; i++)
		c[points[i]].clear();
}
int rt[MAXN]; vector <int> s[MAXN];
void dfsH(int pos, int fa, int root) {
	for (auto x : c[pos])
		if (x != fa) dfsH(x, pos, root);
	if (pos != root) {
		for (auto x : c[pos])
			if (x != fa) {
				if (s[x].size() > s[pos].size()) {
					swap(s[x], s[pos]);
					swap(rt[x], rt[pos]);
				}
				for (auto y : s[x]) {
					int tmp = walk(pos, y, max(k, depth[pos] - depth[root] + 1));
					if (tmp != -1) res += ST.query(rt[pos], dfn[tmp], rit[tmp]);
				}
				for (auto y : s[x]) {
					s[pos].push_back(y);
					ST.modify(rt[pos], dfn[y]);
				}
			}
	}
}
ll workH(int root, vector <pair <int, int>> a) {
	ST.init(n), res = 0;
	for (int i = 1; i <= cmt; i++) {
		rt[points[i]] = 0;
		s[points[i]].clear();
	}
	for (auto x : a)
		if (x.first != root && x.second != root) {
			if (dfn[x.first] > dfn[x.second]) swap(x.first, x.second);
			s[x.first].push_back(x.second);
			int tmp = walk(x.first, x.second, max(k, depth[x.first] - depth[root] + 1));
			if (tmp != -1) res += ST.query(rt[x.first], dfn[tmp], rit[tmp]);
			ST.modify(rt[x.first], dfn[x.second]);
		}
	dfsH(root, 1, root);
	return res;
}
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	work(1, 0);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		int z = lca(x, y);
		b[z].emplace_back(x, y);
	}
	BIT.init(n);
	workV(1, 0);
	for (int i = 1; i <= n; i++) {
		static vector <int> c[MAXN];
		c[i].clear();
		for (auto x : a[i])
			c[x].clear();
		for (auto x : b[i]) {
			if (x.first != i) {
				int tmp = climb(x.first, depth[x.first] - depth[i] - 1);
				if (x.second != i) c[tmp].push_back(x.second); c[i].push_back(x.first);
			}
			if (x.second != i) {
				int tmp = climb(x.second, depth[x.second] - depth[i] - 1);
				if (x.first != i) c[tmp].push_back(x.first); c[i].push_back(x.second);
			}
		}
		build(c[i]);
		ans += workH(i, b[i]);
		ans += workT(c[i], depth[i] + k), clear();
		for (auto x : a[i])
			if (x != father[i][0]) {
				build(c[x]);
				ans -= workT(c[x], depth[i] + k), clear();
			}
	}
	cout << ans << endl;
	return 0;
}