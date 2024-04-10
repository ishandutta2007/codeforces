#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long

int n;
int v[MAXN], t[MAXN];
ll st[MAXN];
ll ans[MAXN];
int a[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", v + i);
	}
	for (int i = 1; i <= n; ++ i) {
		scanf("%d", t + i);
		st[i] = st[i - 1] + t[i];
	}
	for (int i = 1; i <= n; ++ i) {
		int left = i, right = n, sit = -1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (st[mid] - st[i - 1] <= v[i]) {
				sit = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		if(i <= sit){
			++ a[i];
			-- a[sit + 1];
			ans[sit + 1] += v[i] - (st[sit] - st[i - 1]);
		}
		else {
			ans[i] += v[i];
		}
	}
	for (int i = 1; i <= n; ++ i) {
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; ++ i) {
		ans[i] += 1ll * t[i] * a[i];
	}
	for (int i = 1; i <= n; ++ i) {
		printf("%I64d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}