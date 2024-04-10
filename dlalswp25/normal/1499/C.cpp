#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll C[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &C[i]);
		ll s0 = C[1], mn0 = C[1];
		ll s1 = C[2], mn1 = C[2];
		ll ans = (C[1] + C[2]) * N;

		for(int i = 3; i <= N; i++) {
			if(i & 1) {
				s0 += C[i]; mn0 = min(mn0, C[i]);
			}
			else {
				s1 += C[i]; mn1 = min(mn1, C[i]);
			}
			ans = min(ans, s0 + mn0 * (N - (i + 1) / 2) + s1 + mn1 * (N - i / 2));
		}
		printf("%lld\n", ans);
	}
	return 0;
}