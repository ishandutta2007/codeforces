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
struct Treap {
	struct Node {
		ll sum, tag, val; unsigned rnd;
		int child[2], father, size;
	} a[MAXN];
	int root, size;
	unsigned seed;
	void init() {
		srand('X' + 'Y' + 'X');
		root = size = 0;
		seed = 1258553509u;
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].child[0]].sum += a[a[root].child[0]].size * a[root].tag;
			a[a[root].child[0]].tag += a[root].tag;
			a[a[root].child[1]].sum += a[a[root].child[1]].size * a[root].tag;
			a[a[root].child[1]].tag += a[root].tag;
			a[root].val += a[root].tag;
			a[root].tag = 0;
		}
	}
	void update(int root) {
		a[root].sum += a[root].val, a[root].size = 1;
		if (a[root].child[0]) {
			a[root].sum += a[a[root].child[0]].sum;
			a[root].size += a[a[root].child[0]].size;
		}
		if (a[root].child[1]) {
			a[root].sum += a[a[root].child[1]].sum;
			a[root].size += a[a[root].child[1]].size;
		}
	}
	void add(int root, int l, int r, ll x) {
		if (l == 1 && r == a[root].size) {
			a[root].tag += x;
			a[root].sum += a[root].size * x;
			return;
		}
		pushdown(root);
		if (l <= a[a[root].child[0]].size + 1 && r >= a[a[root].child[0]].size + 1) a[root].val += x;
		if (a[root].child[0] && l <= a[a[root].child[0]].size) add(a[root].child[0], l, min(r, a[a[root].child[0]].size), x);
		l -= a[a[root].child[0]].size + 1, r -= a[a[root].child[0]].size + 1;
		if (a[root].child[1] && r >= 1) add(a[root].child[1], max(l, 1), r, x);
		update(root);
	}
	unsigned rnd() {
		seed = seed * seed + rand();
		return seed;
	}
	bool get(int x) {
		return a[a[x].father].child[1] == x;
	}
	void rotate(int x) {
		int f = a[x].father, g = a[f].father;
		pushdown(f), pushdown(x);
		bool tmp = get(x);
		a[x].father = g;
		if (g != 0) a[g].child[get(f)] = x;
		a[f].child[tmp] = a[x].child[tmp ^ 1];
		a[a[x].child[tmp ^ 1]].father = f;
		a[x].child[tmp ^ 1] = f;
		a[f].father = x;
		update(f), update(x);
	}
	void treap(int x) {
		while (a[x].father && a[x].rnd < a[a[x].father].rnd) rotate(x);
		if (a[x].father == 0) root = x;
	}
	int newnode(ll val) {
		size++;
		a[size].val = val;
		a[size].rnd = rnd();
		update(size);
		return size;
	}
	void ins(int pos, ll val) {
		if (root == 0) {
			root = newnode(val);
			return;
		}
		int x = root;
		while (true) {
			pushdown(x);
			a[x].size++, a[x].sum += val;
			if (pos <= a[a[x].child[0]].size + 1) {
				if (a[x].child[0]) x = a[x].child[0];
				else {
					a[x].child[0] = newnode(val);
					a[size].father = x;
					treap(size);
					return;
				}
			} else {
				pos -= a[a[x].child[0]].size + 1;
				if (a[x].child[1]) x = a[x].child[1];
				else {
					a[x].child[1] = newnode(val);
					a[size].father = x;
					treap(size);
					return;
				}
			}
		}
	}
	void trans(int val) {
		int res = size + 1;
		if (root != 0) {
			int x = root, cnt = 0;
			while (true) {
				pushdown(x);
				int rnk = cnt + a[a[x].child[0]].size + 1;
				if (1ll * val * rnk >= a[x].val) {
					res = rnk;
					if (a[x].child[0]) x = a[x].child[0];
					else break;
				} else {
					cnt += a[a[x].child[0]].size + 1;
					if (a[x].child[1]) x = a[x].child[1];
					else break;
				}
			}
		}
		ins(res, 1ll * res * val);
		if (res != size) add(root, res + 1, size, val);
	}
	ll ans, now;
	void getans(int root) {
		pushdown(root);
		if (a[root].child[0]) getans(a[root].child[0]);
		now += a[root].val, chkmax(ans, now);
		if (a[root].child[1]) getans(a[root].child[1]);
	}
	void getans() {
		ans = now = 0;
		getans(root);
		cout << ans << endl;
	}
} Treap;
int main() {
	int n; read(n);
	Treap.init();
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		Treap.trans(x);
	}
	Treap.getans();
	return 0;
}