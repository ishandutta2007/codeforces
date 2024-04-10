#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int K[101010];
int A[101010];
int B[101010];
int C[101010];
ll D[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &K[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 2; i <= N; i++) {
			if(A[i] > B[i]) swap(A[i], B[i]);
			C[i - 1] = A[i] + (K[i - 1] - B[i] + 1);
		}
		D[1] = B[2] - A[2] + 1;
		ll ans = 0;
		for(int i = 2; i <= N; i++) {
			ans = max(ans, D[i - 1] + K[i]);
			if(i == N) break;
			D[i] = B[i + 1] - A[i + 1] + 1;
			if(A[i + 1] != B[i + 1]) D[i] = max(D[i], D[i - 1] + C[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}