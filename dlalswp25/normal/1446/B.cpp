#include <bits/stdc++.h>

using namespace std;

char A[5050];
char B[5050];
int N, M;

int D[5050][5050];

int main() {
	scanf("%d%d", &N, &M);
	scanf("%s", A + 1);
	scanf("%s", B + 1);

	int ans = 0;
	// for(int i = 1; i <= M; i++) D[0][i] = -i;
	// for(int i = 1; i <= N; i++) D[i][0] = -i;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			D[i][j] = max(D[i - 1][j], D[i][j - 1]) - 1;
			if(A[i] == B[j]) D[i][j] = max(D[i][j], 2 + D[i - 1][j - 1]);
			D[i][j] = max(0, D[i][j]);
			ans = max(ans, D[i][j]);
			// printf("%d ", D[i][j]);
		}
		// puts("");
	}
	printf("%d\n", ans);
	return 0;
}