#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXP = 8e7 + 5;
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
struct SegmentTree {
	struct Node {
		int lc, rc;
		int sum;
	} a[MAXP];
	int n, size, root;
	void init(int x) {
		n = x; size = 0;
	}
	void modify(int &root, int l, int r, int pos, int delta) {
		if (root == 0) root = ++size;
		a[root].sum += delta;
		if (l == r) return;
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, delta);
		else modify(a[root].rc, mid + 1, r, pos, delta);
	}
	void modify(int &root, int pos, int delta) {
		modify(root, 1, n, pos, delta);
	}
	int query(int root, int l, int r, int ql, int qr) {
		if (root == 0) return 0;
		if (l == ql && r == qr) return a[root].sum;
		int ans = 0, mid = (l + r) / 2;
		if (mid >= ql) ans += query(a[root].lc, l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) ans += query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	int query(int root, int l, int r) {
		if (l > r) return 0;
		return query(root, 1, n, l, r);
	}
} ST;
namespace rmq {
	const int MAXN = 2e5 + 5;
	const int MAXLOG = 18;
	int Min[MAXN][MAXLOG], Log[MAXN];
	int queryMin(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return min(Min[l][tmp], Min[r - (1 << tmp) + 1][tmp]);
	}
	void init(int *a, int n) {
		for (int i = 1; i <= n; i++) {
			Min[i][0] = a[i];
			Log[i] = Log[i - 1];
			if ((1 << (Log[i] + 1)) <= i) Log[i]++;
		}
		for (int t = 1; t < MAXLOG; t++)
		for (int i = 1, j = (1 << (t - 1)) + 1; j <= n; i++, j++)
			Min[i][t] = min(Min[i][t - 1], Min[j][t - 1]);
	}
}
ll ans, res[MAXN], nor[MAXN];
int n, q, p[MAXN], w[MAXN], len[MAXN], home[MAXN];
int size, father[MAXN], pos[MAXN], root[MAXN], lc[MAXN], rc[MAXN];
int work(int l, int r) {
	int now = ++size;
	len[now] = r - l + 1;
	for (int i = l; i <= r; i++)
		ST.modify(root[now], p[i], 1);
	if (l == r) pos[l] = now;
	else {
		int mid = home[rmq :: queryMin(l, r - 1)];
		lc[now] = work(l, mid), rc[now] = work(mid + 1, r);
		father[lc[now]] = father[rc[now]] = now;
		nor[now] = 1ll * len[lc[now]] * len[rc[now]];
		if (len[lc[now]] < len[rc[now]]) {
			for (int i = l; i <= mid; i++)
				res[now] += ST.query(root[rc[now]], p[i] + 1, n);
		} else {
			for (int i = mid + 1; i <= r; i++)
				res[now] += ST.query(root[lc[now]], 1, p[i] - 1);
		}
		ans += min(res[now], nor[now] - res[now]);
	}
	return now;
}
void modify(int x, int y) {
	int z = pos[x];
	while (father[z] != 0) {
		int f = father[z];
		if (lc[f] == z) {
			ans -= min(res[f], nor[f] - res[f]);
			res[f] -= ST.query(root[rc[f]], p[x] + 1, n);
			res[f] += ST.query(root[rc[f]], y + 1, n);
			ST.modify(root[z], p[x], -1);
			ST.modify(root[z], y, 1);
			ans += min(res[f], nor[f] - res[f]);
		} else {
			ans -= min(res[f], nor[f] - res[f]);
			res[f] -= ST.query(root[lc[f]], 1, p[x] - 1);
			res[f] += ST.query(root[lc[f]], 1, y - 1);
			ST.modify(root[z], p[x], -1);
			ST.modify(root[z], y, 1);
			ans += min(res[f], nor[f] - res[f]);
		}
		z = f;
	}
	p[x] = y;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(p[i]);
	for (int i = 1; i <= n - 1; i++)
		read(w[i]), home[w[i]] = i;
	ST.init(n), rmq :: init(w, n);
	work(1, n);
	read(q);
	for (int i = 1; i <= q; i++) {
		int x, y; read(x), read(y);
		int vx = p[x], vy = p[y];
		modify(x, vy);
		modify(y, vx);
		printf("%lld\n", ans);
	}
	return 0;
}