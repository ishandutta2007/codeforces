#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

int a[8020] = {};
int b[8020] = {};
int t = 0, mx = 0, ans = 0;

void f(int l, int r) {
	if(l == r) {
		ans += mx - b[l];
		return;
	}
	int mid = (l + r) >> 1;

	int m = 0;
	for(int i = l; i <= r; ++i) m = max(m, b[i]);
	int del = mx - m;
	for(int i = l; i <= r; ++i) b[i] += del;
	ans += del;

	f(l, mid);
	f(mid + 1, r);
}

int main() {
	int n; scanf("%d", &n);
	int m = (1 << (n + 1)) - 1;
	for(int i = 2; i <= m; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i >> 1];
	}
	for(int i = (1 << n); i <= m; ++i) {
		b[t++] = a[i];
		mx = max(mx, a[i]);
	}
	f(0, t - 1);
	printf("%d\n", ans);
	return 0;
}