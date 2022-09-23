#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll p, a, b, c; scanf("%lld%lld%lld%lld", &p, &a, &b, &c);
		ll ans = (p + a - 1) / a * a;
		ans = min(ans, (p + b - 1) / b * b);
		ans = min(ans, (p + c - 1) / c * c);
		printf("%lld\n", ans - p);
	}
	return 0;
}