#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXV	10000
#define MAXCNT	40
#define INF	1e9
int n, m, cnt;
int value[MAXN], val[MAXCNT];
struct Segment_Tree {
	int lc[MAXN * 2], rc[MAXN * 2], pos[MAXN * 2];
	int tag[MAXN * 2], ans[MAXN * 2], minnum[MAXN * 2];
	int root, size, n;
	void update(int root) {
		pushdown(lc[root]);
		pushdown(rc[root]);
		ans[root] = ans[lc[root]] + ans[rc[root]];
		minnum[root] = min(minnum[lc[root]], minnum[rc[root]]);
	}
	void build(int root, int l, int r) {
		if (l == r) {
			pos[root] = 1;
			while (val[pos[root]] < value[l])
				pos[root]++;
			minnum[root] = val[pos[root]] - value[l];
			if (minnum[root] == 0) ans[root] = 1;
			else ans[root] = 0;
			return;
		}
		int mid = (l + r) / 2;
		lc[root] = ++size;
		build(size, l, mid);
		rc[root] = ++size;
		build(size, mid + 1, r);
		update(root);
	}
	void pushdown(int root) {
		if (tag[root] == 0) return;
		if (lc[root] == 0) {
			minnum[root] -= tag[root];
			while (minnum[root] < 0) {
				pos[root]++;
				minnum[root] += val[pos[root]] - val[pos[root] - 1];
			}
			if (minnum[root] == 0) ans[root] = 1;
			else ans[root] = 0;
			tag[root] = 0;
			return;
		}
		minnum[root] -= tag[root];
		if (minnum[root] > 0) {
			tag[lc[root]] += tag[root];
			tag[rc[root]] += tag[root];
		} else {
			tag[lc[root]] += tag[root];
			pushdown(lc[root]);
			tag[rc[root]] += tag[root];
			pushdown(rc[root]);
			update(root);
		}
		tag[root] = 0;
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 1, n);
	}
	int query(int root, int l, int r, int ql, int qr) {
		pushdown(root);
		if (l == ql && r == qr) return ans[root];
		int tans = 0, mid = (l + r) / 2;
		if (mid >= ql) tans += query(lc[root], l, mid, ql, min(mid, qr));
		if (mid + 1 <= qr) tans += query(rc[root], mid + 1, r, max(mid + 1, ql), qr);
		return tans;
	}
	int query(int x, int y) {
		return query(root, 1, n, x, y);
	}
	void modify(int root, int l, int r, int ql, int qr, int v) {
		if (l == ql && r == qr) {
			tag[root] += v;
			pushdown(root);
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(lc[root], l, mid, ql, min(mid, qr), v);
		if (mid + 1 <= qr) modify(rc[root], mid + 1, r, max(mid + 1, ql), qr, v);
		update(root);
	}
	void modify(int x, int y, int v) {
		modify(root, 1, n, x, y, v);
	}
} ST;
bool func(int x) {
	while (x) {
		int y = x % 10;
		x /= 10;
		if (y != 4 && y != 7) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	for (int i = 1; i <= MAXV; i++)
		if (func(i)) val[++cnt] = i;
	val[++cnt] = INF;
	ST.init(n);
	while (m--) {
		char s[10];
		int l, r, x;
		cin >> s >> l >> r;
		if (s[0] == 'c') {
			int ans = ST.query(l, r);
			cout << ans << endl;
		} else {
			cin >> x;
			ST.modify(l, r, x);
		}
	}
	return 0;
}