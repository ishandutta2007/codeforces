#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll K;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		ll sum = 0;
		for(int i = 1; i <= N; i++) sum += A[i];

		if(sum <= K) { puts("0"); continue; }
		ll rem = sum - K;
		ll ans = rem;

		for(int i = N; i > 1; i--) {
			rem -= (A[i] - A[1]);
			ans = min(ans, max(0LL, (rem + (N - i + 1)) / (N - i + 2)) + (N - i + 1));
		}
		printf("%lld\n", ans);
	}
	return 0;
}