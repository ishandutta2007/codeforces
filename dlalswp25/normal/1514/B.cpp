#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, K; scanf("%d%d", &N, &K);
		ll ans = 1;
		for(int i = 1; i <= K; i++) ans = ans * N % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}