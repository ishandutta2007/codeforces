#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll n, m; scanf("%lld%lld", &n, &m);
		ll a = (n - m) / (m + 1);
		ll b = (n - m) % (m + 1);
		ll ans = n * (n + 1) / 2;
		ans -= b * (a + 2) * (a + 1) / 2;
		ans -= (m + 1 - b) * a * (a + 1) / 2;
		printf("%lld\n", ans);
	}
	return 0;
}