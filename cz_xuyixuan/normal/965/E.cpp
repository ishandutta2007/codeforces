#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXP = 1e7 + 5;
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
		int sum, Max;
	} a[MAXP];
	int size, n;
	void init(int x) {
		n = x;
		size = 0;
		a[0].sum = 0;
		a[0].Max = -1;
	}
	void update(int root) {
		a[root].Max = -1; a[root].sum = 0;
		chkmax(a[root].Max, a[a[root].lc].Max);
		chkmax(a[root].Max, a[a[root].rc].Max);
		a[root].sum += a[a[root].lc].sum;
		a[root].sum += a[a[root].rc].sum;
	}
	void modify(int &root, int l, int r, int pos, int d) {
		if (root == 0) root = ++size;
		if (l == r) {
			a[root].sum += d;
			if (a[root].sum) a[root].Max = l;
			else a[root].Max = -1;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, d);
		else modify(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modify(int &root, int pos, int d) {
		modify(root, 0, n, pos, d);
	}
	int merge(int x, int y, int l, int r) {
		if (x == 0 || y == 0) return x + y;
		if (l == r) {
			a[x].sum += a[y].sum;
			if (a[x].sum) a[x].Max = l;
			else a[x].Max = -1;
			return x;
		}
		int mid = (l + r) / 2;
		a[x].lc = merge(a[x].lc, a[y].lc, l, mid);
		a[x].rc = merge(a[x].rc, a[y].rc, mid + 1, r);
		update(x);
		return x;
	}
	int merge(int x, int y) {
		return merge(x, y, 0, n);
	}
	void trans(int root, int depth) {
		if (a[root].Max == -1) return;
		modify(root, a[root].Max, -1);
		modify(root, depth, 1);
	}
	long long getans(int root, int l, int r) {
		if (root == 0) return 0;
		if (l == r) return 1ll * a[root].sum * l;
		int mid = (l + r) / 2;
		return getans(a[root].lc, l, mid) + getans(a[root].rc, mid + 1, r);
	}
	long long getans(int root) {
		return getans(root, 0, n);
	}
} ST;
struct Trie {
	struct Node {
		int child[26];
		int depth, root;
	} a[MAXN];
	int root, size;
	void init() {
		root = 0;
		a[root].depth = 0;
		ST.modify(a[root].root, 0, 1);
	}
	void insert(char *s) {
		int len = strlen(s + 1), now = root;
		for (int i = 1; i <= len; i++) {
			int tmp = s[i] - 'a';
			if (a[now].child[tmp] == 0) {
				a[now].child[tmp] = ++size;
				a[size].depth = a[now].depth + 1;
			}
			now = a[now].child[tmp];
		}
		ST.modify(a[now].root, a[now].depth, 1);
	}
	long long getans() {
		static int q[MAXN], cnt[MAXN];
		for (int i = 0; i <= size; i++)
			cnt[a[i].depth]++;
		for (int i = 1; i <= size; i++)
			cnt[i] += cnt[i - 1];
		for (int i = 0; i <= size; i++)
			q[--cnt[a[i].depth]] = i;
		for (int i = size; i >= 0; i--) {
			int tmp = q[i];
			bool type = a[tmp].root == 0;
			for (int j = 0; j < 26; j++)
				if (a[tmp].child[j]) a[tmp].root = ST.merge(a[tmp].root, a[a[tmp].child[j]].root);
			if (type) ST.trans(a[tmp].root, a[tmp].depth);
		}
		return ST.getans(a[root].root);
	}
} Trie;
int n; char s[MAXN];
int main() {
	read(n);
	ST.init(MAXN - 1);
	Trie.init();
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		Trie.insert(s);
	}
	writeln(Trie.getans());
	return 0;
}