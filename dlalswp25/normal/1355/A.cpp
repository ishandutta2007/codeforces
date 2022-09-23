#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll N, K; scanf("%lld%lld", &N, &K);
		for(int i = 1; i < K; i++) {
			ll tmp = N;
			ll mn = 10, mx = 0;
			while(tmp) {
				ll x = tmp % 10;
				mn = min(mn, x);
				mx = max(mx, x);
				tmp /= 10;
			}
			if(!mn) break;
			N += mn * mx;
		}
		printf("%lld\n", N);
	}
	return 0;
}