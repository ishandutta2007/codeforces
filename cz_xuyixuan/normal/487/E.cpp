#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXP = 400005;
const int INF = 1e9;
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
		int Min;
	} a[MAXP];
	int root, n, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].Min = INF;
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
	void update(int root) {
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
	}
	void modify(int root, int l, int r, int pos, int x) {
		if (l == r) {
			a[root].Min = x;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, x);
		else modify(a[root].rc, mid + 1, r, pos, x);
		update(root);
	}
	void modify(int pos, int x) {
		modify(root, 1, n, pos, x);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Min;
		int ans = INF, mid = (l + r) / 2;
		if (mid >= ql) chkmin(ans, query(a[root].lc, l, mid, ql, min(qr, mid)));
		if (mid + 1 <= qr) chkmin(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	int query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
struct Heap {
	priority_queue <int, vector<int>, greater<int> > Heap, Delt;
	void push(int x) {Heap.push(x); }
	void delt(int x) {Delt.push(x); }
	int query() {
		while (!Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		return Heap.top();
	}
} Heap[MAXN];
int n, m, q, oldn, val[MAXN];
int top, Stack[MAXN];
int timer, dfn[MAXN], low[MAXN], up[MAXN];
int depth[MAXN], father[MAXN], size[MAXN], son[MAXN];
vector <int> a[MAXN], b[MAXN];
void dfs(int pos, int fa) {
	size[pos] = 1;
	father[pos] = fa;
	depth[pos] = depth[fa] + 1;
	for (unsigned i = 0; i < b[pos].size(); i++)
		if (b[pos][i] != fa) {
			dfs(b[pos][i], pos);
			size[pos] += size[b[pos][i]];
			if (size[b[pos][i]] > size[son[pos]]) son[pos] = b[pos][i];
		}
}
void efs(int pos, int fa) {
	dfn[pos] = ++timer; up[pos] = fa;
	if (pos <= oldn) ST.modify(timer, val[pos]);
	else ST.modify(timer, Heap[pos].query());
	if (son[pos]) efs(son[pos], fa);
	for (unsigned i = 0; i < b[pos].size(); i++)
		if (b[pos][i] != father[pos] && b[pos][i] != son[pos]) efs(b[pos][i], b[pos][i]);
}
void tarjan(int pos) {
	Stack[++top] = pos;
	dfn[pos] = low[pos] = ++timer;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (dfn[a[pos][i]] == 0) {
			tarjan(a[pos][i]);
			chkmin(low[pos], low[a[pos][i]]);
			if (low[a[pos][i]] >= dfn[pos]) {
				int tmp = 0; n++;
				while (tmp != a[pos][i]) {
					tmp = Stack[top--];
					Heap[n].push(val[tmp]);
					b[n].push_back(tmp);
					b[tmp].push_back(n);
				}
				b[n].push_back(pos);
				b[pos].push_back(n);
			}
		} else chkmin(low[pos], dfn[a[pos][i]]);
}
int query(int x, int y) {
	int ans = INF;
	while (up[x] != up[y]) {
		if (depth[up[x]] < depth[up[y]]) swap(x, y);
		chkmin(ans, ST.query(dfn[up[x]], dfn[x]));
		x = father[up[x]];
	}
	if (dfn[x] > dfn[y]) swap(x, y);
	chkmin(ans, ST.query(dfn[x], dfn[y]));
	if (x > oldn) chkmin(ans, val[father[x]]);
	return ans;
}
int main() {
	read(n), read(m), oldn = n, read(q);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	tarjan(1);
	timer = 0;
	memset(dfn, 0, sizeof(dfn));
	dfs(1, 0);
	ST.init(n);
	efs(1, 1);
	for (int i = 1; i <= q; i++) {
		char opt; int x, y;
		scanf("\n%c%d%d", &opt, &x, &y);
		if (opt == 'C') {
			int old = val[x];
			val[x] = y;
			ST.modify(dfn[x], y);
			if (father[x]) {
				int f = father[x];
				Heap[f].delt(old);
				Heap[f].push(y);
				ST.modify(dfn[f], Heap[f].query());
			}
		} else writeln(query(x, y));
	}
	return 0;
}