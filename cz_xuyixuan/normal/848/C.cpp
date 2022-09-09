#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXP	10000005
struct Two_Dimension_Tree {
	int size, n, BIT[MAXN];
	int lc[MAXP], rc[MAXP];
	long long sum[MAXP];
	void init(int x) {
		n = x;
		size = 0;
	}
	void modify(int &root, int l, int r, int x, int d) {
		if (!root) root = ++size;
		sum[root] += d;
		if (l == r) return;
		int mid = (l + r) / 2;
		if (mid >= x) modify(lc[root], l, mid, x, d);
		else modify(rc[root], mid + 1, r, x, d);
	}
	void modify(int x, int y, int d) {
		for (int i = x; i <= n; i += i & -i)
			modify(BIT[i], 1, n, y, d);
	}
	long long query(int root, int l, int r, int ql, int qr) {
		if (!root) return 0;
		if (l == ql && r == qr) return sum[root];
		int mid = (l + r) / 2;
		long long ans = 0;
		if (mid >= ql) ans += query(lc[root], l, mid, ql, min(qr, mid));
		if (mid + 1 <= qr) ans += query(rc[root], mid + 1, r, max(mid + 1, ql), qr);
		return ans;
	}
	long long query(int l, int r, int x, int y) {
		long long ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += query(BIT[i], 1, n, x, y);
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= query(BIT[i], 1, n, x, y);
		return ans;
	}
} TDT;
vector <int> a[MAXN];
int value[MAXN], home[MAXN], n, m;
int find(int pos, int value) {
	int l = 0, r = a[pos].size();
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[pos][mid] < value) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	TDT.init(n);
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
		a[value[i]].push_back(i);
		int tmp = a[value[i]].size();
		if (tmp != 1) TDT.modify(a[value[i]][tmp - 2], a[value[i]][tmp - 1], a[value[i]][tmp - 1] - a[value[i]][tmp - 2]);
	}
	for (int i = 1; i <= m; i++) {
		int opt, l, r;
		cin >> opt >> l >> r;
		if (opt == 1) {
			int tmp = find(value[l], l), tot = a[value[l]].size();
			if (tmp > 0) TDT.modify(a[value[l]][tmp - 1], a[value[l]][tmp], a[value[l]][tmp - 1] - a[value[l]][tmp]);
			if (tmp + 1 < tot) TDT.modify(a[value[l]][tmp], a[value[l]][tmp + 1], a[value[l]][tmp] - a[value[l]][tmp + 1]);
			if (tmp > 0 && tmp + 1 < tot) TDT.modify(a[value[l]][tmp - 1], a[value[l]][tmp + 1], a[value[l]][tmp + 1] - a[value[l]][tmp - 1]);
			a[value[l]].erase(a[value[l]].begin() + tmp);
			value[l] = r; tmp = find(value[l], l);
			a[value[l]].insert(a[value[l]].begin() + tmp, l);
			tot = a[value[l]].size();
			if (tmp > 0) TDT.modify(a[value[l]][tmp - 1], a[value[l]][tmp], a[value[l]][tmp] - a[value[l]][tmp - 1]);
			if (tmp + 1 < tot) TDT.modify(a[value[l]][tmp], a[value[l]][tmp + 1], a[value[l]][tmp + 1] - a[value[l]][tmp]);
			if (tmp > 0 && tmp + 1 < tot) TDT.modify(a[value[l]][tmp - 1], a[value[l]][tmp + 1], a[value[l]][tmp - 1] - a[value[l]][tmp + 1]);
			
		} else cout << TDT.query(l, r, l, r) << endl;
	}
	return 0;
}