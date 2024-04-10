#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll K, X; scanf("%lld%lld", &K, &X);
		if(X <= K * (K + 1) / 2) {
			ll l = 1, r = K;
			while(l <= r) {
				ll m = l + r >> 1;
				if(m * (m + 1) / 2 >= X) r = m - 1;
				else l = m + 1;
			}
			printf("%lld\n", l);
		}
		else if(X <= K * K) {
			X -= K * (K + 1) / 2;
			ll l = 1, r = K - 1;
			while(l <= r) {
				ll m = l + r >> 1;
				if(K * (K - 1) / 2 - (K - 1 - m) * (K - m) / 2 >= X) r = m - 1;
				else l = m + 1;
			}
			printf("%lld\n", K + l);
		}
		else {
			printf("%lld\n", 2 * K - 1);
		}
	}
	return 0;
}