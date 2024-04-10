#include <bits/stdc++.h>

using namespace std;

int N;
char A[2][202020];
int D[202020][2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A[0] + 1);
		scanf("%s", A[1] + 1);
		while(N > 0) {
			if(A[0][N] == '*' || A[1][N] == '*') break;
			N--;
		}
		bool ok = false;
		for(int i = 1; i <= N; i++) {
			if(A[0][i] == '*' || A[1][i] == '*') ok = true;
			if(!ok) D[i][0] = D[i][1] = 0;
			else {
				D[i][0] = min(D[i - 1][0] + 1 + (A[1][i] == '*'), D[i - 1][1] + 2);
				D[i][1] = min(D[i - 1][1] + 1 + (A[0][i] == '*'), D[i - 1][0] + 2);
			}
		}
		printf("%d\n", min(D[N][0], D[N][1]) - 1);
	}
	return 0;
}