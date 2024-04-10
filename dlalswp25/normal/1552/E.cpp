#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[10101];
int B[105];
bool chk[105];
int X[105];
int Y[105];

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N * K; i++) {
		scanf("%d", &A[i]);
	}

	for(int i = 0; i * (K - 1) + 1 <= N; i++) {
		int l = i * (K - 1) + 1, r = (i + 1) * (K - 1);
		for(int j = 1; j <= N * K; j++) {
			if(A[j] < l || A[j] > r) continue;
			if(chk[A[j]]) continue;
			if(B[A[j]]) {
				X[A[j]] = B[A[j]];
				Y[A[j]] = j;
				chk[A[j]] = true;
				for(int k = l; k <= r; k++) B[k] = 0;
			}
			B[A[j]] = j;
		}
	}
	for(int i = 1; i <= N; i++) printf("%d %d\n", X[i], Y[i]);
	return 0;
}