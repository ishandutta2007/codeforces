#include <bits/stdc++.h>

using namespace std;

int A[5050];
int N, M;

int main() {
	scanf("%d%d", &N, &M);
	if(N <= 2) {
		if(M == 0) {
			for(int i = 1; i <= N; i++) printf("%d ", i); puts("");
			return 0;
		}
		puts("-1"); return 0;
	}
	A[1] = 1; A[2] = 2;

	int i = 3;
	for(; i <= N; i++) {
		if(M == 0) break;
		int t = (i - 1) / 2;
		if(M < t) {
			A[i] = A[i - 1] + A[i - 2 * M];
			M = 0; continue;
		}
		else { A[i] = i; M -= t; }
	}

	if(M > 0) { puts("-1"); return 0; }

	int x = A[i - 1] + 1;
	for(; i <= N; i++) {
		A[i] = 1000000000 - (N - i) * x;
	}

	for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");

	return 0;
}