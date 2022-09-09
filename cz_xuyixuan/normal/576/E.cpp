#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXP = 5e7 + 5;
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
int x[MAXN], y[MAXN], last[MAXN];
int e[MAXN], c[MAXN], nxt[MAXN];
int n, m, q, k, f[MAXP], s[MAXP];
struct Node {
	int lc, rc;
	vector <int> mod;
} a[MAXN * 2]; int root, size;
int find(int x) {
	if (f[x] == x) return x;
	else return find(f[x]);
}
inline int point(int x, bool side, int k) {
	return (k - 1) * n * 2 + side * n + x;
}
void modify(int root, int l, int r, int ql, int qr, int d) {
	if (l == ql && r == qr) {
		a[root].mod.push_back(d);
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), d);
	if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, d);
}
void work(int root, int l, int r) {
	vector <pair <int, pair <int, int>>> bak;
	for (auto t : a[root].mod) {
		int tx = find(point(x[e[t]], 0, c[t])), ty = find(point(y[e[t]], 1, c[t]));
		if (tx != ty) {
			if (s[tx] > s[ty]) swap(tx, ty);
			bak.emplace_back(tx, make_pair(f[tx], s[tx]));
			bak.emplace_back(ty, make_pair(f[ty], s[ty]));
			f[tx] = ty, s[ty] += s[tx];
		}
		tx = find(point(x[e[t]], 1, c[t])), ty = find(point(y[e[t]], 0, c[t]));
		if (tx != ty) {
			if (s[tx] > s[ty]) swap(tx, ty);
			bak.emplace_back(tx, make_pair(f[tx], s[tx]));
			bak.emplace_back(ty, make_pair(f[ty], s[ty]));
			f[tx] = ty, s[ty] += s[tx];
		}
	}
	if (l == r) {
		if (find(point(x[e[l]], 0, c[l])) == find(point(y[e[l]], 0, c[l]))) {
			puts("NO");
			if (last[e[l]] && l != q) modify(1, 1, q, l + 1, nxt[l], last[e[l]]);
		} else {
			puts("YES");
			last[e[l]] = l;
			if (l != q) modify(1, 1, q, l + 1, nxt[l], last[e[l]]);
		}
	} else {
		int mid = (l + r) / 2;
		work(a[root].lc, l, mid);
		work(a[root].rc, mid + 1, r);
	}
	reverse(bak.begin(), bak.end());
	for (auto x : bak) {
		f[x.first] = x.second.first;
		s[x.first] = x.second.second;
	}
}
void build(int &root, int l, int r) {
	root = ++size;
	if (l == r) return;
	int mid = (l + r) / 2;
	build(a[root].lc, l, mid);
	build(a[root].rc, mid + 1, r);
}
int main() {
	read(n), read(m), read(k), read(q);
	for (int i = 1; i <= m; i++)
		read(x[i]), read(y[i]);
	for (int i = 1; i <= q; i++) {
		read(e[i]), read(c[i]);
		if (last[e[i]] != 0) nxt[last[e[i]]] = i;
		last[e[i]] = i;
	}
	for (int i = 1; i <= q; i++)
		if (nxt[i] == 0) nxt[i] = q;
	for (int i = 1; i <= 2 * n * k; i++)
		f[i] = i, s[i] = 1;
	memset(last, 0, sizeof(last));
	build(root, 1, q);
	work(root, 1, q);
	return 0;
}