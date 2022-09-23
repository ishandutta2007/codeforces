#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll a, b, c, d; scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(a > c * b) { puts("-1"); continue; }
		if(c < d) { printf("%lld\n", a); continue; }
		ll ans = a;
		ll q = c / d, r = c % d;
		// printf("%lld %lld\n", q, r);
		ans = max(ans, (q + 2) * a - b * d * q * (q + 1) / 2 - b * c);
		ll k = a / (b * d);
		if(k <= q) {
			ans = max(ans, (k + 1) * a - b * d * k * (k + 1) / 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}