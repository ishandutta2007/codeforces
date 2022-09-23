#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];
ll L[101010];
ll R[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 2; i <= N; i += 2) {
			L[i] = L[i - 2] + max(0, max(A[i - 1], A[i + 1]) - A[i] + 1);
		}
		R[N + 1] = 0;
		for(int i = N - 1; i >= 1; i -= 2) {
			R[i] = R[i + 2] + max(0, max(A[i - 1], A[i + 1]) - A[i] + 1);
		}
		if(N & 1) printf("%lld\n", L[N - 1]);
		else {
			ll ans = 1LL << 60;
			for(int i = 0; i <= N - 2; i += 2) ans = min(ans, L[i] + R[i + 3]);
			printf("%lld\n", ans);
		}
	}
	return 0;
}