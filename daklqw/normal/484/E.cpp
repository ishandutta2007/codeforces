#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500010;
int rk[MAXN], sums[MAXN], li[MAXN], m, n, t1, t2, t3;
struct T {
	int val, pre, suc, len;
	T(int _ = 0, int __ = 0, int ___ = 0, int ____ = 0) { val = _; pre = __; suc = ___; len = ____; }
	inline friend T operator + (const T & A, const T & B) {
		T res;
		res.val = std::max(std::max(A.val, B.val), A.suc + B.pre);
		res.len = A.len + B.len;
		res.pre = A.pre + (A.pre == A.len ? B.pre : 0);
		res.suc = B.suc + (B.suc == B.len ? A.suc : 0);
		return res;
	}
} tree[MAXN * 20];
int ls[MAXN * 20], rs[MAXN * 20], tot, rt[MAXN];
int build(int l, int r) {
	int now = ++tot;
	if (l == r) {
		tree[now] = T(0, 0, 0, 1);
		return now;
	}
	int mid = l + r >> 1;
	if (l <= mid) ls[now] = build(l, mid);
	if (mid < r) rs[now] = build(mid + 1, r);
	tree[now] = tree[ls[now]] + tree[rs[now]];
	return now;
}
int modify(int ver, int l, int r, int tar) {
	int now = ++tot;
	tree[now] = tree[ver]; ls[now] = ls[ver]; rs[now] = rs[ver];
	if (l == r) {
		tree[now].len = tree[now].val = tree[now].pre = tree[now].suc = 1;
		return now;
	}
	int mid = l + r >> 1;
	if (tar <= mid) ls[now] = modify(ls[ver], l, mid, tar);
	else rs[now] = modify(rs[ver], mid + 1, r, tar);
	tree[now] = tree[ls[now]] + tree[rs[now]];
	return now;
}
T query(int ver, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[ver];
	int mid = l + r >> 1; T res;
	if (L <= mid) res = query(ls[ver], l, mid, L, R);
	if (mid < R) res = res + query(rs[ver], mid + 1, r, L, R);
	return res;
}
inline bool cmp(int a, int b) { return sums[a] > sums[b]; }
inline bool cmp2(int a, int b) { return a > b; }
bool judge(int now, int l, int r, int K) { return query(rt[now], 1, n, l, r).val >= K; }
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &sums[i]);
		li[i] = sums[i];
		rk[i] = i;
	}
	sort(li + 1, li + 1 + n, cmp2);
	sort(rk + 1, rk + 1 + n, cmp);
	rt[0] = build(1, n);
	for (int i = 1; i <= n; ++i) rt[i] = modify(rt[i - 1], 1, n, rk[i]); 
	scanf("%d", &m);
	while (m --> 0) {
		scanf("%d%d%d", &t1, &t2, &t3);
		int ans = 0, l = 1, r = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (judge(mid, t1, t2, t3)) ans = mid, r = mid - 1; else l = mid + 1;
		}
		printf("%d\n", li[ans]);
	}
	return 0;
}