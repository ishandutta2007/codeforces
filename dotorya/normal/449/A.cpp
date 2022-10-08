#include <stdio.h>
int main() {
	long long N, M, K, i, mx = 0, t;
	scanf("%lld %lld %lld", &N, &M, &K);
	if(N+M-2 < K) {
		printf("-1");
		return 0;
	}
	if(K <= N-1) {
		if(mx <= (N/(K+1))*M) mx = (N/(K+1))*M;
	}
	if(K <= M-1) {
		if(mx <= N*(M/(K+1))) mx = N*(M/(K+1));
	}
	for(i = 1; i*i <= N; i++) {
		if(i >= K) break;
		if(mx < (N/(i+1)) * (M/(K-i+1))) mx = (N/(i+1)) * (M/(K-i+1));
	}
	for(i = 1; i*i <= N; i++) {
		t = N/i-1;
		if(t >= K) continue;
		if(mx < (N/(t+1)) * (M/(K-t+1))) mx = (N/(t+1))*(M/(K-t+1));
	}
	printf("%lld", mx);
	return 0;
}