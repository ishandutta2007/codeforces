#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const long long INF = 1e18;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, m, P, value[MAXN]; ll s[MAXN];
int block, tot, belong[MAXN], l[MAXN], r[MAXN];
struct SegmentTree {
	struct Node {
		int lc, rc;
		vector <ll> a;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r) {
		root = ++size;
		a[root].a.push_back(-INF);
		if (l == r) {
			a[root].a.push_back(P - value[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid);
		build(a[root].rc, mid + 1, r);
		int len = mid - l + 1, ren = r - mid;
		for (int i = 1, j = 0; i <= len + ren; i++) {
			while (i - j > ren) j++;
			while (j + 1 <= len && a[a[root].lc].a[j + 1] + s[mid] - s[l - 1] - 1ll * P * (j + 1) <= a[a[root].rc].a[i - (j + 1)]) j++;
			a[root].a.push_back(a[a[root].lc].a[j] + max(0ll, a[a[root].rc].a[i - j] - (a[a[root].lc].a[j] + s[mid] - s[l - 1] - 1ll * P * j)));
			if (j + 1 <= len) chkmin(a[root].a[i], a[a[root].lc].a[j + 1] + max(0ll, a[a[root].rc].a[i - (j + 1)] - (a[a[root].lc].a[j + 1] + s[mid] - s[l - 1] - 1ll * P * (j + 1))));
		}
	}
	void init(int x) {
		n = x;
		root = size = 0;
		build(root, 1, n);
	}
	void query(int root, int l, int r, int ql, int qr, ll &ans) {
		if (l == ql && r == qr) {
			int cnt = upper_bound(a[root].a.begin(), a[root].a.end(), ans) - (a[root].a.begin()) - 1;
			ans += s[r] - s[l - 1] - 1ll * cnt * P;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= ql) query(a[root].lc, l, mid, ql, min(mid, qr), ans);
		if (mid + 1 <= qr) query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, ans);
	}
	ll query(int l, int r) {
		ll ans = 0;
		query(root, 1, n, l, r, ans);
		return ans;
	}
} ST;
int main() {
	read(n), read(m), read(P);
	for (int i = 1; i <= n; i++) {
		read(value[i]);
		s[i] = s[i - 1] + value[i];
	}
	ST.init(n);
	for (int i = 1; i <= m; i++) {
		int l, r; read(l), read(r);
		writeln(ST.query(l, r));
	}
	return 0;
}