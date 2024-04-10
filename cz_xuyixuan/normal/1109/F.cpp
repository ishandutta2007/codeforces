#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int MAXM = 2e5 + 5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
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
struct LinkCutTree {
	struct Node {
		int child[2];
		int father, up;
		bool rev;
	} a[MAXM];
	int size;
	void pushdown(int root) {
		if (a[root].rev) {
			swap(a[root].child[0], a[root].child[1]);
			if (a[root].child[0]) a[a[root].child[0]].rev ^= true;
			if (a[root].child[1]) a[a[root].child[1]].rev ^= true;
			a[root].rev = false;
		}
	}
	bool get(int root) {return a[a[root].father].child[1] == root; }
	void rotate(int x) {
		int f = a[x].father, g = a[f].father;
		pushdown(f); pushdown(x);
		bool tmp = get(x), tnp = get(f);
		a[a[x].child[tmp ^ 1]].father = f;
		a[f].child[tmp] = a[x].child[tmp ^ 1];
		a[x].child[tmp ^ 1] = f;
		a[f].father = x;
		a[x].father = g;
		if (g != 0) a[g].child[tnp] = x;
		a[x].up = a[f].up;
		a[f].up = 0;
	}
	void splay(int x) {
		pushdown(x);
		for (int f = a[x].father; (f = a[x].father) != 0; rotate(x)) {
			pushdown(f); pushdown(x);
			if (a[f].father != 0) {
				if (get(f) == get(x)) rotate(f);
				else rotate(x);
			}
		}
	}
	void access(int x) {
		splay(x);
		int tmp = a[x].child[1];
		a[x].child[1] = 0;
		a[tmp].father = 0;
		a[tmp].up = x;
		while (a[x].up) {
			int f = a[x].up;
			splay(f);
			tmp = a[f].child[1];
			a[f].child[1] = x;
			a[x].father = f;
			a[x].up = 0;
			a[tmp].father = 0;
			a[tmp].up = f;
			splay(x);
		}
	}
	int findroot(int x) {
		access(x);
		splay(x);
		pushdown(x);
		while (a[x].child[0]) {
			x = a[x].child[0];
			pushdown(x);
		}
		splay(x);
		return x;
	}
	void makeroot(int x) {
		access(x);
		splay(x);
		a[x].rev ^= true;
		pushdown(x);
	}
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			size++;
			a[size].child[0] = 0;
			a[size].child[1] = 0;
			a[size].up = 0;
			a[size].father = 0;
		}
	}
	bool query(int x, int y) {
		return findroot(x) != findroot(y);
	}
	void link(int x, int y) {
		if (findroot(x) == findroot(y)) assert(false);
		makeroot(x);
		access(y);
		splay(y);
		a[x].father = y;
		a[y].child[1] = x;
	}
	void cut(int x, int y) {
		if (findroot(x) != findroot(y)) assert(false);
		makeroot(x);
		access(y);
		splay(x);
		if (a[x].child[1] != y) assert(false);
		a[x].child[1] = 0;
		a[y].father = 0;
	}
} LCT;
struct info {int Min, cnt; };
info operator + (info a, info b) {
	info ans; ans.cnt = 0;
	ans.Min = min(a.Min, b.Min);
	if (ans.Min == a.Min) ans.cnt += a.cnt;
	if (ans.Min == b.Min) ans.cnt += b.cnt;
	return ans;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		int tag; info ans;
	} a[MAXM * 2];
	int n, root, size;
	void update(int root) {
		a[root].ans = a[a[root].lc].ans + a[a[root].rc].ans;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].ans = (info) {l, 1};
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x, size = root = 0;
		build(root, 1, n);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].ans.Min += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].ans.Min += a[root].tag;
			a[root].tag = 0;
		}
	}
	void add(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].ans.Min += d;
			a[root].tag += d;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) add(a[root].lc, l, mid, ql, min(qr, mid), d);
		if (mid + 1 <= qr) add(a[root].rc, mid + 1, r, max(ql, mid + 1), qr, d);
		update(root);
	}
	void add(int l, int r, int d) {
		add(root, 1, n, l, r, d);
	}
	info query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].ans;
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return query(a[root].lc, l, mid, ql, mid) + query(a[root].rc, mid + 1, r, mid + 1, qr);
	}
	info query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
int n, m, a[MAXN][MAXN];
int x[MAXM], y[MAXM];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
		read(a[i][j]);
		x[a[i][j]] = i;
		y[a[i][j]] = j;
	}
	ST.init(n * m);
	LCT.init(n * m);
	ll ans = 0;
	for (int i = 1, j = 1; i <= n * m; i++) {
		while (j + 1 <= n * m) {
			bool ok = true;
			vector <int> tmp;
			for (int k = 0; k <= 3; k++) {
				int tx = x[j + 1] + dx[k];
				int ty = y[j + 1] + dy[k];
				if (a[tx][ty] >= i && a[tx][ty] < j + 1 && ok) {
					ok &= LCT.query(j + 1, a[tx][ty]);
					if (ok) {
						LCT.link(j + 1, a[tx][ty]);
						tmp.push_back(a[tx][ty]);
					}
				}
			}
			if (ok) {
				j++;
				for (int k = 0; k <= 3; k++) {
					int tx = x[j] + dx[k];
					int ty = y[j] + dy[k];
					if (a[tx][ty] >= i && a[tx][ty] < j) {
						ST.add(j, n * m, -1);
					}
				}
			} else {
				for (auto x : tmp)
					LCT.cut(j + 1, x);
				break;
			}
		}
		info tmp = ST.query(i, j);
		if (tmp.Min == i) ans += tmp.cnt;
		for (int k = 0; k <= 3; k++) {
			int tx = x[i] + dx[k];
			int ty = y[i] + dy[k];
			if (a[tx][ty] > i && a[tx][ty] <= j) {
				LCT.cut(i, a[tx][ty]);
				ST.add(a[tx][ty], n * m, 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}