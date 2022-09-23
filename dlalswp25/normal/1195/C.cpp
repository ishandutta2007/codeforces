#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[101010];
int B[101010];

ll D[101010][2];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

	D[1][0] = A[1];
	D[1][1] = B[1];
	D[2][0] = B[1] + A[2];
	D[2][1] = A[1] + B[2];

	for(int i = 3; i <= N; i++) {
		D[i][0] = max(D[i - 2][1], D[i - 1][1]) + A[i];
		D[i][1] = max(D[i - 2][0], D[i - 1][0]) + B[i];
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans = max(ans, D[i][0]);
		ans = max(ans, D[i][1]);
	}
	printf("%lld\n", ans);
	return 0;
}