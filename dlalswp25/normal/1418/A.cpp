#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll x, y, k; scanf("%lld%lld%lld", &x, &y, &k);
		printf("%lld\n", (k * (y + 1) - 1 - 1) / (x - 1) + 1 + k);
	}
	return 0;
}