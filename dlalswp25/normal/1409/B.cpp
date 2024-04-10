#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll a, b, x, y, n; scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &n);
		ll ans = 1LL << 62;
		if(n >= (a - x) + (b - y)) ans = x * y;
		else {
			if(n >= a - x) ans = min(ans, x * (b - (n - (a - x))));
			else ans = min(ans, (a - n) * b);

			if(n >= b - y) ans = min(ans, y * (a - (n - (b - y))));
			else ans = min(ans, (b - n) * a);
		}
		printf("%lld\n", ans);
	}
	return 0;
}