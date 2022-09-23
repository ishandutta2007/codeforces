#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[1010101];
ll D[1010101];
ll r1, r2, r3, d;

ll C1[1010101];
ll C2[1010101];

int main() {
	scanf("%d%lld%lld%lld%lld", &N, &r1, &r2, &r3, &d);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		C2[i] = A[i] * r1 + r3;
		C1[i] = min((ll)r2, (A[i] + 1) * r1) + r1;
	}

	D[1] = C2[1] + d;
	for(int i = 2; i <= N; i++) {
		D[i] = D[i - 1] + C2[i] + d;
		D[i] = min(D[i], D[i - 2] + 4 * d + C1[i - 1] + C1[i]);
	}

	ll ans = D[N] - d;
	ans = min(ans, D[N - 1] + min(C1[N] + 2 * d, C2[N]));
	ans = min(ans, D[N - 2] + 2 * d + min(C1[N - 1], C2[N - 1]) + min(C2[N], C1[N] + 2 * d));
	printf("%lld\n", ans);
	return 0;
}