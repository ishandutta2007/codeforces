#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
		printf("%lld %lld %lld\n", a + b + c, b + c, c);
	}
	return 0;
}