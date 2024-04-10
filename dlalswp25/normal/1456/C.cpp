#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
ll A[505050];
ll S[505050];
int C[505050];

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

	int a = 0, b = 0;
	for(int i = N; i >= 1; i--) {
		C[i] = a; b++;
		if(b >= K + 1) { a++; b = 0; }
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) ans += A[i] * C[i];

	for(int i = 1; i < N; i++) {
		if(S[i] < 0) break;
		if(C[i] != C[i + 1]) continue;
		ans += S[i];
	}

	printf("%lld\n", ans);

	return 0;
}