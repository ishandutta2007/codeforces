#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[202020];
int B[202020];
int pos[202020];
int idx[202020];
ll X, K, Y;

int main() {
	scanf("%d%d", &N, &M);
	scanf("%lld%lld%lld", &X, &K, &Y);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		pos[A[i]] = i;
	}

	ll Z = min(X, K * Y);

	for(int i = 1; i <= M; i++) {
		scanf("%d", &B[i]);
		idx[i] = pos[B[i]];
	}

	if(N < M) { puts("-1"); return 0; }
	for(int i = 1; i <= M; i++) {
		if(idx[i] == 0) { puts("-1"); return 0; }
		if(i > 1 && idx[i - 1] > idx[i]) { puts("-1"); return 0; }
	}

	idx[M + 1] = N + 1;
	ll ans = 0;
	for(int i = 1; i <= M + 1; i++) {
		int d = idx[i] - idx[i - 1] - 1;

		int mx = 0;
		for(int j = idx[i - 1] + 1; j < idx[i]; j++) {
			mx = max(mx, A[j]);
		}
		if(mx > max(A[idx[i - 1]], A[idx[i]])) {
			if(d < K) { puts("-1"); return 0; }
			ans += X;
			d -= K;
			ans += (d / K) * Z;
			ans += (d % K) * Y;
		}
		else {
			ans += (d / K) * Z;
			ans += (d % K) * Y;
		}
	}

	printf("%lld\n", ans);
	return 0;
}