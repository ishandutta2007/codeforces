#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];
int B[202020];
int cntA[202020];
int cntB[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) cntA[i] = cntB[i] = 0;

		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &A[i], &B[i]);
			cntA[A[i]]++; cntB[B[i]]++;
		}

		ll ans = (ll)N * (N - 1) * (N - 2) / 6;

		for(int i = 1; i <= N; i++) {
			ans -= (ll)(cntA[A[i]] - 1) * (cntB[B[i]] - 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}