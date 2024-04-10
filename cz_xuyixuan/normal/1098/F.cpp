#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MAXLOG = 20;
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
vector <int> e[MAXN];
int n, oldn, m, depth[MAXN], home[MAXN];
int father[MAXN], size[MAXN], son[MAXN];
int timer, dfn[MAXN], rit[MAXN], up[MAXN];
int ql[MAXN], qr[MAXN], from[MAXN]; ll ans[MAXN];
int jump[MAXN][MAXLOG];
struct SegmentTree {
	struct Node {
		int lc, rc;
		int tag; ll cnt, sum;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
	}
	void build(int &root, int l, int r, int *tmp) {
		root = ++size;
		if (l == r) {
			a[root].cnt = tmp[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, tmp);
		build(a[root].rc, mid + 1, r, tmp);
		a[root].cnt = a[a[root].lc].cnt + a[a[root].rc].cnt;
	}
	void init(int x, int *tmp) {
		n = x, root = size = 0;
		build(root, 1, n, tmp);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			int tmp = a[root].lc, d = a[root].tag;
			a[tmp].tag += d;
			a[tmp].sum += d * a[tmp].cnt;
			tmp = a[root].rc;
			a[tmp].tag += d;
			a[tmp].sum += d * a[tmp].cnt;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].sum += d * a[root].cnt;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(qr, mid), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d); 
		update(root);
	}
	void modify(int l, int r, int d) {
		modify(root, 1, n, l, r, d);
	}
	ll query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		pushdown(root);
		ll ans = 0; int mid = (l + r) / 2;
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr); 
		return ans;
	}
	ll query(int l, int r) {
		return query(root, 1, n, l, r);
	}
	int query(int root, int l, int r, int pos) {
		if (l == r) {
			return a[root].tag;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= pos) return query(a[root].lc, l, mid, pos);
		else return query(a[root].rc, mid + 1, r, pos);
	}
	int query(int pos) {
		return query(root, 1, n, pos);
	}
} ST;
void ScanningLineI() {
	static int tmp[MAXN];
	for (int i = 1; i <= n; i++)
		tmp[dfn[i]] = depth[i] - depth[father[i]];
	ST.init(n, tmp);
	static vector <pair <pair <int, int>, int> > q[MAXN];
	for (int i = 1; i <= m; i++)
		q[ql[i]].push_back(make_pair(make_pair(from[i], qr[i] - ql[i] + 1), i));
	for (int i = 1; i <= oldn; i++) {
		function <ll (pair <int, int>) > query = [&] (pair <int, int> x) {
			ll ans = 1ll * (x.second - depth[father[x.first]]) * ST.query(dfn[x.first]);
			int pos = father[x.first];
			while (pos) {
				ans += ST.query(dfn[up[pos]], dfn[pos]);
				pos = father[up[pos]];
			}
			return ans;
		};
		for (auto x : q[i])
			ans[x.second] -= query(x.first);
		int pos = home[i];
		while (pos) {
			ST.modify(dfn[up[pos]], dfn[pos], 1);
			pos = father[up[pos]];
		}
	}
}
struct BinaryIndexTree {
	int n; ll a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	ll query(int x) {
		ll ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	ll query(int l, int r) {
		if (l > r) return 0;
		ll ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} all[2], part[2];
void ScanningLineII() {
	static vector <pair <int, int> > mod[MAXN];
	static vector <pair <pair <int, int>, int> > qry[MAXN];
	for (int i = 1; i <= oldn; i++) {
		int pos = home[i];
		while (pos) {
			mod[up[pos]].emplace_back(depth[pos], i);
			pos = father[up[pos]];
		}
	}
	for (int i = 1; i <= m; i++) {
		int pos = from[i];
		while (pos) {
			if (pos == from[i]) qry[up[pos]].emplace_back(make_pair(qr[i] - ql[i] + 1, qr[i] + 1), i);
			else qry[up[pos]].emplace_back(make_pair(depth[pos], qr[i] + 1), i);
			pos = father[up[pos]];
		}
	}
	all[0].init(oldn * 2 + 2), all[1].init(oldn * 2 + 2);
	part[0].init(oldn * 2 + 2), part[1].init(oldn * 2 + 2);
	for (int i = 1; i <= n; i++) {
		if (up[i] != i) continue;
		int startdepth = depth[father[i]] + 1;
		sort(mod[i].begin(), mod[i].end());
		reverse(mod[i].begin(), mod[i].end());
		sort(qry[i].begin(), qry[i].end());
		reverse(qry[i].begin(), qry[i].end());
		vector <pair <int, int> > bak = mod[i];
		for (auto x : bak) {
			all[0].modify(x.second, x.second);
			all[1].modify(x.second, 1);
		}
		while (!mod[i].empty() || !qry[i].empty()) {
			if (mod[i].empty() || (!qry[i].empty() && qry[i].back().first.first <= mod[i].back().first)) {
				pair <int, int> x = qry[i].back().first;
				int home = qry[i].back().second;
				ans[home] += part[1].query(x.second) * x.second + part[0].query(x.second);
				int tmp = x.second - x.first;
				if (tmp >= 1) ans[home] += all[1].query(1, tmp) * (x.first - startdepth + 1);
				chkmax(tmp, 0);
				ans[home] += all[1].query(tmp + 1, x.second - startdepth) * (x.second - startdepth + 1) - all[0].query(tmp + 1, x.second - startdepth);
				qry[i].pop_back();
			} else {
				pair <int, int> x = mod[i].back();
				all[0].modify(x.second, -x.second);
				all[1].modify(x.second, -1);
				part[0].modify(startdepth + x.second, -(startdepth + x.second - 1));
				part[0].modify(x.first + 1 + x.second, startdepth + x.second - 1 + x.first - startdepth + 1);
				part[1].modify(startdepth + x.second, 1);
				part[1].modify(x.first + 1 + x.second, -1);
				mod[i].pop_back();
			}
		}
		for (auto x : bak) {
			part[0].modify(startdepth + x.second, startdepth + x.second - 1);
			part[0].modify(x.first + 1 + x.second, -(startdepth + x.second - 1 + x.first - startdepth + 1));
			part[1].modify(startdepth + x.second, -1);
			part[1].modify(x.first + 1 + x.second, 1);
		}
	}
}
void dfs(int pos, int fa) {
	size[pos] = 1;
	father[pos] = fa;
	for (auto x : e[pos]) {
		dfs(x, pos);
		size[pos] += size[x];
		if (size[x] > size[son[pos]]) son[pos] = x;
	}
}
void efs(int pos, int fa, int from) {
	up[pos] = from;
	dfn[pos] = ++timer;
	if (son[pos]) efs(son[pos], pos, from);
	for (auto x : e[pos])
		if (x != son[pos]) efs(x, pos, x);
	rit[pos] = timer;
}
struct SuffixAutomaton {
	struct Node {
		int child[26];
		int depth, father, value;
	} a[MAXN];
	char s[MAXN];
	int root, size, last;
	int newnode(int depth) {
		a[++size].depth = depth;
		return size;
	}
	void extend(int ch, int pos) {
		int p = last, np = newnode(a[p].depth + 1);
		while (a[p].child[ch] == 0) {
			a[p].child[ch] = np;
			if (p != root) p = a[p].father;
		}
		if (a[p].child[ch] == np) a[np].father = root;
		else {
			int q = a[p].child[ch];
			if (a[q].depth == a[p].depth + 1) a[np].father = q;
			else {
				int nq = newnode(a[p].depth + 1);
				memcpy(a[nq].child, a[q].child, sizeof(a[q].child));
				a[nq].father = a[q].father;
				a[np].father = a[q].father = nq;
				while (a[p].child[ch] == q) {
					a[p].child[ch] = nq;
					if (p != root) p = a[p].father;
				}
			}
		}
		a[last = np].value = pos;
	}
	void init() {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		size = 0; root = last = newnode(0);
		for (int i = len; i >= 1; i--)
			extend(s[i] - 'a', i);
		oldn = len, n = size;
		for (int i = 1; i <= size; i++) {
			depth[i] = a[i].depth;
			if (a[i].value) home[a[i].value] = i;
		}
		for (int i = 2; i <= size; i++)
			e[a[i].father].push_back(i);
	}
} SAM;
int main() {
	SAM.init();
	dfs(1, 0);
	efs(1, 0, 1);
	read(m);
	for (int i = 1; i <= m; i++)
		read(ql[i]), read(qr[i]);
	for (int i = 1; i <= n; i++)
		jump[i][0] = father[i];
	for (int t = 1; t < MAXLOG; t++)
	for (int i = 1; i <= n; i++)
		jump[i][t] = jump[jump[i][t - 1]][t - 1];
	for (int i = 1; i <= m; i++) {
		int pos = home[ql[i]], goal = qr[i] - ql[i] + 1;
		for (int j = MAXLOG - 1; j >= 0; j--) {
			int dest = jump[pos][j];
			if (depth[dest] >= goal) pos = dest;
		}
		from[i] = pos;
	}
	ScanningLineI();
	ScanningLineII();
	for (int i = 1; i <= m; i++)
		writeln(ans[i]);
	return 0;
}