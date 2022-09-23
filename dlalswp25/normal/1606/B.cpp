#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N, K;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%lld%lld", &N, &K);
		ll t = 1, ans = 0;
		while(t < K) {
			t <<= 1; ans++;
		}
		if(t < N) ans += (N - t + K - 1) / K;
		printf("%lld\n", ans);
	}
	return 0;
}