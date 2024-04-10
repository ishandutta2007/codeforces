#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int B[202020];
int X[202020];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	X[1] = 0; A[1] = B[1];
	X[2] = A[1];
	for(int i = 2; i <= N; i++) {
		A[i] = X[i] + B[i];
		X[i + 1] = max(X[i], A[i]);
	}
	for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	return 0;
}