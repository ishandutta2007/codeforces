#include <stdio.h>

int X[100005];

int main() {
	int N, S; scanf("%d%d", &N, &S);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		X[a]++; X[b]++;
	}

	int lf = 0;
	for(int i = 1; i <= N; i++) if(X[i] == 1) lf++;
	if(N == 2) printf("%d\n", S);
	else printf("%.10f\n", (double)S / lf * 2.0);
	return 0;
}