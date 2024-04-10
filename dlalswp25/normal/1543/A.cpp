#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll a, b; scanf("%lld%lld", &a, &b);
		ll x = abs(a - b);
		if(!x) puts("0 0");
		else printf("%lld %lld\n", x, min(a % x, x - (a % x)));
	}
	return 0;
}