#include <bits/stdc++.h>

using namespace std;

int N;
char A[404][404];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		int x1 = -1, y1, x2 = -1, y2;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(A[i][j] == '*') {
					if(x1 == -1) { x1 = i; y1 = j; }
					else { x2 = i; y2 = j; }
				}
			}
		}

		if(x1 == x2) {
			x2 = x2 % N + 1;
			A[x2][y2] = '*';
		}
		else if(y1 == y2) {
			y2 = y2 % N + 1;
			A[x2][y2] = '*';
		}
		A[x1][y2] = A[x2][y1] = '*';

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				printf("%c", A[i][j]);
			}
			puts("");
		}
	}
	return 0;
}