#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll K;
ll A[3030];
ll S[3030];
int Z[3030];

int main() {
	scanf("%d%lld", &N, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		S[i] = S[i - 1] + A[i];
		Z[i] = Z[i - 1] + !A[i];
	}

	if(abs(S[N]) > Z[N] * K) { puts("-1"); return 0; }
	if(N == 1) { puts("1"); return 0; }

	ll ans = 0;
	for(int _ = 0; _ < 2; _++) {
		for(int i = 0; i < N; i++) {
			for(int j = i + 1; j <= N; j++) {
				ll sl = S[i], sm = S[j] - S[i], sr = S[j] - S[N];
				int zl = Z[i], zm = Z[j] - Z[i], zr = Z[N] - Z[j];
				ll t = min(sm + zm * K, sr + zr * K - sl + zl * K);
				ans = max(ans, t);
			}
		}
		for(int i = 1; i <= N; i++) {
			A[i] *= -1;
			S[i] *= -1;
		}
	}
	printf("%lld\n", ans + 1);
	return 0;
}