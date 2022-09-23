#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		ll ans = 0;
		for(int i = N; i >= N - K; i--) ans += A[i];
		printf("%lld\n", ans);
	}
	return 0;
}