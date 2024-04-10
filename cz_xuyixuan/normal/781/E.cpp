#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int P = 1e9 + 7;
const int INF = 2e9;
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
struct ball {int cnt, height; };
bool operator < (ball a, ball b) {return a.height > b.height; }
struct SegmentTree {
	struct Node {
		int lc, rc;
		int Min;
	} a[MAXN * 2];
	int n, root, size;
	priority_queue <ball> Heap[MAXN];
	void update(int root) {
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
	}
	void build(int &root, int l, int r, int h) {
		root = ++size;
		if (l == r) {
			Heap[l].push((ball) {1, h + 1});
			a[root].Min = h + 1;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, h);
		build(a[root].rc, mid + 1, r, h);
		update(root);
	}
	void init(int h, int w) {
		n = w;
		root = size = 0;
		build(root, 1, w, h);
	}
	int query(int root, int u, int l, int r, int ql, int qr, int s) {
		int ans = 0;
		if (l == ql && r == qr) {
			if (l == r) {
				while (!Heap[l].empty() && Heap[l].top().height <= u + s) {
					ans = (ans + Heap[l].top().cnt) % P;
					Heap[l].pop();
				}
				if (Heap[l].empty()) a[root].Min = INF;
				else a[root].Min = Heap[l].top().height;
				return ans;
			}
			int mid = (l + r) / 2;
			if (u + s >= a[a[root].lc].Min) ans += query(a[root].lc, u, l, mid, ql, min(mid, qr), s);
			if (u + s >= a[a[root].rc].Min) ans += query(a[root].rc, u, mid + 1, r, max(mid + 1, ql), qr, s);
		} else {
			int mid = (l + r) / 2;
			if (mid >= ql) ans += query(a[root].lc, u, l, mid, ql, min(mid, qr), s);
			if (mid + 1 <= qr) ans += query(a[root].rc, u, mid + 1, r, max(mid + 1, ql), qr, s);
		}
		update(root);
		return ans % P;
	}
	void modify(int root, int l, int r, int pos, ball d) {
		if (l == r) {
			Heap[l].push(d);
			a[root].Min = Heap[l].top().height;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, d);
		else modify(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modify(int u, int l, int r, int s) {
		int tmp = query(root, u, 1, n, l, r, s);
		if (l == 1) modify(root, 1, n, r + 1, (ball) {tmp, u});
		else modify(root, 1, n, l - 1, (ball) {tmp, u});
		if (r == n) modify(root, 1, n, l - 1, (ball) {tmp, u});
		else modify(root, 1, n, r + 1, (ball) {tmp, u});
	}
	int getans() {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			while (!Heap[i].empty()) {
				ans = (ans + Heap[i].top().cnt) % P;
				Heap[i].pop();
			}
		}
		return ans;
	}
} ST;
struct info {int u, l, r, s; } a[MAXN];
bool cmp(info a, info b) {
	return a.u > b.u;
}
int main() {
	int h, w, n;
	read(h), read(w), read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].u), read(a[i].l);
		read(a[i].r), read(a[i].s);
	}
	sort(a + 1, a + n + 1, cmp);
	ST.init(h, w);
	for (int i = 1; i <= n; i++)
		ST.modify(a[i].u, a[i].l, a[i].r, a[i].s);
	writeln(ST.getans());
	return 0;
}