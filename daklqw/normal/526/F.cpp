#include <bits/stdc++.h>

const int MAXN = 300010;
int A[MAXN], n;
struct node {
	int minv, cnt;
	friend node operator + (node a, node b) {
		if (a.minv == b.minv) return (node) {a.minv, a.cnt + b.cnt};
		return a.minv < b.minv ? a : b;
	}
} tree[MAXN << 2];
int tag[MAXN << 2];
void mkadd(int x, int v) {
	tag[x] += v, tree[x].minv += v;
}
void pushdown(int u) {
	if (int & t = tag[u]) {
		mkadd(u << 1, t);
		mkadd(u << 1 | 1, t);
		t = 0;
	}
}
void mdf(int u, int l, int r, int L, int R, int v) {
	// if (u == 1) std::cout << "MDF " << L << ' ' << R << ' ' << v << std::endl;
	if (L <= l && r <= R) return mkadd(u, v);
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) mdf(u << 1, l, mid, L, R, v);
	if (mid < R) mdf(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
node qry(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1;
	pushdown(u); node res = (node) {0x3f3f3f3f, 0};
	if (L <= mid) res = qry(u << 1, l, mid, L, R);
	if (mid < R) res = res + qry(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
void build(int u, int l, int r) {
	tree[u].cnt = 1;
	tree[u].minv = l;
	if (l == r) return ;
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}
int st1[MAXN], top1, st2[MAXN], top2;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t1, t2; i <= n; ++i)
		std::cin >> t1 >> t2, A[t1] = t2;
	build(1, 1, n);
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		mkadd(1, -1);
		if (i > 1) {
			int lcur = i - 1;
			while (top1 && A[st1[top1]] > A[i]) {
				mdf(1, 1, n, st1[top1 - 1] + 1, lcur, A[st1[top1]] - A[i]);
				lcur = st1[--top1];
			}
			lcur = i - 1;
			while (top2 && A[st2[top2]] < A[i]) {
				mdf(1, 1, n, st2[top2 - 1] + 1, lcur, A[i] - A[st2[top2]]);
				lcur = st2[--top2];
			}
		}
		st1[++top1] = i;
		st2[++top2] = i;
		node res = qry(1, 1, n, 1, i);
		if (res.minv == 0) ans += res.cnt;
		// std::cout << "NOW " << i << ' ' << res.minv << ' ' << res.cnt << std::endl;
	}
	std::cout << ans << std::endl;
	return 0;
}