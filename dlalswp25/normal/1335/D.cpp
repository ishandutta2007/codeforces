#include <bits/stdc++.h>

using namespace std;

int A[10][10];

int X[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int Y[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for(int i = 1; i <= 9; i++) for(int j = 1; j <= 9; j++) scanf("%1d", &A[i][j]);

		for(int i = 0; i < 9; i++) {
			int x = X[i], y = Y[i];
			A[x][y] = A[x][y] % 9 + 1;
		}

		for(int i = 1; i <= 9; i++) {
			for(int j = 1; j <= 9; j++) printf("%d", A[i][j]);
			puts("");
		} 
	}
	return 0;
}