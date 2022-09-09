#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
struct info {int l, r, x, y, home; };
int n, m, value[MAXN], BIT[MAXN];
long long ans[MAXN];
info a[MAXN];
void modify(int x) {
	for (int i = x; i <= n; i += i & -i)
		BIT[i]++;
}
int query(int l, int r) {
	int ans = 0;
	for (int i = r; i >= 1; i -= i & -i)
		ans += BIT[i];
	for (int i = l - 1; i >= 1; i -= i & -i)
		ans -= BIT[i];
	return ans;
}
bool cmp(info x, info y) {
	return x.l < y.l;
}
bool cnp(info x, info y) {
	return x.r > y.r;
}
long long func(long long x) {
	return x * (x - 1) / 2;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	long long tmp = func(n);
	for (int i = 1; i <= m; i++) {
		cin >> a[i].l >> a[i].x >> a[i].r >> a[i].y;
		a[i].home = i;
		ans[i] = tmp - func(a[i].l - 1) - func(a[i].x - 1) - func(n - a[i].r) - func(n - a[i].y);
	}
	sort(a + 1, a + m + 1, cmp);
	memset(BIT, 0, sizeof(BIT));
	int pos = 1;
	while (pos <= m && a[pos].l == 1) pos++;
	for (int i = 1; i <= n; i++) {
		modify(value[i]);
		while (pos <= m && a[pos].l == i + 1) {
			ans[a[pos].home] += func(query(1, a[pos].x - 1)) + func(query(a[pos].y + 1, n));
			pos++;
		}
	}
	sort(a + 1, a + m + 1, cnp);
	memset(BIT, 0, sizeof(BIT));
	pos = 1;
	while (pos <= m && a[pos].r == n) pos++;
	for (int i = n; i >= 1; i--) {
		modify(value[i]);
		while (pos <= m && a[pos].r == i - 1) {
			ans[a[pos].home] += func(query(1, a[pos].x - 1)) + func(query(a[pos].y + 1, n));
			pos++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << endl;
	return 0;
}