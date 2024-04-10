#include <bits/stdc++.h>
using namespace std;

int n;
const int MAXN = 1<<18;

struct Node {
	int a, b, p;
	Node(int a = 0, int b = 0, int p = 0) : a(a), b(b), p(p) {}
} A[MAXN];

int d[MAXN];

void renew(int u, int t) {
	A[u].a += t, d[u] += t;
}

Node merge(Node l, Node r) {
	return Node(max(l.a, r.a), max(l.b, r.b), (l.b > r.b ? l.p : r.p));
}

void down(int u) {
	if (!d[u]) return;
	renew(u + u, d[u]);
	renew(1 + u + u, d[u]);
	d[u] = 0;
}

void up(int u) {
	A[u] = merge(A[u + u], A[u + u + 1]);
}

void build(int u, int l, int r) {
	A[u].a = A[u].b = d[u] = 0, A[u].p = r;
	if (l == r) return;
	int mid = l + r >> 1;
	build(u + u, l, mid), build(u + u + 1, mid + 1, r);
}

void add(int u, int l, int r, int ll, int rr, int t) {
	if (ll <= l && r <= rr) { renew(u, t); return; }
	int mid = l + r >> 1;
	down(u);
	if (ll <= mid) add(u + u, l, mid, ll, rr, t);
	if (mid < rr) add(u + u + 1, mid + 1, r, ll, rr, t);
	up(u);
}

void update(int u, int l, int r, int x, int t) {
	if (l == r) { A[u].b = t; return; }
	int mid = l + r >> 1;
	down(u);
	if (x <= mid) update(u + u, l, mid, x, t);
	else update(u + u + 1, mid + 1, r, x, t);
	up(u);
}

Node get(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return A[u];
	int mid = l + r >> 1;
	down(u);
	Node ret;
	if (ll <= mid) ret = merge(ret, get(u + u, l, mid, ll, rr));
	if (mid < rr) ret = merge(ret, get(u + u + 1, mid + 1, r, ll, rr));
	return ret;
}

bool check(int mid) {
	Node r = get(1, 1, n, mid + 1, n);
	int rhs = (r.p == n ? 0 : get(1, 1, n, r.p + 1, n).a);
	int lhs = get(1, 1, n, 1, r.p - 1).a - r.b;
	return lhs > rhs;
}

int L[MAXN], R[MAXN], T[MAXN];

int main() {

	scanf("%d", &n);
	int ans = 1;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &L[i], &R[i], &T[i]), R[i]++;
		if (ans + T[i] <= R[i]) {
			printf("%d ", 0);
			ans = max(L[i], ans) + T[i];
			add(1, 1, n, 1, i, T[i]);
			add(1, 1, n, i, i, L[i]);
			update(1, 1, n, i, T[i]);
			continue;
		}
		if (L[i] + T[i] >= ans) {
			printf("%d ", -1);
			continue;
		}
		int lo = 0, hi = i;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			if (check(mid)) hi = mid;
			else lo = mid;
		}
		if (hi == i) {
			printf("%d ", -1);
			continue;
		}
		int now = min(R[i], ans) - T[i], ret = 0;
		Node rhs = get(1, 1, n, hi + 1, n);
		if (rhs.b > 0) {
			int temp = max(0, get(1, 1, n, 1, rhs.p - 1).a - rhs.b);
			if (temp < now) now = temp, ret = rhs.p;
		}
		if (T[hi] > 0) {
			int temp = get(1, 1, n, hi + 1, n).a;
			if (temp < now) now = temp, ret = hi;
		}
		if (!ret) {
			printf("%d ", -1);
			continue;
		}
		add(1, 1, n, 1, ret, -T[ret]);
		add(1, 1, n, ret, ret, -L[ret]);
		update(1, 1, n, ret, 0);
		add(1, 1, n, 1, i, T[i]);
		add(1, 1, n, i, i, L[i]);
		update(1, 1, n, i, T[i]);
		ans = max(now, L[i]) + T[i];
		printf("%d ", ret);
	}
	puts("");
	return 0;
}