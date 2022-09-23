#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[202020];
int W[202020];
int N, K;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= K; i++) scanf("%d", &W[i]);

		sort(A + 1, A + N + 1);
		sort(W + 1, W + K + 1);
		reverse(W + 1, W + K + 1);

		ll ans = 0;
		for(int i = N; i >= N - K + 1; i--) ans += A[i];

		int t = N;
		for(int i = K; i >= 1; i--) {
			if(W[i] != 1) break;
			ans += A[t]; t--;
		}

		int p = 1;
		for(int i = 1; i <= K; i++) {
			if(W[i] == 1) break;
			ans += A[p];
			p += (W[i] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}