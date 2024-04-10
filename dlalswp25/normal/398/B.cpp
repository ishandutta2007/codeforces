#include <stdio.h>

double D[2005][2005];
bool X[2005];
bool Y[2005];

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i = 0; i < M; i++) {
		int x, y; scanf("%d%d", &x, &y);
		X[x] = true; Y[y] = true;
	}

	D[0][0] = 0;
	for(int i = 1; i <= N; i++) D[i][0] = 1 + D[i - 1][0] + (double)(N - i) / i;
	for(int i = 1; i <= N; i++) D[0][i] = 1 + D[0][i - 1] + (double)(N - i) / i;

	for(int i = 1; i < N; i++) {
		for(int j = 1; j < N; j++) {
			double X = (double)N * (i + j) - i * j;
			D[i][j] = 1 + (D[i - 1][j - 1]) * i * j / X
					+ (D[i - 1][j]) * i * (N - j) / X
					+ (D[i][j - 1]) * (N - i) * j / X
					+ (N - i) * (N - j) / X;
		}
	}
	int A = 0, B = 0;
	for(int i = 1; i <= N; i++) if(!X[i]) A++;
	for(int i = 1; i <= N; i++) if(!Y[i]) B++;
	//printf("%d %d\n", A, B);
	if(!A && !B) {
		puts("0.000000");
		return 0;
	}
	int t = 0;
	if(A == N) { A--; B--; t++; }
	printf("%.10f\n", D[A][B] + t);
	return 0;
}