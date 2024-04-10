#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		ll t = 1, ans = 0;
		while(K) {
			if(K & 1) ans = (ans + t) % MOD;
			t = t * N % MOD;
			K >>= 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}