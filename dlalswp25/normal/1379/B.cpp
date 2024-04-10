#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll l, r, m; scanf("%lld%lld%lld", &l, &r, &m);
		for(ll i = l; i <= r; i++) {
			ll x = m % i;
			if(x <= r - l && m >= i) {
				printf("%lld %lld %lld\n", i, l + x, l);
				break;
			}
			else if(i - x <= r - l) {
				printf("%lld %lld %lld\n", i, r - (i - x), r);
				break;
			}
		}
	}
	return 0;
}