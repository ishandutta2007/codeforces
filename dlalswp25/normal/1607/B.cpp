#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll x, n; scanf("%lld%lld", &x, &n);
		for(ll i = n / 4 * 4 + 1; i <= n; i++) {
			if(x & 1) x += i;
			else x -= i;
		}
		printf("%lld\n", x);
	}
	return 0;
}