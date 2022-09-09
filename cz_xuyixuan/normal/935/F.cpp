#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
struct info {int cnt, pos; };
info operator + (info a, info b) {
	info ans;
	ans.cnt = a.cnt + b.cnt;
	if (ans.cnt == 1) ans.pos = a.pos + b.pos;
	else if (a.pos) ans.pos = a.pos; else ans.pos = b.pos;
	return ans;
}
struct SegmentTree {
	struct Node{
		int lc, rc;
		info top, low;
		long long Min, Max;
	} a[MAXN * 2];
	int n, size, root;
	void update(int root) {
		int lc = a[root].lc, rc = a[root].rc;
		a[root].Min = min(a[lc].Min, a[rc].Min);
		a[root].Max = max(a[lc].Max, a[rc].Max);
		a[root].top = a[lc].top + a[rc].top;
		a[root].low = a[lc].low + a[rc].low;
	}
	void build(int &root, int l, int r, long long *val) {
		root = ++size;
		if (l == r) {
			a[root].Min = a[root].Max = val[l];
			if (l != n) {
				bool tlow = val[l] <= 0 && val[l + 1] >= 0;
				a[root].low = (info) {tlow, l * tlow};
				bool ttop = val[l] >= 0 && val[l + 1] <= 0;
				a[root].top = (info) {ttop, l * ttop};
			} else {
				a[root].low = (info) {0, 0};
				a[root].top = (info) {0, 0};
			}
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, val);
		build(a[root].rc, mid + 1, r, val);
		update(root);
	}
	void init(int x, long long *val) {
		n = x;
		root = size = 0;
		build(root, 1, n, val);
	}
	void modify(int root, int l, int r, int pos, long long val, bool ttop, bool tlow) {
		if (l == r) {
			a[root].Min = a[root].Max = val;
			a[root].top = (info) {ttop, l * ttop};
			a[root].low = (info) {tlow, l * tlow};
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val, ttop, tlow);
		else modify(a[root].rc, mid + 1, r, pos, val, ttop, tlow);
		update(root);
	}
	long long queryval(int root, int l, int r, int pos) {
		if (l == r) return a[root].Max;
		int mid = (l + r) / 2;
		if (mid >= pos) return queryval(a[root].lc, l, mid, pos);
		else return queryval(a[root].rc, mid + 1, r, pos);
	}
	long long queryval(int pos) {
		return queryval(root, 1, n, pos);
	}
	void Modify(int pos, long long val) {
		if (pos != n) {
			long long tmp = queryval(root, 1, n, pos + 1);
			bool ttop = false, tlow = false;
			if (val <= 0 && tmp >= 0) tlow = true;
			if (val >= 0 && tmp <= 0) ttop = true;
			modify(root, 1, n, pos, val, ttop, tlow);
		} else modify(root, 1, n, pos, val, false, false);
	}
	void modify(int pos, long long val) {
		if (pos != n) {
			long long tmp = queryval(root, 1, n, pos + 1);
			bool ttop = false, tlow = false;
			if (val <= 0 && tmp >= 0) tlow = true;
			if (val >= 0 && tmp <= 0) ttop = true;
			modify(root, 1, n, pos, val, ttop, tlow);
		} else modify(root, 1, n, pos, val, false, false);
		if (pos != 1) Modify(pos - 1, queryval(root, 1, n, pos - 1));
	}
	info querylow(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].low;
		int mid = (l + r) / 2;
		info ans = (info) {0, 0};
		if (mid >= ql) ans = ans + querylow(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans = ans + querylow(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	info querylow(int l, int r) {
		return querylow(root, 1, n, l, r);
	}
	info querytop(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].top;
		int mid = (l + r) / 2;
		info ans = (info) {0, 0};
		if (mid >= ql) ans = ans + querytop(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans = ans + querytop(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	info querytop(int l, int r) {
		return querytop(root, 1, n, l, r);
	}
	long long querymax(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Max;
		int mid = (l + r) / 2;
		long long ans = -LLONG_MAX;
		if (mid >= ql) ans = max(ans, querymax(a[root].lc, l, mid, ql, min(qr, mid)));
		if (mid + 1 <= qr) ans = max(ans, querymax(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	long long querymax(int l, int r) {
		return querymax(root, 1, n, l, r);
	}
	long long querymin(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].Min;
		int mid = (l + r) / 2;
		long long ans = LLONG_MAX;
		if (mid >= ql) ans = min(ans, querymin(a[root].lc, l, mid, ql, min(qr, mid)));
		if (mid + 1 <= qr) ans = min(ans, querymin(a[root].rc, mid + 1, r, max(mid + 1, ql), qr));
		return ans;
	}
	long long querymin(int l, int r) {
		return querymin(root, 1, n, l, r);
	}
} ST;
int n, q;
long long sum, a[MAXN];
void add(int l, int r, int d) {
	if (l != 1) sum -= abs(a[l]);
	sum -= abs(a[r + 1]);
	a[l] += d, ST.modify(l, a[l]);
	if (r != n) a[r + 1] -= d, ST.modify(r + 1, a[r + 1]);
	if (l != 1) sum += abs(a[l]);
	sum += abs(a[r + 1]);
}
void judge(long long &ans, int x, int l, int r) {
	if (l > r) return;
	long long tmp = sum + 2 * x;
	if (ST.queryval(l) <= 0) ans = max(ans, tmp - 2 * min(x * 1ll, abs(ST.querymax(l, r))));
	else ans = max(ans, tmp - 2 * min(x * 1ll, abs(ST.querymin(l, r))));
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = n; i >= 2; i--) {
		a[i] -= a[i - 1];
		sum += abs(a[i]);
	}
	ST.init(n, a);
	read(q);
	while (q--) {
		int opt, l, r, x;
		read(opt), read(l), read(r), read(x);
		if (opt == 2) add(l, r, x);
		else {
			long long ans = 0;
			add(l, l, x); ans = max(ans, sum); add(l, l, -x);
			add(r, r, x); ans = max(ans, sum); add(r, r, -x);
			if (r - l <= 1) {
				writeln(ans);
				continue;
			}
			add(l + 1, l + 1, x); ans = max(ans, sum); add(l + 1, l + 1, -x);
			add(r - 1, r - 1, x); ans = max(ans, sum); add(r - 1, r - 1, -x);
			info tmp = ST.querylow(l + 1, r);
			info tnp = ST.querytop(l + 1, r);
			if (tnp.cnt != 0) {
				writeln(sum + 2 * x);
				continue;
			}
			if (tmp.cnt != 0) {
				add(tmp.pos, tmp.pos, x); ans = max(ans, sum); add(tmp.pos, tmp.pos, -x);
				if (tmp.pos != l) add(tmp.pos - 1, tmp.pos - 1, x), ans = max(ans, sum), add(tmp.pos - 1, tmp.pos - 1, -x);
				if (tmp.pos != r) add(tmp.pos + 1, tmp.pos + 1, x), ans = max(ans, sum), add(tmp.pos + 1, tmp.pos + 1, -x);
				judge(ans, x, l + 2, tmp.pos - 1);
				judge(ans, x, tmp.pos + 2, r - 1);
			} else judge(ans, x, l + 2, r - 1);
			writeln(ans);
		}
	}
	return 0;
}