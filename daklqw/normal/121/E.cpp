#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int arr[] = {
4, 7,
44, 47, 74, 77,
444, 447, 474, 477, 744, 747, 774, 777,
4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777,
7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777,
0x3f3f3f3f
} ;
const int MAXN = 100010;
int cur[MAXN];
struct data {
	int minn, cnt;
	explicit data(int _m = 4, int _c = 1) : minn(_m), cnt(_c) {}
	inline friend data operator + (const data & a, const data & b) {
		if (a.minn != b.minn) return a.minn < b.minn ? a : b;
		return data(a.minn, a.cnt + b.cnt);
	}
} tree[MAXN << 2];
int tag[MAXN << 2];
inline void pushdown(int u) {
	if (tag[u]) {
		tag[u << 1] += tag[u];
		tag[u << 1 | 1] += tag[u];
		tree[u << 1].minn -= tag[u];
		tree[u << 1 | 1].minn -= tag[u];
		tag[u] = 0;
	}
}
void reduce(int u, int l, int r) {
	if (tree[u].minn >= 0) return ;
	if (l == r) {
		while (tree[u].minn < 0) {
			tree[u].minn += arr[cur[l] + 1] - arr[cur[l]];
			++cur[l];
		}
		return ;
	}
	int mid = l + r >> 1;
	pushdown(u);
	reduce(u << 1, l, mid); reduce(u << 1 | 1, mid + 1, r);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
void modify(int u, int l, int r, int L, int R, int v) {
	if (L <= l && r <= R) {
		tag[u] += v;
		tree[u].minn -= v;
		reduce(u, l, r);
		return ;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (L <= mid) modify(u << 1, l, mid, L, R, v);
	if (mid < R) modify(u << 1 | 1, mid + 1, r, L, R, v);
	tree[u] = tree[u << 1] + tree[u << 1 | 1];
}
data query(int u, int l, int r, int L, int R) {
	if (L <= l && r <= R) return tree[u];
	int mid = l + r >> 1; data res(0x3f3f3f3f, 1);
	pushdown(u);
	if (L <= mid) res = res + query(u << 1, l, mid, L, R);
	if (mid < R) res = res + query(u << 1 | 1, mid + 1, r, L, R);
	return res;
}
int n, m, t1, t2, t3;
char buf[10];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t1);
		modify(1, 1, n, i, i, t1);
	}
	while (m --> 0) {
		scanf("%s", buf);
		if (*buf == 'c') {
			scanf("%d%d", &t1, &t2);
			data ret = query(1, 1, n, t1, t2);
			printf("%d\n", (ret.minn == 0) * ret.cnt);
		} else {
			scanf("%d%d%d", &t1, &t2, &t3);
			modify(1, 1, n, t1, t2, t3);
		}
	}
	return 0;
}