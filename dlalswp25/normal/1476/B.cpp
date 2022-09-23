#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
ll P[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 0; i < N; i++) scanf("%lld", &P[i]);
		ll mx = 0;
		ll s = 0;
		for(int i = 1; i < N; i++) {
			mx = max(mx, (100 * P[i] + K - 1) / K - s);
			s += P[i];
		}
		printf("%lld\n", max(0LL, mx - P[0]));
	}
	return 0;
}