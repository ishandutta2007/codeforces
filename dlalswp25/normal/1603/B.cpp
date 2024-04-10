#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll x, y; scanf("%lld%lld", &x, &y);
		if(x > y) printf("%lld\n", x + y);
		else if(x == y) printf("%lld\n", x);
		else {
			ll r = y % x;
			printf("%lld\n", y - r / 2);
		}
	}
	return 0;
}