#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
struct info { int l, r; };
info a[MAXN];
bool cmp(info x, info y) {
	return x.l < y.l;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].l >> a[i].r;
	sort(a + 1, a + n + 1, cmp);
	int x = -1, y = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i].l > x) x = a[i].r;
		else if (a[i].l > y) y = a[i].r;
			else {
				cout << "NO" << endl;
				return 0;
			}
	}
	cout << "YES" << endl;
	return 0;
}