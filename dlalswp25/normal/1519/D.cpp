#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A[5050];
ll B[5050];
ll L[5050];
ll R[5050];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	for(int i = 1; i <= N; i++) L[i] = L[i - 1] + A[i] * B[i];
	for(int i = N; i >= 1; i--) R[i] = R[i + 1] + A[i] * B[i];

	ll ans = L[N];
	for(int i = 2; i < N; i++) {
		ll t = 0;
		for(int j = 0; ; j++) {
			int x = i - j, y = i + j;
			if(x < 0 || y > N) break;
			t += A[y] * B[x];
			if(x != y) t += A[x] * B[y];
			ans = max(ans, t + L[x - 1] + R[y + 1]);
		}
	}

	for(int i = 1; i < N; i++) {
		ll t = 0;
		for(int j = 0; ; j++) {
			int x = i - j, y = i + j + 1;
			if(x < 0 || y > N) break;
			t += A[y] * B[x] + A[x] * B[y];
			ans = max(ans, t + L[x - 1] + R[y + 1]);
		}
	}
	printf("%lld\n", ans);

	return 0;
}