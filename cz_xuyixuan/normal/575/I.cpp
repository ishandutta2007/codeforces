#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
} BIT[3];
int n, q, ans[MAXN];
struct info {int x, y, val, type; } a[MAXN];
struct event {int type, x, d, timer; } b[MAXN * 5];
bool cmp(event x, event y) {
	if (x.timer == y.timer) return x.type < y.type;
	else return x.timer < y.timer;
}
void add(int &tot, int l, int r, int type, int x, int d) {
	b[++tot] = (event) {-type, x, d, l};
	b[++tot] = (event) {-type, x, -d, r + 1};
}
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2, tot = 0;
	solve(l, mid), solve(mid + 1, r);
	for (int i = l; i <= mid; i++)
		if (a[i].type) {
			int x = a[i].x, y = a[i].y, len = a[i].val;
			if (a[i].type == 1) {
				add(tot, x, x + len, 0, y, 1);
				add(tot, x, x + len, 1, x + y + len + 1, -1);
			}
			if (a[i].type == 2) {
				add(tot, x, x + len, 2, y - x + n - len, 1);
				add(tot, x, x + len, 0, y + 1, -1);
			}
			if (a[i].type == 3) {
				add(tot, x - len, x, 0, y, 1);
				add(tot, x - len, x, 2, y - x + n + len + 1, -1);
			}
			if (a[i].type == 4) {
				add(tot, x - len, x, 1, x + y - len, 1);
				add(tot, x - len, x, 0, y + 1, -1);
			}
		}
	for (int i = mid + 1; i <= r; i++)
		if (a[i].type == 0) b[++tot] = (event) {a[i].val, a[i].y, 0, a[i].x};
	sort(b + 1, b + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		if (b[i].type <= 0) BIT[-b[i].type].modify(b[i].x, b[i].d);
		else {
			int home = b[i].type, x = b[i].timer, y = b[i].x;
			ans[home] += BIT[0].query(y);
			ans[home] += BIT[1].query(x + y);
			ans[home] += BIT[2].query(y - x + n);
		}
	}
}
int main() {
	read(n), read(q);
	BIT[0].init(n * 2);
	BIT[1].init(n * 2);
	BIT[2].init(n * 2);
	for (int i = 1; i <= q; i++) {
		int opt; read(opt);
		if (opt == 1) {
			read(a[i].type), read(a[i].x);
			read(a[i].y), read(a[i].val);
		} else {
			read(a[i].x), read(a[i].y);
			a[i].type = 0, a[i].val = i;
		}
	}
	solve(1, q);
	for (int i = 1; i <= q; i++)
		if (a[i].type == 0) printf("%d\n", ans[i]);
	return 0;
}