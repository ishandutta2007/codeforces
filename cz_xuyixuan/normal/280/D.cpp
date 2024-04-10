#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct Segment_Tree {
	struct info {
		int lmax, rmax, smax;
		int lmin, rmin, smin;
		int lmaxpos, lminpos;
		int rmaxpos, rminpos;
		int smaxl, sminl;
		int smaxr, sminr;
		int sum;
	};
	info merge(info a, info b) {
		info ans;
		ans.sum = a.sum + b.sum;
		/*lmax lmaxpos*/
		if (a.lmax > a.sum + b.lmax) {
			ans.lmax = a.lmax;
			ans.lmaxpos = a.lmaxpos;
		} else {
			ans.lmax = a.sum + b.lmax;
			ans.lmaxpos = b.lmaxpos;
		}
		/*rmax rmaxpos*/
		if (b.rmax > b.sum + a.rmax) {
			ans.rmax = b.rmax;
			ans.rmaxpos = b.rmaxpos;
		} else {
			ans.rmax = b.sum + a.rmax;
			ans.rmaxpos = a.rmaxpos;
		}
		/*lmin lminpos*/
		if (a.lmin < a.sum + b.lmin) {
			ans.lmin = a.lmin;
			ans.lminpos = a.lminpos;
		} else {
			ans.lmin = a.sum + b.lmin;
			ans.lminpos = b.lminpos;
		}
		/*rmin rminpos*/
		if (b.rmin < b.sum + a.rmin) {
			ans.rmin = b.rmin;
			ans.rminpos = b.rminpos;
		} else {
			ans.rmin = b.sum + a.rmin;
			ans.rminpos = a.rminpos;
		}
		/*smax smaxl smaxr*/
		if (a.smax > b.smax) {
			ans.smax = a.smax;
			ans.smaxl = a.smaxl;
			ans.smaxr = a.smaxr;
		} else {
			ans.smax = b.smax;
			ans.smaxl = b.smaxl;
			ans.smaxr = b.smaxr;
		}
		if (a.rmax + b.lmax > ans.smax) {
			ans.smax = a.rmax + b.lmax;
			ans.smaxl = a.rmaxpos;
			ans.smaxr = b.lmaxpos;
		}
		/*smin sminl sminr*/
		if (a.smin < b.smin) {
			ans.smin = a.smin;
			ans.sminl = a.sminl;
			ans.sminr = a.sminr;
		} else {
			ans.smin = b.smin;
			ans.sminl = b.sminl;
			ans.sminr = b.sminr;
		}
		if (a.rmin + b.lmin < ans.smin) {
			ans.smin = a.rmin + b.lmin;
			ans.sminl = a.rminpos;
			ans.sminr = b.lminpos;
		}
		return ans;
	}
	void reverse(info &a) {
		a.sum = -a.sum;
		swap(a.lmax, a.lmin);
		a.lmax = -a.lmax;
		a.lmin = -a.lmin;
		swap(a.rmax, a.rmin);
		a.rmax = -a.rmax;
		a.rmin = -a.rmin;
		swap(a.smax, a.smin);
		a.smax = -a.smax;
		a.smin = -a.smin;
		swap(a.lmaxpos, a.lminpos);
		swap(a.rmaxpos, a.rminpos);
		swap(a.smaxl, a.sminl);
		swap(a.smaxr, a.sminr);
	}
	info new_node(int value, int pos) {
		info ans;
		ans.sum = value;
		ans.lmax = ans.rmax = ans.smax = value;
		ans.lmin = ans.rmin = ans.smin = value;
		ans.lmaxpos = ans.lminpos = pos;
		ans.rmaxpos = ans.rminpos = pos;
		ans.smaxl = ans.sminl = pos;
		ans.smaxr = ans.sminr = pos;
		return ans;
	}
	struct Node {
		int lc, rc;
		bool tag;
		info value;
	} a[MAXN];
	int root, size, n;
	void pushdown(int root) {
		if (a[root].tag) {
			int tmp;
			tmp = a[root].lc;
			a[tmp].tag ^= true;
			reverse(a[tmp].value);
			tmp = a[root].rc;
			a[tmp].tag ^= true;
			reverse(a[tmp].value);
			a[root].tag = false;
		}
	}
	void update(int root) {
		a[root].value = merge(a[a[root].lc].value, a[a[root].rc].value);
	}
	void build(int root, int l, int r, int *value) {
		if (l == r) {
			a[root].value = new_node(value[l], l);
			return;
		}
		int mid = (l + r) / 2;
		a[root].lc = ++size;
		build(size, l, mid, value);
		a[root].rc = ++size;
		build(size, mid + 1, r, value);
		update(root);
	}
	void init(int x, int *value) {
		n = x;
		root = size = 0;
		build(root, 1, n, value);
	}
	info query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].value;
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		return merge(query(a[root].lc, l, mid, ql, mid), query(a[root].rc, mid + 1, r, mid + 1, qr));
	}
	void reverse(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) {
			reverse(a[root].value);
			a[root].tag ^= true;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) reverse(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) reverse(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		update(root);
	}
	int query(int l, int r, int k) {
		static int ql[MAXN], qr[MAXN];
		int ans = 0, used = k;
		for (int i = 1; i <= k; i++) {
			info tmp = query(root, 1, n, l, r);
			if (tmp.smax > 0) {
				ql[i] = tmp.smaxl;
				qr[i] = tmp.smaxr;
				reverse(root, 1, n, ql[i], qr[i]);
				ans += tmp.smax;
			} else {
				used = i - 1;
				break;
			}
		}
		for (int i = 1; i <= used; i++)
			reverse(root, 1, n, ql[i], qr[i]);
		return ans;
	}
	void modify(int root, int l, int r, int pos, int value) {
		if (l == r) {
			a[root].value = new_node(value, pos);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, value);
		else modify(a[root].rc, mid + 1, r, pos, value);
		update(root);
	}
	void modify(int pos, int value) {
		modify(root, 1, n, pos, value);
	}
} SMT;
int value[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(value[i]);
	SMT.init(n, value);
	int m; read(m);
	for (int i = 1; i <= m; i++) {
		int opt, l, r, k;
		read(opt);
		if (opt == 1) {
			read(l), read(r), read(k);
			printf("%d\n", SMT.query(l, r, k));
		} else {
			read(l), read(k);
			SMT.modify(l, k);
		}
	}
	return 0;
}