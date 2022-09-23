#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll x, y; scanf("%lld%lld", &x, &y);
		ll b = 2;
		ll ans = 0;
		while(1) {
			if((b + 1) * (b - 1) > x) break;
			if(b > y) break;
			ans += b - 1; b++;
		}
		while(b <= y) {
			ll k = x / (b + 1);
			if(!k) break;
			ll r = min(x / k - 1, y);
			if(b <= r) ans += k * (r - b + 1);
			b = r + 1;
		}

		printf("%lld\n", ans);
	}
	return 0;
}