#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, Q;
int X[101010];
int A[105];
int B[105];
ll S1[105];
ll D[10101];
ll S[10101];

ll sum(int l, int r) {
	l = max(l, 0);
	if(!l) return S[r];
	return (S[r] + MOD - S[l - 1]) % MOD;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i < N; i++) {
		scanf("%d", &B[i]);
		S1[i] = S1[i - 1] + B[i];
	}

	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) scanf("%d", &X[i]);

	for(int i = 0; i <= 10000; i++) S[i] = 1;

	ll s2 = 0;

	for(int i = 1; i <= N; i++) {
		s2 += S1[i - 1];
		ll t = X[1] * i + s2;
		for(int j = 0; j < min(t, 10001LL); j++) D[j] = 0;
		// printf("%d %lld\n", i, t);
		for(int j = max(t, 0LL); j <= 10000; j++) {
			D[j] = sum(j - A[i], j);
		}
		S[0] = D[0];
		for(int j = 1; j <= 10000; j++) S[j] = (S[j - 1] + D[j]) % MOD;
		// for(int j = 0; j <= 10000; j++) printf("%lld ", S[j]); puts("");
	}

	printf("%lld\n", S[10000]);

	return 0;
}