#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[202020];
ll D[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		ll s = 0;
		for(int i = 2; i <= N; i++) {
			D[i] = abs(A[i] - A[i - 1]);
			s += D[i];
		}
		ll ans = 1LL << 60;
		ans = min(ans, s - D[2]);
		ans = min(ans, s - D[N]);
		for(int i = 2; i < N; i++) {
			ans = min(ans, s - D[i] - D[i + 1] + abs(A[i + 1] - A[i - 1]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}