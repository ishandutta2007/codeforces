#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[303030];
ll B[303030];
ll D[303030];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) scanf("%lld%lld", &A[i], &B[i]);

		ll s = 0;
		for(int i = 0; i < N; i++) {
			int bef = (i + N - 1) % N;
			D[i] = max(A[i] - B[bef], 0LL);
			s += D[i];
		}

		ll ans = (1LL << 60);
		for(int i = 0; i < N; i++) {
			ans = min(ans, s - D[i] + A[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}