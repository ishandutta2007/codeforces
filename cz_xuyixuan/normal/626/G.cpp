#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double eps = 1e-12;
const double inf = 1e100;
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
struct SegmentTree {
	struct Node {
		int lc, rc;
		pair <double, int> Max;
		pair <double, int> Min;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		if (l == r) {
			a[root].Max.second = l;
			a[root].Min.second = l;
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
	}
	void init(int x) {
		n = x, root = size = 0;
		build(root, 1, n);
	}
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
	}
	void modifyMax(int root, int l, int r, int pos, double d) {
		if (l == r) {
			a[root].Max.first = d;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modifyMax(a[root].lc, l, mid, pos, d);
		else modifyMax(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modifyMax(int pos, double d) {
		modifyMax(root, 1, n, pos, d);
	}
	void modifyMin(int root, int l, int r, int pos, double d) {
		if (l == r) {
			a[root].Min.first = d;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modifyMin(a[root].lc, l, mid, pos, d);
		else modifyMin(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modifyMin(int pos, double d) {
		modifyMin(root, 1, n, pos, d);
	}
} ST;
double p[MAXN], ans;
int n, t, s, q, a[MAXN], c[MAXN];
void update(int pos) {
	if (c[pos] == a[pos]) ST.modifyMax(pos, 0);
	else ST.modifyMax(pos, p[pos] * a[pos] / (a[pos] + c[pos]) / (a[pos] + c[pos] + 1));
	if (c[pos] == 0) ST.modifyMin(pos, inf);
	else ST.modifyMin(pos, p[pos] * a[pos] / (a[pos] + c[pos]) / (a[pos] + c[pos] - 1));
}
int main() {
	read(n), read(t), read(q), ST.init(n);
	for (int i = 1; i <= n; i++)
		read(p[i]);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++) {
		ST.modifyMax(i, p[i] / (a[i] + 1));
		ST.modifyMin(i, inf);
	}
	while (t > 0 && ST.a[ST.root].Max.first > eps) {
		ans += ST.a[ST.root].Max.first;
		int pos = ST.a[ST.root].Max.second;
		c[pos]++, t--, update(pos);
	}
	for (int i = 1; i <= q; i++) {
		int opt, x; read(opt), read(x);
		if (opt == 1) {
			ans -= p[x] * c[x] / (a[x] + c[x]), a[x]++;
			ans += p[x] * c[x] / (a[x] + c[x]);
			update(x);
		} else {
			ans -= p[x] * c[x] / (a[x] + c[x]), a[x]--;
			if (c[x] > a[x]) c[x]--, t++;
			ans += p[x] * c[x] / (a[x] + c[x]);
			update(x);
		}
		while (t > 0 && ST.a[ST.root].Max.first > eps) {
			ans += ST.a[ST.root].Max.first;
			int pos = ST.a[ST.root].Max.second;
			c[pos]++, t--, update(pos);
		}
		while (ST.a[ST.root].Max.first > ST.a[ST.root].Min.first + eps) {
			ans += ST.a[ST.root].Max.first - ST.a[ST.root].Min.first;
			int p = ST.a[ST.root].Max.second, q = ST.a[ST.root].Min.second;
			c[p]++, c[q]--, update(p), update(q);
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}