#include <bits/stdc++.h>

using namespace std;

int N;
char A[2][202020];
int D[2][202020];

int main() {
	scanf("%d", &N);
	scanf("%s", A[0] + 1);
	scanf("%s", A[1] + 1);
	int tot = 0;
	for(int i = 0; i < 2; i++) for(int j = 1; j <= N; j++) tot += (A[i][j] == '1');

	for(int i = N; i >= 1; i--) {
		for(int j = 0; j < 2; j++) {
			if(A[1 - j][i] == '0') {
				D[j][i] = D[j][i + 1];
				continue;
			}
			else {
				if(A[j][i + 1] == '1') {
					D[j][i] = min(1 + D[j][i + 1], 1 + D[1 - j][i + 2]);
				}
				else {
					D[j][i] = min(D[1 - j][i + 1], 1 + D[j][i + 1]);
				}
			}
		}
	}
	printf("%d\n", tot - D[0][1]);
	return 0;
}