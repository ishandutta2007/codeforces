#include <iostream>
#include <cstdio>

#define ll long long

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n;
		scanf("%lld", &n);
		ll ans = 0;
		for(ll i = 0; i < 63; i++) {
			ll div = (1ll << i);
			ll q = (n + 1) / div;
			ans += q;
			if((n + 1) % div == 0) ans--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}