#include <bits/stdc++.h>
using namespace std;

#define rep(i, l, r) for (int i = l; i <= r; i++)
#define For(i, l, r) rep(i, l, r - 1)

int g[105];
int n, k;
long long ans = 0;

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) {
		int x; scanf("%d", &x);
		g[x % k]++;
	}
	ans = int(g[0] / 2) * 2;
	For(i, 1, k) ans += min(g[i], g[k - i]);
	if (k % 2 == 0 && g[k / 2] & 1) ans--;
	printf("%lld\n", ans);
	return 0;
}