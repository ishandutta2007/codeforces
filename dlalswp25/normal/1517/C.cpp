#include <bits/stdc++.h>

using namespace std;

int N;
int P[505];
int A[505][505];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &P[i]);
	for(int i = 1; i <= N; i++) A[i][i] = P[i];
	for(int i = 1; i <= N; i++) {
		int m = A[i][i];
		int x = i, y = i;
		for(int j = 0; j < m - 1; j++) {
			if(y > 1 && !A[x][y - 1]) y--;
			else x++;
			A[x][y] = P[i];
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) {
			printf("%d ", A[i][j]);
		}
		puts("");
	}
	return 0;
}