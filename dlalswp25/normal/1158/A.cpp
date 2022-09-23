#include <bits/stdc++.h>

using namespace std;

int A[101010];
int B[101010];

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= M; i++) scanf("%d", &B[i]);
	sort(A + 1, A + N + 1);
	sort(B + 1, B + M + 1);
	if(A[N] > B[1]) { puts("-1"); return 0; }
	long long ans = 0;
	for(int i = 2; i <= M; i++) ans += B[i];
	if(A[N] != B[1]) {
		ans += A[N];
		ans += B[1] - A[N - 1];
		for(int i = 1; i < N; i++) ans += (long long)A[i] * M;
	}
	else {
		ans += B[1];
		for(int i = 1; i < N; i++) ans += (long long)A[i] * M;
	}
	printf("%lld\n", ans);
	return 0;
}