#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;

int N; ll K;
ll D[2020];
int L[2020];
int R[2020];
int A[2020];

int main() {
	scanf("%d%lld", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d%d%d", &L[i], &R[i], &A[i]);

	if((R[N] - L[N] + 1) * K < A[N]) D[N] = INF;
	else D[N] = A[N];

	for(int i = N - 1; i >= 1; i--) {
		ll k = K;
		ll cnt = 0;
		int last = -1;
		D[i] = INF;
		int j;
		for(j = i; j <= N; j++) {
			// printf("%d %d %lld %lld %d\n", i, j, k, D[i], last);
			if(k + (R[j] - L[j]) * K < A[j]) break;
			if(j < N && (R[j] < L[j + 1] || (L[j] < R[j] && k + (R[j] - L[j] - 1) * K >= A[j]))) {
				D[i] = min(D[i], cnt + A[j] + (k + K - A[j] % K) % K + D[j + 1]);
			}

			cnt += A[j];
			int r = A[j] % K;
			if(k < r) k += K;
			k = (k - r) % K;
		}
		if(j > N) D[i] = min(D[i], cnt);
	}
	// for(int i = 1; i <= N; i++) printf("%lld ", D[i]); puts("");

	printf("%lld\n", D[1] == INF ? -1 : D[1]);

	return 0;
}