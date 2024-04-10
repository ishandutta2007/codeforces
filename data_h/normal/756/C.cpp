#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;

int n;
int ll[N << 2], rr[N << 2];
int val[N];

void insert(int x, int l, int r, int pos, int v) {
	if (l == r) {
		if (v == 1) {
			rr[x] = 1, ll[x] = 0;
		} else {
			rr[x] = 0, ll[x] = 1;
		}
	} else {
		int mid = (l + r) / 2;
		if (pos <= mid) {
			insert(x << 1, l, mid, pos, v);
		} else {
			insert(x << 1 | 1, mid + 1, r, pos, v);
		}
		int delta = rr[x << 1] - ll[x << 1 | 1];
		ll[x] = ll[x << 1] + max(-delta, 0);
		rr[x] = rr[x << 1 | 1] + max(delta, 0);
	}
}

int query(int x, int l, int r, int k) {
	if (rr[x] < k) return -1;
	if (l == r) return val[l];
	int mid = (l + r) / 2;
	if (rr[x << 1 | 1] >= k) return query(x << 1 | 1, mid + 1, r, k);
	return query(x << 1, l, mid, k + ll[x << 1 | 1] - rr[x << 1 | 1]);
}

int main() {
	scanf("%d", &n);
	fill(val + 1, val + n + 1, -1);
	for (int i = 1; i <= n; i++) {
		int t, pos;
		scanf("%d %d", &pos, &t);
		if (t == 0) {
			insert(1, 1, n, pos, -1);
		} else {
			scanf("%d", &val[pos]);
			insert(1, 1, n, pos, 1);
		}
		printf("%d\n", query(1, 1, n, 1));
	}
	return 0;
}