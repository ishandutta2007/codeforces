#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int LU[101010];
int RU[101010];
int LD[101010];
int RD[101010];
int mxLD[101010];
int mxLU[101010];
int mxRD[101010];
int mxRU[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 2; i <= N; i++) {
		if(A[i - 1] < A[i]) {
			LU[i] = LU[i - 1] + 1;
			LD[i] = 0;
		}
		else {
			LU[i] = 0;
			LD[i] = LD[i - 1] + 1;
		}
	}

	for(int i = N - 1; i >= 1; i--) {
		if(A[i] > A[i + 1]) {
			RU[i] = RU[i + 1] + 1;
			RD[i] = 0;
		}
		else {
			RU[i] = 0;
			RD[i] = RD[i + 1] + 1;
		}
	}

	for(int i = 1; i <= N; i++) {
		mxLD[i] = max(mxLD[i - 1], LD[i]);
		mxLU[i] = max(mxLU[i - 1], LU[i]);
	}
	for(int i = N; i >= 1; i--) {
		mxRD[i] = max(mxRD[i + 1], RD[i]);
		mxRU[i] = max(mxRU[i + 1], RU[i]);
	}

	int ans = 0;
	for(int i = 2; i < N; i++) {
		if(A[i] < A[i - 1] || A[i] < A[i + 1]) continue;
		if(LU[i] != RU[i]) continue;
		if(LU[i] & 1) continue;
		int t = max(max(mxLD[i - 1], mxLU[i - LU[i] - 1]), max(mxRD[i + 1], mxRU[i + LU[i] + 1]));
		if(t >= LU[i]) continue;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}