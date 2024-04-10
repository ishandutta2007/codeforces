#include <bits/stdc++.h>

using namespace std;

int N, M;
char A[505][505];
int B[505][505];
int C[505][505];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) B[i][j] = (A[i][j] == 'B');

	int sum = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			C[i][j] = (B[i][j] + B[i + 1][j] + B[i][j + 1] + B[i + 1][j + 1]) & 1;
			sum += C[i][j];
		}
	}

	int ans = sum;
	for(int i = 2; i <= N; i++) {
		for(int j = 2; j <= M; j++) {
			int tmp = sum + 3;
			if(C[i - 1][j - 1]) tmp--;
			else tmp++;
			if(C[i - 1][M]) tmp--;
			else tmp++;
			if(C[N][j - 1]) tmp--;
			else tmp++;
			if(C[N][M]) tmp--;
			else tmp++;
			ans = min(ans, tmp);
		}
	}

	printf("%d\n", ans);

	return 0;
}