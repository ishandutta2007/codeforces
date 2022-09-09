#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MAXQ = 5e5 + 5;
const int MAXP = 8e6 + 5;
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
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct SegmentTreeMerging {
	struct Node {
		int lc, rc, sum;
		bool leaf;
	} a[MAXP];
	int size, n;
	void init(int x) {
		n = x;
		size = 0;
	}
	void update(int root) {
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
	}
	void modify(int &root, int l, int r, int pos, int d) {
		if (root == 0) root = ++size;
		if (l == r) {
			a[root].sum += d;
			a[root].leaf = true;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, d);
		else modify(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modify(int &root, int val, int d) {
		modify(root, 1, n, val, d);
	}
	int merge(int x, int y) {
		if (x == 0 || y == 0) return x + y;
		if (a[x].leaf) {
			a[x].sum += a[y].sum;
			return x;
		}
		a[x].lc = merge(a[x].lc, a[y].lc);
		a[x].rc = merge(a[x].rc, a[y].rc);
		update(x);
		return x;
	}
	void join(int &to, int from) {
		to = merge(to, from);
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
struct SuffixAutomaton {
	struct Node {
		int child[26];
		int father, depth;
	} a[MAXN];
	vector <int> e[MAXN];
	vector <int> home[MAXN];
	vector <pair <int, int>> s[MAXN];
	int n, root, size, last;
	int newnode(int dep) {
		a[++size].depth = dep;
		return size;
	}
	void init() {
		size = 0;
		root = last = 0;
	}
	void extend(int ch) {
		int p = last, np;
		if (a[p].child[ch]) {
			int q = a[p].child[ch];
			if (a[p].depth + 1 == a[q].depth) np = q;
			else {
				np = newnode(a[p].depth + 1);
				memcpy(a[np].child, a[q].child, sizeof(a[q].child));
				a[np].father = a[q].father;
				a[q].father = np;
				while (a[p].child[ch] == q) {
					a[p].child[ch] = np;
					p = a[p].father;
				}
			}
		} else {
			np = newnode(a[p].depth + 1);
			while (a[p].child[ch] == 0) {
				a[p].child[ch] = np;
				p = a[p].father;
			}
			if (a[p].child[ch] == np) a[np].father = root;
			else {
				int q = a[p].child[ch];
				if (a[q].depth == a[p].depth + 1) a[np].father = q;
				else {
					int nq = newnode(a[p].depth + 1);
					memcpy(a[nq].child, a[q].child, sizeof(a[q].child));
					a[nq].father = a[q].father;
					a[q].father = a[np].father = nq;
					while (a[p].child[ch] == q) {
						a[p].child[ch] = nq;
						p = a[p].father;
					}
				}
			}
		}
		last = np;
	}
	void insert(char *s) {
		last = 0, n++;
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++) {
			extend(s[i] - 'a');
			home[n].push_back(last);
		}
	}
	int rt[MAXN], ans[MAXQ];
	vector <pair <pair <int, int>, int>> q[MAXN];
	void work(int pos) {
		for (auto x : s[pos])
			ST.modify(rt[pos], x.first, x.second);
		for (auto x : e[pos]) {
			work(x);
			ST.join(rt[pos], rt[x]);
		}
		for (auto x : q[pos])
			ans[x.second] = ST.query(rt[pos], x.first.first, x.first.second);
	}
	void solve(int m) {
		for (int i = 1; i <= size; i++)
			e[a[i].father].push_back(i);
		for (int i = 1; i <= n; i++)
		for (unsigned j = 0; j < home[i].size(); j++)
			s[home[i][j]].emplace_back(i, 1);
		work(0);
		for (int i = 1; i <= m; i++)
			writeln(ans[i]);
	}
} SAM;
char s[MAXN];
int main() {
	int n, m; read(n), read(m);
	SAM.init(), ST.init(n);
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s + 1);
		SAM.insert(s);
	}
	for (int i = 1; i <= m; i++) {
		int l, r, k; read(l), read(r), read(k);
		SAM.q[SAM.home[k].back()].emplace_back(make_pair(l, r), i);
	}
	SAM.solve(m);
	return 0;
}