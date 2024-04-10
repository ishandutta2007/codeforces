#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXLOG = 20;
const int MAXP = 1.2e6 + 5;
const int MAXQ = 1.2e7 + 5;
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
struct info {int pos, cnt; };
void chkmax(info &x, info y) {
	if (x.cnt < y.cnt) x = y;
	else if (x.cnt == y.cnt && x.pos > y.pos) x = y;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		info Max;
		bool leaf;
	} a[MAXQ];
	int size, n;
	void init(int x) {
		n = x;
		size = 0;
	}
	void update(int root) {
		a[root].Max = (info) {n, 0};
		if (a[root].lc) chkmax(a[root].Max, a[a[root].lc].Max);
		if (a[root].rc) chkmax(a[root].Max, a[a[root].rc].Max);
	}
	void modify(int &root, int l, int r, int pos) {
		if (root == 0) root = ++size;
		if (l == r) {
			a[root].Max.pos = l;
			a[root].Max.cnt++;
			a[root].leaf = true;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos);
		else modify(a[root].rc, mid + 1, r, pos);
		update(root);
	}
	void modify(int &root, int val) {
		return modify(root, 1, n, val);
	}
	int merge(int x, int y) {
		if (x == 0 || y == 0) return x + y;
		if (a[x].leaf) {
			a[x].Max.cnt += a[y].Max.cnt;
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
	info query(int root, int l, int r, int ql, int qr) {
		if (root == 0) return (info) {ql, 0};
		if (l == ql && r == qr) return a[root].Max;
		info ans = (info) {n, 0};
		int mid = (l + r) / 2;
		if (mid >= ql) chkmax(ans, query(a[root].lc, l, mid, ql, min(mid, qr)));
		if (mid + 1 <= qr) chkmax(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	info query(int root, int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST; 
struct SuffixAutomaton {
	struct Node {
		int child[26], parent[MAXLOG];
		int father, depth, root;
		vector <int> l, r, home;
	} a[MAXP];
	vector <int> t[MAXP];
	int n, m, q, home[MAXN];
	int root, last, size;
	info ans[MAXN];
	char s[MAXN];
	int newnode(int depth) {
		a[size].depth = depth;
		return size++;
	}
	void extend(int ch) {
		int p = last;
		if (a[p].child[ch] != 0) {
			int q = a[p].child[ch];
			if (a[p].depth + 1 == a[q].depth) last = q;
			else {
				int np = newnode(a[p].depth + 1);
				while (a[p].child[ch] == q) {
					a[p].child[ch] = np;
					p = a[p].father;
				}
				a[np].father = a[q].father;
				a[q].father = np;
				memcpy(a[np].child, a[q].child, sizeof(a[q].child));
				last = np;
			}
		} else {
			int np = newnode(a[p].depth + 1);
			while (a[p].child[ch] == 0) {
				a[p].child[ch] = np;
				p = a[p].father;
			}
			if (a[p].child[ch] == np) a[last = np].father = root;
			else {
				int q = a[p].child[ch];
				if (a[p].depth + 1 == a[q].depth) a[last = np].father = q;
				else {
					int nq = newnode(a[p].depth + 1);
					a[nq].father = a[q].father;
					a[q].father = a[np].father = nq;
					memcpy(a[nq].child, a[q].child, sizeof(a[q].child));
					while (a[p].child[ch] == q) {
						a[p].child[ch] = nq;
						p = a[p].father;
					}
					last = np;
				}
			}
		}
	}
	void init() {
		scanf("\n%s", s + 1);
		n = strlen(s + 1);
		size = 0;
		last = root = newnode(0);
		for (int i = 1; i <= n; i++) {
			extend(s[i] - 'a');
			home[i] = last;
		}
		read(m);
		ST.init(m);
		for (int i = 1; i <= m; i++) {
			scanf("\n%s", s + 1);
			int len = strlen(s + 1);
			last = root;
			for (int j = 1; j <= len; j++) {
				extend(s[j] - 'a');
				ST.modify(a[last].root, i);
			}
		}
		for (int i = 1; i < size; i++) {
			a[i].parent[0] = a[i].father;
			t[a[i].father].push_back(i);
		}
		for (int p = 1; p < MAXLOG; p++)
		for (int i = 0; i < size; i++)
			a[i].parent[p] = a[a[i].parent[p - 1]].parent[p - 1];
	}
	void storequery(int num, int pl, int pr, int l, int r) {
		int len = r - l + 1, pos = home[r];
		for (int i = MAXLOG - 1; i >= 0; i--)
			if (a[a[pos].parent[i]].depth >= len) pos = a[pos].parent[i];
		a[pos].l.push_back(pl);
		a[pos].r.push_back(pr);
		a[pos].home.push_back(num);
	}
	void work(int root) {
		for (unsigned i = 0; i < t[root].size(); i++) {
			work(t[root][i]);
			ST.join(a[root].root, a[t[root][i]].root);
		}
		for (unsigned i = 0; i < a[root].l.size(); i++)
			ans[a[root].home[i]] = ST.query(a[root].root, a[root].l[i], a[root].r[i]);
	}
	void calc(int x) {
		q = x; work(root);
		for (int i = 1; i <= q; i++)
			write(ans[i].pos), putchar(' '), writeln(ans[i].cnt);
	}
} SAM;
int main() {
	SAM.init();
	int q; read(q);
	for (int i = 1; i <= q; i++) {
		int l, r, pl, pr;
		read(l), read(r), read(pl), read(pr);
		SAM.storequery(i, l, r, pl, pr);
	}
	SAM.calc(q);
	return 0;
}