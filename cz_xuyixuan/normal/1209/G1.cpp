#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
struct SegmentTreeMax {
	struct Node {
		int lc, rc;
		int Max;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].Max = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	void modify(int root, int l, int r, int pos, int val) {
		if (l == r) {
			a[root].Max = val;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val);
		else modify(a[root].rc, mid + 1, r, pos, val);
		update(root);
	}
	void modify(int pos, int val) {
		modify(root, 1, n, pos, val);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2, ans = 0;
		if (mid >= ql) chkmax(ans, query(a[root].lc, l, mid, ql, min(mid, qr)));
		if (mid + 1 <= qr) chkmax(ans, query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	int query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} STA;
struct info {int Min, l, r, sum; };
info operator + (info a, info b) {
	if (a.Min < b.Min) return a;
	if (b.Min < a.Min) return b;
	info ans; ans.Min = a.Min;
	ans.l = a.l, ans.r = b.r;
	ans.sum = a.sum + b.sum + STA.query(a.r + 1, b.l);
	return ans;
}
struct SegmentTreeMin {
	struct Node {
		int lc, rc, tag;
		info ans;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].ans = a[a[root].lc].ans + a[a[root].rc].ans;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].ans = (info) {0, l, l, 0};
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 0, n);
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
	void modify(int root, int l, int r, int pos, int val) {
		if (l == r) {
			STA.modify(pos, val);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val);
		else modify(a[root].rc, mid + 1, r, pos, val);
		update(root);
	}
	void modify(int pos, int val) {
		modify(root, 0, n, pos, val);
	}
	void modify(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].ans.Min += d;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void modify(int l, int r, int d) {
		modify(root, 0, n, l, r, d);
	}
} STI;
int n, q, Max, a[MAXN];
set <int> pos[MAXN];
int main() {
	read(n), read(q);
	for (int i = 1; i <= n; i++) {
		read(a[i]), chkmax(Max, a[i]);
		pos[a[i]].insert(i);
	}
	STA.init(n);
	STI.init(n);
	for (int i = 1; i <= Max; i++)
		if (pos[i].size()) {
			STI.modify(*pos[i].begin(), pos[i].size());
			if (pos[i].size() >= 2) {
				auto tmp = pos[i].end(); tmp--;
				STI.modify(*pos[i].begin(), *tmp - 1, 1);
			}
		}
	writeln(n - STI.a[STI.root].ans.sum);
	while (q--) {
		int x, v;
		read(x), read(v);
		STI.modify(*pos[a[x]].begin(), 0);
		if (pos[a[x]].size() >= 2) {
			auto tmp = pos[a[x]].end(); tmp--;
			STI.modify(*pos[a[x]].begin(), *tmp - 1, -1);
		}
		pos[a[x]].erase(x);
		if (pos[a[x]].size()) {
			STI.modify(*pos[a[x]].begin(), pos[a[x]].size());
			if (pos[a[x]].size() >= 2) {
				auto tmp = pos[a[x]].end(); tmp--;
				STI.modify(*pos[a[x]].begin(), *tmp - 1, 1);
			}
		}
		a[x] = v;
		if (pos[a[x]].size()) {
			STI.modify(*pos[a[x]].begin(), 0);
			if (pos[a[x]].size() >= 2) {
				auto tmp = pos[a[x]].end(); tmp--;
				STI.modify(*pos[a[x]].begin(), *tmp - 1, -1);
			}
		}
		pos[a[x]].insert(x);
		STI.modify(*pos[a[x]].begin(), pos[a[x]].size());
		if (pos[a[x]].size() >= 2) {
			auto tmp = pos[a[x]].end(); tmp--;
			STI.modify(*pos[a[x]].begin(), *tmp - 1, 1);
		}
		writeln(n - STI.a[STI.root].ans.sum);
	}
	return 0;
}