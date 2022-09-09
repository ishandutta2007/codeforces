#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
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
struct SegmentTree {
	struct Node {
		int lc, rc;
		int tag, Max;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].tag = 0;
		a[root].Max = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].tag += a[root].tag;
			a[a[root].lc].Max += a[root].tag;
			a[a[root].rc].tag += a[root].tag;
			a[a[root].rc].Max += a[root].tag;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Max += d;
			return;
		}
		int mid = (l + r) / 2;
		pushdown(root);
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, int d) {
		modify(root, 1, n, l, r, d);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2; pushdown(root);
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return max(query(a[root].lc, l, mid, ql, mid), query(a[root].rc, mid + 1, r, mid + 1, qr));
	}
	int query(int l, int r) {
		if (l > r) return 0;
		else return query(root, 1, n, l, r);
	}
} ST;
int n;
pair <int, int> a[MAXN], b[MAXN];
bool check() {
	static vector <pair <int, int>> ins[MAXN], qry[MAXN];
	for (int i = 1; i <= 4 * n; i++)
		ins[i].clear(), qry[i].clear();
	ST.init(4 * n);
	for (int i = 1; i <= n; i++) {
		qry[a[i].first].push_back(b[i]);
		ins[a[i].second].push_back(b[i]);
	}
	for (int i = 1; i <= 4 * n; i++) {
		for (auto x : qry[i])
			if (ST.query(x.first, x.second) != 0) return true;
		for (auto x : ins[i])
			ST.modify(x.first, x.second, 1);
	}
	return false;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].first), read(a[i].second);
		read(b[i].first), read(b[i].second);
	}
	set <int> num; map <int, int> home;
	for (int i = 1; i <= n; i++) {
		num.insert(a[i].first);
		num.insert(a[i].second);
	}
	int cnt = 0;
	for (auto x : num)
		home[x] = ++cnt;
	for (int i = 1; i <= n; i++) {
		a[i].first = home[a[i].first];
		a[i].second = home[a[i].second];
	}
	num.clear(), home.clear();
	
	for (int i = 1; i <= n; i++) {
		num.insert(b[i].first);
		num.insert(b[i].second);
	}
	cnt = 0;
	for (auto x : num)
		home[x] = ++cnt;
	for (int i = 1; i <= n; i++) {
		b[i].first = home[b[i].first];
		b[i].second = home[b[i].second];
	}
	
	if (check()) {
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		swap(a[i], b[i]);
	if (check()) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}