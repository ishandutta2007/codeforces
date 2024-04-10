#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
int n, m, x[MAXN], y[MAXN], z[MAXN], ans[MAXN];
int cnt, res, f[MAXN], s[MAXN], rk[MAXN], sa[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return find(f[x]);
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		vector <pair <int, int>> mod;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) return;
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void modify(int root, int l, int r, int ql, int qr, pair <int, int> x) {
		if (l == ql && r == qr) {
			a[root].mod.push_back(x);
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), x);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, x);
	}
	void modify(int l, int r, pair <int, int> x) {
		modify(root, 1, n, l, r, x);
	}
	void dfs(int root, int l, int r) {
		int bakcnt = cnt;
		vector <pair <int, pair <int, int>>> bak;
		for (auto x : a[root].mod) {
			int tx = find(x.first), ty = find(x.second);
			if (tx != ty) {
				cnt -= s[tx] & 1;
				cnt -= s[ty] & 1;
				bak.emplace_back(tx, make_pair(f[tx], s[tx]));
				bak.emplace_back(ty, make_pair(f[ty], s[ty]));
				if (s[tx] > s[ty]) swap(tx, ty);
				f[tx] = ty, s[ty] += s[tx];
				cnt += s[ty] & 1;
			}
		}
		if (l == r) {
			while (cnt != 0 && res != 0) {
				if (sa[res] > l) {
					res--;
					continue;
				}
				int tx = find(x[sa[res]]), ty = find(y[sa[res]]);
				if (sa[res] < l) modify(sa[res], l - 1, make_pair(x[sa[res]], y[sa[res]]));
				if (tx != ty) {
					cnt -= s[tx] & 1;
					cnt -= s[ty] & 1;
					bak.emplace_back(tx, make_pair(f[tx], s[tx]));
					bak.emplace_back(ty, make_pair(f[ty], s[ty]));
					if (s[tx] > s[ty]) swap(tx, ty);
					f[tx] = ty, s[ty] += s[tx];
					cnt += s[ty] & 1;
				}
				res--;
			}
			if (cnt != 0) ans[l] = -1;
			else ans[l] = z[sa[res + 1]];
		} else {
			int mid = (l + r) / 2;
			dfs(a[root].rc, mid + 1, r);
			dfs(a[root].lc, l, mid);
		}
		cnt = bakcnt;
		reverse(bak.begin(), bak.end());
		for (auto x : bak) {
			f[x.first] = x.second.first;
			s[x.first] = x.second.second;
		}
	}
} ST;
bool cmp(int x, int y) {
	return z[x] > z[y];
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		f[i] = i, s[i] = 1;
	for (int i = 1; i <= m; i++)
		read(x[i]), read(y[i]), read(z[i]), sa[i] = i;
	sort(sa + 1, sa + m + 1, cmp);
	for (int i = 1; i <= m; i++)
		rk[sa[i]] = i;
	res = m, cnt = n;
	ST.init(m), ST.dfs(ST.root, 1, m);
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}