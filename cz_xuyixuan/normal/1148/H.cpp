#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXP = 2e7 + 6e6;
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
struct vinfo {
	ll pre;
	int sum, len;
};
vinfo operator + (vinfo a, vinfo b) {
	return (vinfo) {a.pre + b.pre, a.sum + b.sum, a.len + b.len};
}
struct tinfo {
	int pk, pb;
	int sk, sb;
};
vinfo operator * (vinfo a, tinfo b) {
	vinfo ans;
	ans.len = a.len;
	ans.sum = a.sum * b.sk + a.len * b.sb;
	ans.pre = a.pre + 1ll * a.sum * b.pk + 1ll * a.len * b.pb;
	return ans;
}
tinfo cipher() {
	tinfo ans;
	ans.sb = 0;
	ans.sk = 1;
	ans.pb = 0;
	ans.pk = 0;
	return ans;
}
bool operator == (tinfo a, tinfo b) {
	return a.sb == b.sb && a.sk == b.sk && a.pb == b.pb && a.pk == b.pk;
}
tinfo operator * (tinfo a, tinfo b) {
	tinfo ans;
	ans.sb = a.sb * b.sk + b.sb;
	ans.sk = a.sk * b.sk;
	ans.pb = a.pb + a.sb * b.pk + b.pb;
	ans.pk = a.pk + a.sk * b.pk;
	return ans;
}
struct PersistentSegmentTree {
	struct Node {
		int lc, rc;
		vinfo ans;
		tinfo tag;
	} a[MAXP];
	int n, root, size;
	void update(int root) {
		a[root].ans = a[a[root].lc].ans + a[a[root].rc].ans;
	}
	void pushdown(int root) {
		if (a[root].tag == cipher()) return;
		int lc = ++size;
		a[lc] = a[a[root].lc];
		a[lc].tag = a[lc].tag * a[root].tag;
		a[lc].ans = a[lc].ans * a[root].tag;
		a[root].lc = lc;
		int rc = ++size;
		a[rc] = a[a[root].rc];
		a[rc].tag = a[rc].tag * a[root].tag;
		a[rc].ans = a[rc].ans * a[root].tag;
		a[root].rc = rc;
		a[root].tag = cipher();
	}
	int modify(int root, int l, int r, int ql, int qr, tinfo tag, bool type) {
		int ans = root;
		if (type) ans = ++size;
		a[ans] = a[root];
		if (l == ql && r == qr) {
			a[ans].ans = a[ans].ans * tag;
			a[ans].tag = a[ans].tag * tag;
			return ans;
		}
		pushdown(ans);
		int mid = (l + r) / 2;
		if (mid >= ql) a[ans].lc = modify(a[ans].lc, l, mid, ql, min(qr, mid), tag, false);
		if (mid + 1 <= qr) a[ans].rc = modify(a[ans].rc, mid + 1, r, max(mid + 1, ql), qr, tag, false);
		update(ans);
		return ans;
	}
	int prefix(int root, int x) {
		tinfo tmp = cipher(); tmp.pk = x;
		return modify(root, 1, n, 1, n, tmp, 1);
	}
	int modify(int root, int l, int r, int v) {
		tinfo tmp = cipher();
		tmp.sk = 0, tmp.sb = v;
		return modify(root, 1, n, l, r, tmp, 1);
	}
	ll query(int root, int l, int r, int ql, int qr, tinfo tag) {
		if (l == ql && r == qr) {
			vinfo tmp = a[root].ans * tag;
			return tmp.pre;
		}
		tag = a[root].tag * tag;
		int mid = (l + r) / 2; ll ans = 0;
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(mid, qr), tag);
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, tag);
		return ans;
	}
	ll query(int root, int l, int r, int coef) {
		tinfo tmp = cipher(); tmp.pk = coef;
		return query(root, 1, n, l, r, tmp);
	}
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].tag = cipher();
		if (l == r) {
			a[root].ans.len = 1;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		update(root);
	}
	void init(int x) {
		n = x, size = 0;
		build(root, 1, n);
	}
} PST;
int a[MAXN], last[MAXN];
vector <int> timer[MAXN], root[MAXN];
set <pair <int, pair <int, int>>> seg;
void modify(int c, int l, int r, int t, int v) {
	int res = root[c].back();
	res = PST.prefix(res, t - timer[c].back());
	res = PST.modify(res, l, r, v);
	timer[c].push_back(t);
	root[c].push_back(res);
}
ll query(int c, int t, int l, int r) {
	int tmp = upper_bound(timer[c].begin(), timer[c].end(), t) - timer[c].begin() - 1;
	return PST.query(root[c][tmp], l, r, t - timer[c][tmp] + 1);
}
ll query(int c, int l, int r) {
	return query(c, r, l, r) - query(c, l - 1, l, r);
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		int Min;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].Min = 0;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 0, n);
	}
	void update(int root) {
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
	}
	void modify(int root, int l, int r, int pos, int val) {
		if (l == r) {
			a[root].Min = val;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, val);
		else modify(a[root].rc, mid + 1, r, pos, val);
		update(root);
	}
	void modify(int pos, int val) {
		modify(root, 0, n, pos, val);
	}
	pair <int, int> query(int root, int l, int r, int lim) {
		if (l == r) return make_pair(l, a[root].Min);
		int mid = (l + r) / 2;
		if (a[a[root].lc].Min <= lim) return query(a[root].lc, l, mid, lim);
		else return query(a[root].rc, mid + 1, r, lim);
	}
	pair <int, int> query(int lim) {
		return query(root, 0, n, lim);
	}
} ST;
int main() {
	int n; read(n); ll lastans = 0;
	ST.init(n), PST.init(n);
	for (int i = 0; i <= n; i++) {
		root[i].push_back(1);
		timer[i].push_back(0);
	}
	for (int i = 1; i <= n; i++) {
		int v, l, r, k;
		read(v), read(l), read(r), read(k);
		v = (v + lastans) % (n + 1);
		l = (l + lastans) % i + 1;
		r = (r + lastans) % i + 1;
		if (l > r) swap(l, r);
		k = (k + lastans) % (n + 1);
		ST.modify(v, i), a[i] = v;
		modify(0, i, i, i, 1);
		if (a[i - 1] != 0) {
			pair <int, pair <int, int>> tmp = *seg.begin();
			seg.erase(seg.begin()), tmp.second.second++;
			seg.insert(tmp);
		} else seg.insert(make_pair(0, make_pair(i, i)));
		auto tmp = seg.lower_bound(make_pair(v, make_pair(0, 0)));
		if (tmp != seg.end() && (*tmp).first == v) {
			auto suf = tmp; suf++;
			int l = (*tmp).second.first;
			int r = (*tmp).second.second;
			modify(v, l, r, i, 0);
			seg.erase(tmp);
			if (suf != seg.end()) {
				modify((*suf).first, (*suf).second.first, (*suf).second.second, i, 0);
				l = (*suf).second.first, seg.erase(suf);
			}
			while (r >= l) {
				pair <int, int> tmp = ST.query(r - 1);
				modify(tmp.first, tmp.second + 1, r, i, 1);
				seg.insert(make_pair(tmp.first, make_pair(tmp.second + 1, r)));
				r = tmp.second;
			}
		}
		writeln(lastans = query(k, l, r));
	}
	return 0;
}