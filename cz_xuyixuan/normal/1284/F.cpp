#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int f[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
struct LinkCutTree {
	struct Node {
		int child[2];
		int val, sum;
		int father, up;
		bool rev;
	} a[MAXN];
	int size;
	void pushdown(int root) {
		if (a[root].rev) {
			swap(a[root].child[0], a[root].child[1]);
			if (a[root].child[0]) a[a[root].child[0]].rev ^= true;
			if (a[root].child[1]) a[a[root].child[1]].rev ^= true;
			a[root].rev = false;
		}
	}
	void update(int root) {
		a[root].sum = a[root].val;
		if (a[root].child[0]) a[root].sum += a[a[root].child[0]].sum;
		if (a[root].child[1]) a[root].sum += a[a[root].child[1]].sum;
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
		update(f); update(x);
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
		update(x);
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
			update(f);
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
	void maketree(int val) {
		size++;
		a[size].child[0] = 0;
		a[size].child[1] = 0;
		a[size].up = 0;
		a[size].val = val;
		a[size].sum = val;
		a[size].father = 0;
	}
	void link(int x, int y) {
		if (findroot(x) == findroot(y)) {
			assert(false);
			return;
		}
		makeroot(x);
		access(y);
		splay(y);
		a[x].father = y;
		a[y].child[1] = x;
		update(x);
	}
	void cut(int x, int y) {
		if (findroot(x) != findroot(y)) {
			assert(false);
			return;
		}
		makeroot(x);
		access(y);
		splay(x);
		if (a[x].child[1] != y) {
			assert(false);
			return;
		}
		a[x].child[1] = 0;
		a[y].father = 0;
		update(x);
	}
	int query(int x, int y) {
		makeroot(x);
		access(y);
		splay(y);
		return a[y].sum;
	}
	void modify(int x, int val) {
		makeroot(x);
		splay(x);
		a[x].val = val;
		update(x);
	}
	pair <int, int> findcut(int x, int y) {
		makeroot(x);
		access(y), splay(y);
		assert(find(x) != find(y));
		int last = y;
		pair <int, int> res = make_pair(-1, -1);
		while (y != 0) {
			last = y;
			pushdown(y);
			if (find(y) == find(x)) {
				res.first = y;
				y = a[y].child[1];
			} else {
				res.second = y;
				y = a[y].child[0];
			}
		}
		splay(last);
		return res;
	}
} LCT;
vector <int> a[MAXN];
void dfs(int pos, int fa) {
	for (auto x : a[pos])
		if (x != fa) {
			dfs(x, pos);
		}
	if (fa != 0) {
		pair <int, int> res = LCT.findcut(pos, fa);
		printf("%d %d %d %d\n", pos, fa, res.first, res.second);
		f[find(pos)] = find(fa);
		LCT.cut(res.first, res.second);
		LCT.link(pos, fa);
	}
}
int main() {
	int n; read(n);
	printf("%d\n", n - 1);
	for (int i = 1; i <= n; i++)
		LCT.maketree(1), f[i] = i;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		LCT.link(x, y);
	}
	dfs(1, 0);
	return 0;
}