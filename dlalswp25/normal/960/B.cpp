#include <stdio.h>

int A[1005];
int B[1005];
int X[1005];

int myABS(int x) {
	return x > 0 ? x : (-x);
}

int main() {
	int N, k1, k2; scanf("%d%d%d", &N, &k1, &k2);
	int K = k1 + k2;

	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	for(int i = 1; i <= N; i++) X[i] = myABS(A[i] - B[i]);
	
	for(int i = 1; i <= K; i++) {
		int mx = -1, idx;
		for(int j = 1; j <= N; j++) {
			if(mx < X[j]) { idx = j; mx = X[j]; }
		}
		if(mx == 0) { X[1]++; continue; }
		else X[idx]--;
	}
	long long ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += (long long)X[i] * X[i];
	}
	printf("%lld", ans);
	return 0;
}