#include <bits/stdc++.h>
using namespace std;

int a[110000];
long long s[110000];

bool can(int n, int d, int b, int k) {
	for (int i = k+1; i <= n/2; i++) {
		if ((d+1) * 1LL * i >= n) return 1;
		if (s[(d+1) * 1LL * i] < b * 1LL * (i-k)) return 0;
		if (s[n] - s[n - (d+1) * 1LL * i] < b * 1LL * (i-k)) return 0;
	}
	return 1;
}

int main() {
	int n, d, b; scanf("%d%d%d", &n, &d, &b);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	int lo = -1, hi = (n+1)/2;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (can(n, d, b, mid)) hi = mid;
		else lo = mid;
	}
	printf("%d\n", hi);
	return 0;
}