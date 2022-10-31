#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<20;
const long long INF = 1LL<<62;

long long add[MAXN<<1], d[2][MAXN<<1];
long long a[MAXN], b[MAXN];

int mask[MAXN];

void renew(int u, long long x) {
	add[u] += x, d[0][u] += x, d[1][u] += x;
}

void push_down(int u) {
	if (add[u]) {
		for (int j = 0; j < 2; j++) renew(u + u + j, add[u]);
		add[u] = 0;
	}
}

void push_up(int u) {
	for (int i = 0; i < 2; i++) d[i][u] = max(d[i][u + u], d[i][u + u + 1]);
}

void update(int u, int l, int r, int p, long long x, long long y) {
	if (l == r) {
		d[0][u] = max(d[0][u], x), d[1][u] = max(d[1][u], y);
		return;
	}
	push_down(u);
	int mid = l + r >> 1;
	if (p <= mid) update(u + u, l, mid, p, x, y);
	else update(u + u + 1, mid + 1, r, p, x, y);
	push_up(u);
}

void modify(int u, int l, int r, int ll, int rr, long long x) {
	if (ll > rr) return;
	if (ll <= l && r <= rr) {
		renew(u, x);
		return;
	}
	push_down(u);
	int mid = l + r >> 1;
	if (ll <= mid) modify(u + u, l, mid, ll, rr, x);
	if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr, x);
	push_up(u);
}

void query(int u, int l, int r, int ll, int rr, long long &x, long long &y) {
	if (ll > rr) return;
	if (ll <= l && r <= rr) {
		x = max(x, d[0][u]), y = max(y, d[1][u]);
		return;
	}
	push_down(u);
	int mid = l + r >> 1;
	if (ll <= mid) query(u + u, l, mid, ll, rr, x, y);
	if (mid < rr) query(u + u + 1, mid + 1, r, ll, rr, x, y);
}

int main() {
	int n, m; long long C; scanf("%d%d%I64d", &n, &m, &C); n <<= 1, m <<= 1;
	for (int i = 0; i < n+m; i++) scanf("%I64d", &a[i]), b[i] = a[i];
	merge(a, a+n, a+n, a+n+m, b);
	int N = unique(b, b+n+m) - b;
	for (int j = 0, i = 0; i < n+m; i++) {
		if (i == n) j = 0;
		while (j < N && b[j] < a[i]) j++;
		mask[j] ^= 1 << (i >= n);
	}
	for (int i = 1; i < N; i++) mask[i] ^= mask[i-1];
	long long diff = 0;
	int L = 1; a[0] = 0;
	for (int i = 1; i < N; i++) {
		if (mask[i-1] == 2) diff += b[i] - b[i-1];
		if (mask[i-1] == 1) diff -= b[i] - b[i-1];
		if (mask[i-1] == 3) a[L++] = diff - C, a[L++] = diff + C;
	}
	sort(a, a+L);
	L = unique(a, a+L) - a;
	memset(d, 0x80, sizeof d);
	update(1, 0, L-1, lower_bound(a, a+L, 0) - a, 0, 0);
	long long sumx = 0, sumy = 0;
	for (int i = 0; i < N-1; i++) {
		if (mask[i] == 0) continue;
		long long t = b[i+1] - b[i];
		if (mask[i] & 1) sumx += t;
		if (mask[i] & 2) sumy += t;
		if (mask[i] == 3) {
			int l = lower_bound(a, a+L, -C+sumy-sumx) - a;
			int r = lower_bound(a, a+L, C+sumy-sumx) - a;
			{
				long long x = -INF, y = -INF; query(1, 0, L-1, 0, l-1, x, y);
				if (y + sumy > C + x + sumx) update(1, 0, L-1, l, x, x - a[l]);
			}
			{
				long long x = -INF, y = -INF; query(1, 0, L-1, r+1, L-1, x, y);
				if (x + sumx > C + y + sumy) update(1, 0, L-1, r, y + a[r], y);
			}
			modify(1, 0, L-1, l, r, t);
		}
	}
	cout << sumx + d[0][1] << endl;
	return 0;
}