#include<bits/stdc++.h>
typedef long long ll;

int n, T;
int a[100005], c[100005];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ll ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[i] = 0;
		int H = 0;
		for (int i = 1; i <= n; i++) {
			H += c[i];
			if (H > a[i] - 1) {
				c[i + 1] += H - a[i] + 1,  c[i + 2] -= H - a[i] + 1;
				c[i + 2]++; c[std::min(n + 1, i + a[i] + 1)]--;
			}
			else ans += a[i] - 1 - H, c[i + 2]++, c[std::min(n + 1, i + a[i] + 1)]--;
		}
		printf("%lld\n", ans);
	}
}