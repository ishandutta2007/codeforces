#include <bits/stdc++.h>

using namespace std;

int R, N;
int D[101010];
int M[101010];
int T[101010];
int X[101010];
int Y[101010];

int main() {
	scanf("%d%d", &R, &N);
	X[0] = Y[0] = 1; D[0] = M[0] = 1;
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
		int j;
		for(j = i - 1; j >= 0; j--) {
			if(T[i] - T[j] >= 2 * R) break;
			if(T[i] - T[j] >= abs(X[i] - X[j]) + abs(Y[i] - Y[j]) && D[j]) D[i] = max(D[i], D[j] + 1);
		}
		if(j >= 0) D[i] = max(D[i], M[j] + 1);
		M[i] = max(M[i - 1], D[i]);
	}
	printf("%d\n", M[N] - 1);
	return 0;
}