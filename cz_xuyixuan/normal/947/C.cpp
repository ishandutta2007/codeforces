#include<bits/stdc++.h>
using namespace std;
const int MAXLOG = 30;
const int MAXN = 300005;
const int MAXP = 1.2e7 + 5;
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
struct Trie {
	struct Node {
		int child[2];
		int sum;
	} a[MAXP];
	int root, size;
	void init() {root = size = 0; }
	void insert(int &root, int depth, int val) {
		if (root == 0) root = ++size;
		a[root].sum++;
		if (depth == -1) return;
		int tmp = 1 << depth;
		if (tmp & val) insert(a[root].child[1], depth - 1, val);
		else insert(a[root].child[0], depth - 1, val);
	}
	void insert(int x) {insert(root, MAXLOG, x); }
	int query(int root, int depth, int val) {
		a[root].sum--;
		if (depth == -1) return 0;
		int tmp = 1 << depth;
		if ((tmp & val) == 0) {
			if (a[a[root].child[0]].sum) return query(a[root].child[0], depth - 1, val);
			else return query(a[root].child[1], depth - 1, val) + tmp;
		} else {
			if (a[a[root].child[1]].sum) return query(a[root].child[1], depth - 1, val);
			else return query(a[root].child[0], depth - 1, val) + tmp;
		}
	}
	int query(int x) {return query(root, MAXLOG, x); }
} T;
int a[MAXN];
int main() {
	T.init();
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		T.insert(x);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", T.query(a[i]));
	return 0;
}