#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF  = 1e9 + 7;
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
struct SegmentTreeChkmax {
	struct Node {
		ll sum; int lc, rc, tag, len;
		int cntMin, Min, Nin, tagMin;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].cntMin = 0;
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
		a[root].Nin = min(a[a[root].lc].Nin, a[a[root].rc].Nin);
		if (a[a[root].lc].Min != a[root].Min) chkmin(a[root].Nin, a[a[root].lc].Min);
		else a[root].cntMin += a[a[root].lc].cntMin;
		if (a[a[root].rc].Min != a[root].Min) chkmin(a[root].Nin, a[a[root].rc].Min);
		else a[root].cntMin += a[a[root].rc].cntMin;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].len = r - l + 1;
		if (l == r) {
			a[root].sum = 0;
			a[root].Min = 0;
			a[root].cntMin = 1;
			a[root].Nin = INF;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		build(root, 1, n);
	}
	void pushdown(int root) {
		int lc = a[root].lc;
		int rc = a[root].rc;
		if (a[root].tag) {
			a[lc].tag += a[root].tag;
			a[lc].sum += 1ll * a[lc].len * a[root].tag;
			a[lc].Min += a[root].tag;
			a[lc].Nin += a[root].tag;
			a[rc].tag += a[root].tag;
			a[rc].sum += 1ll * a[rc].len * a[root].tag;
			a[rc].Min += a[root].tag;
			a[rc].Nin += a[root].tag;
			a[root].tag = 0;
		}
		if (a[root].tagMin) {
			int Min = min(a[lc].Min, a[rc].Min);
			if (a[lc].Min == Min) {
				a[lc].Min += a[root].tagMin;
				a[lc].tagMin += a[root].tagMin;
				a[lc].sum += 1ll * a[lc].cntMin * a[root].tagMin;
			}
			if (a[rc].Min == Min) {
				a[rc].Min += a[root].tagMin;
				a[rc].tagMin += a[root].tagMin;
				a[rc].sum += 1ll * a[rc].cntMin * a[root].tagMin;
			}
			a[root].tagMin = 0;
		}
	}
	void add(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Min += d;
			a[root].Nin += d;
			a[root].sum += 1ll * d * a[root].len;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) add(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) add(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void add(int l, int r, int d) {
		add(root, 1, n, l, r, d);
	}
	void chkmax(int root, int l, int r, int ql, int qr, int d) {
		if (d <= a[root].Min) return;
		if (l == ql && r == qr) {
			if (d < a[root].Nin) {
				a[root].sum += 1ll * a[root].cntMin * (d - a[root].Min);
				a[root].tagMin += d - a[root].Min;
				a[root].Min = d;
				return;
			}
			pushdown(root);
			int mid = (l + r) / 2;
			chkmax(a[root].lc, l, mid, l, mid, d);
			chkmax(a[root].rc, mid + 1, r, mid + 1, r, d);
			update(root);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) chkmax(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) chkmax(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void chkmax(int l, int r, int d) {
		chkmax(root, 1, n, l, r, d);
	}
	ll query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		int mid = (l + r) / 2; ll ans = 0;
		pushdown(root);
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	ll query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} L;
struct SegmentTreeChkmin {
	struct Node {
		ll sum; int lc, rc, tag, len;
		int cntMax, Max, Nax, tagMax;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].cntMax = 0;
		a[root].sum = a[a[root].lc].sum + a[a[root].rc].sum;
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
		a[root].Nax = max(a[a[root].lc].Nax, a[a[root].rc].Nax);
		if (a[a[root].lc].Max != a[root].Max) chkmax(a[root].Nax, a[a[root].lc].Max);
		else a[root].cntMax += a[a[root].lc].cntMax;
		if (a[a[root].rc].Max != a[root].Max) chkmax(a[root].Nax, a[a[root].rc].Max);
		else a[root].cntMax += a[a[root].rc].cntMax;
	}
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].len = r - l + 1;
		if (l == r) {
			a[root].sum = 0;
			a[root].Max = 0;
			a[root].cntMax = 1;
			a[root].Nax = -INF;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x;
		build(root, 1, n);
	}
	void pushdown(int root) {
		int lc = a[root].lc;
		int rc = a[root].rc;
		if (a[root].tag) {
			a[lc].tag += a[root].tag;
			a[lc].sum += 1ll * a[lc].len * a[root].tag;
			a[lc].Max += a[root].tag;
			a[lc].Nax += a[root].tag;
			a[rc].tag += a[root].tag;
			a[rc].sum += 1ll * a[rc].len * a[root].tag;
			a[rc].Max += a[root].tag;
			a[rc].Nax += a[root].tag;
			a[root].tag = 0;
		}
		if (a[root].tagMax) {
			int Max = max(a[lc].Max, a[rc].Max);
			if (a[lc].Max == Max) {
				a[lc].Max += a[root].tagMax;
				a[lc].tagMax += a[root].tagMax;
				a[lc].sum += 1ll * a[lc].cntMax * a[root].tagMax;
			}
			if (a[rc].Max == Max) {
				a[rc].Max += a[root].tagMax;
				a[rc].tagMax += a[root].tagMax;
				a[rc].sum += 1ll * a[rc].cntMax * a[root].tagMax;
			}
			a[root].tagMax = 0;
		}
	}
	void add(int root, int l, int r, int ql, int qr, int d) {
		if (l == ql && r == qr) {
			a[root].tag += d;
			a[root].Max += d;
			a[root].Nax += d;
			a[root].sum += 1ll * d * a[root].len;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) add(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) add(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void add(int l, int r, int d) {
		add(root, 1, n, l, r, d);
	}
	void chkmin(int root, int l, int r, int ql, int qr, int d) {
		if (d >= a[root].Max) return;
		if (l == ql && r == qr) {
			if (d > a[root].Nax) {
				a[root].sum += 1ll * a[root].cntMax * (d - a[root].Max);
				a[root].tagMax += d - a[root].Max;
				a[root].Max = d;
				return;
			}
			pushdown(root);
			int mid = (l + r) / 2;
			chkmin(a[root].lc, l, mid, l, mid, d);
			chkmin(a[root].rc, mid + 1, r, mid + 1, r, d);
			update(root);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) chkmin(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) chkmin(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void chkmin(int l, int r, int d) {
		chkmin(root, 1, n, l, r, d);
	}
	ll query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		int mid = (l + r) / 2; ll ans = 0;
		pushdown(root);
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	ll query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} R;
int n, a[MAXN], home[MAXN];
int main() {
	read(n), L.init(n), R.init(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), home[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		int x = home[i];
		L.add(x, n, 1);
		R.add(x, n, 1);
		int cnt = L.query(x, x);
		if (x + 1 <= n) L.chkmax(x + 1, n, cnt);
		if (x - 1 >= 1) R.chkmin(1, x - 1, cnt - 1);
		L.add(x, x, 0 - cnt);
		R.add(x, x, i - cnt);
		printf("%lld\n", R.query(1, n) - L.query(1, n));
	}
	return 0;
}