#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long INF = 1e18;
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
ll x[MAXN], y[MAXN]; vector <int> a[MAXN];
int n, k, ans, g[MAXN], w[MAXN], fa[MAXN];
struct BinaryIndexTree {
	int n; ll a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, ll d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	ll query(int x) {
		ll ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
} BIT;
struct SegmentTree {
	struct Node {
		int lc, rc, rev;
		ll tagh, tagc;
		ll Maxh, Minc, res;
	} a[MAXN * 2];
	int root, size, n;
	void pushdown(int root) {
		if (a[root].tagh) {
			a[a[root].lc].tagh += a[root].tagh;
			a[a[root].lc].Maxh += a[root].tagh;
			a[a[root].lc].res += a[root].tagh;
			a[a[root].rc].tagh += a[root].tagh;
			a[a[root].rc].Maxh += a[root].tagh;
			a[a[root].rc].res += a[root].tagh;
			a[root].tagh = 0;
		}
		if (a[root].tagc) {
			a[a[root].lc].tagc += a[root].tagc;
			a[a[root].lc].Minc += a[root].tagc;
			a[a[root].lc].res += a[root].tagc;
			a[a[root].rc].tagc += a[root].tagc;
			a[a[root].rc].Minc += a[root].tagc;
			a[a[root].rc].res += a[root].tagc;
			a[root].tagc = 0;
		}
	}
	ll query(int root, ll height) {
		if (a[root].lc == 0) return a[root].Minc + max(height, y[a[root].rev] + BIT.query(a[root].rev));
		else {
			pushdown(root);
			if (height <= a[a[root].lc].Maxh) return min(a[root].res, query(a[root].lc, height));
			else return min(height + a[a[root].lc].Minc, query(a[root].rc, max(height, a[a[root].lc].Maxh)));
		}
	}
	void update(int root) {
		a[root].Maxh = max(a[a[root].lc].Maxh, a[a[root].rc].Maxh);
		a[root].Minc = min(a[a[root].lc].Minc, a[a[root].rc].Minc);
		a[root].res = query(a[root].rc, a[a[root].lc].Maxh);
	}
	void build(int &root, int l, int r, ll *x) {
		root = ++size;
		if (l == r) {
			a[root].rev = l;
			a[root].Maxh = x[l];
			a[root].Minc = -x[l];
			a[root].res = 0;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, x);
		build(a[root].rc, mid + 1, r, x);
		update(root);
	}
	void init(int l, ll *x) {
		root = size = 0, n = l;
		build(root, 1, n, x);
	}
	void addheight(int root, int l, int r, int ql, int qr, ll d) {
		if (l == ql && r == qr) {
			a[root].tagh += d;
			a[root].Maxh += d;
			a[root].res += d;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) addheight(a[root].lc, l, mid, ql, min(mid, qr), d);
		if (mid + 1 <= qr) addheight(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
		update(root);
	}
	void addheight(int l, int r, ll d) {
		addheight(root, 1, n, l, r, d);
	}
	int home; ll Max, Mem;
	void dfs(int root, int l, int r, int pos, ll Lim) {
		if (pos <= l) {
			if (query(root, Max) <= Lim) {
				home = root;
				Mem = Max;
			}
			chkmax(Max, a[root].Maxh);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (pos <= mid) dfs(a[root].lc, l, mid, pos, Lim);
		dfs(a[root].rc, mid + 1, r, pos, Lim);
	}
	int getans(int root, ll height, ll Lim) {
		if (a[root].lc == 0) return a[root].rev;
		pushdown(root);
		if (query(a[root].rc, max(height, a[a[root].lc].Maxh)) <= Lim) return getans(a[root].rc, max(height, a[a[root].lc].Maxh), Lim);
		else return getans(a[root].lc, height, Lim);
	}
	int getans(int pos, ll Lim) {
		Max = BIT.query(pos) + y[pos];
		dfs(root, 1, n, pos, Lim);
		return getans(home, Mem, Lim);
	}
} ST;
void dfs(int pos, int fa) {
	chkmax(ans, ST.getans(pos, k) - pos + 1);
	for (auto p : a[pos]) {
		BIT.modify(pos, x[p] - x[pos]);
		ST.addheight(pos - 1, n, x[p] - x[pos]);
		dfs(p, pos);
		BIT.modify(pos, x[pos] - x[p]);
		ST.addheight(pos - 1, n, x[pos] - x[p]);
	}
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n - 1; i++)
		read(w[i]);
	for (int i = 1; i <= n; i++)
		read(g[i]);
	y[1] = g[1];
	for (int i = 2; i <= n; i++) {
		x[i] = y[i - 1] - w[i - 1];
		y[i] = x[i] + g[i];
	}
	static int q[MAXN]; int top = 0;
	for (int i = n; i >= 1; i--) {
		while (top >= 1 && x[i] <= x[q[top]]) top--;
		if (top >= 1) {
			fa[i] = q[top];
			a[q[top]].push_back(i);
		}
		q[++top] = i;
	}
	BIT.init(n);
	ST.init(n, y);
	for (int i = 1; i <= n; i++)
		if (fa[i] == 0) dfs(i, 0);
	cout << ans << endl;
	return 0;
}