#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int T, n, m;
int a[maxn];
pair<int, int> evt[maxn];
int b[maxn];

struct node {
	int v, p;
} seg[maxn << 2]; // small large

node operator + (const node a, const node b) {
	return a.v < b.v ? a : b;
}
int lzy[maxn << 2];
void add(int x, int K) { seg[x].v += K; lzy[x] += K; }
void pushdown(int x) {
	add(x << 1, lzy[x]); add(x << 1 | 1, lzy[x]);
	lzy[x] = 0;
}
void build(int x, int l, int r) {
	seg[x].v = l; seg[x].p = l;
	lzy[x] = 0;
	if (l != r) {
		int mid = (l + r) >> 1;
		build(x << 1, l, mid);
		build(x << 1 | 1, mid + 1, r);
	}
}
void Update(int x, int l, int r, int L, int R, int K) {
	if (L > R) return;
	if (L <= l && r <= R) return add(x, K);
	int mid = (l + r) >> 1;
	pushdown(x);
	if (L <= mid) Update(x << 1, l, mid, L, R, K);
	if (R > mid) Update(x << 1 | 1, mid + 1, r, L, R, K);
	seg[x] = seg[x << 1] + seg[x << 1 | 1];
}

int pos[maxn];
int C[maxn];
void chn(int x, int k) { for (; x <= n; x += x & -x) C[x] += k; }
int qry(int x) { int ans = 0; for (; x; x -= x & -x) ans += C[x]; return ans; }

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), evt[i] = make_pair(a[i], i);
		// for (int i = 1; i <= n; i++) a[i] = rand() % 100, evt[i] = make_pair(a[i], i);
		sort(evt + 1, evt + n + 1);
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		// for (int i = 1; i <= m; i++) b[i] = rand() % 100;
		sort(b + 1, b + m + 1);
		build(1, 0, n);
		int j1 = 1, j2 = 1, j3 = 1;
		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			while (j1 <= n && evt[j1].first <= b[i]) Update(1, 0, n, evt[j1].second, n, -1), j1++;
			while (j2 <= n && evt[j2].first < b[i]) Update(1, 0, n, 0, evt[j2].second - 1, 1), j2++;
			while (j3 < i && b[j3] < b[i]) Update(1, 0, n, 0, pos[j3] - 1, 1), j3++;
			pos[i] = seg[1].p, ans += seg[1].v;
			assert(pos[i] >= pos[i - 1]);
		}
		j1 = 1;
		for (int i = 1; i <= n; i++) {
			while (j1 <= n && evt[j1].first < evt[i].first) chn(evt[j1].second, 1), j1++;
			ans += qry(n) - qry(evt[i].second);
		}
		while (j1 != 1) j1--, chn(evt[j1].second, -1);
		printf("%lld\n", ans);
	}
}