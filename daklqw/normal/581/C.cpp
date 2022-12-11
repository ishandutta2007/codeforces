#include <stdio.h>
#include <algorithm>
int n, k, ans;
int a[100100];
bool cmp(int a, int b) {
	return a % 10 > b % 10;
}
int min(int a, int b) {return a > b ? b : a; }
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), ans += a[i] / 10;
	std::sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (a[i] % 10 != 0 && k >= 10 - a[i] % 10) k -= 10 - a[i] % 10, a[i] += 10 - a[i] % 10, ans++;
		else break; 
	}
	k = k / 10 * 10;
	for (int i = 1; i <= n && k; i++) {
		int t = min(k / 10, 10 - a[i] / 10);
		ans += t, k -= 10 * t;
	}
	printf("%d\n", ans);
	return 0;
}