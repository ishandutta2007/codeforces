#include <bits/stdc++.h>

using namespace std;

int N;
int A[505050];
int D[505050];
int L[505050];
int R[505050];
int C[505050];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if(!L[A[i]]) L[A[i]] = i;
		R[A[i]] = i;
		C[A[i]]++;
	}

	for(int i = 1; i <= N; i++) {
		if(i != R[A[i]]) D[i] = D[i - 1];
		else D[i] = max(D[i - 1], D[L[A[i]] - 1] + C[A[i]]);
	}

	int ans = D[N];
	for(int i = 1; i <= N; i++) C[i] = 0;
	for(int i = N; i >= 1; i--) {
		C[A[i]]++;
		ans = max(ans, D[i - 1] + C[A[i]]);
	}
	printf("%d\n", N - ans);

	return 0;
}