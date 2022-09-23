#include <bits/stdc++.h>

using namespace std;

int A[505][505];
int c = 0;
int N;

bool chk[505];

int B[4][4] = {
	{9, 6, 5, 0},
	{8, 7, 4, 10},
	{11, -1, 3, 1},
	{-1, -1, 12, 2}
};

int main() {
	scanf("%d", &N);
	if(N <= 2) { puts("-1"); return 0; }
	if(N == 3) {
		puts("8 3 4");
		puts("7 6 9");
		puts("1 2 5");
		return 0;
	}
	if(N == 4) {
		puts("4 3 6 12");
		puts("7 5 9 15");
		puts("14 1 11 10");
		puts("13 8 16 2");
		return 0;
	}

	A[N - 1][N - 2] = 1;
	A[N][N - 2] = 2;
	A[N][N - 3] = 3;

	c = 4;

	for(int i = N; i >= 1; i--) {
		int y = 1;
		for(int j = 1; j <= N - 4; j++) {
			if(!chk[j]) {
				y = j;
				A[i][y] = c;
				c++;
			}
		}

		for(int j = 1; j <= N - 4; j++) chk[j] = false;
		if(i > 1) {
			A[i - 1][y] = c;
			c++;
			chk[y] = true;
		}
	}

	A[1][N - 3] = c; c++;
	chk[N - 3] = true;

	for(int i = 1; i < N - 4; i++) {
		int y = 1;
		for(int j = N; j > N - 4; j--) {
			if(!chk[j]) {
				y = j;
				A[i][y] = c;
				c++;
			}
		}

		for(int j = N - 3; j <= N; j++) chk[j] = false;

		A[i + 1][y] = c; c++;
		chk[y] = true;
	}

	for(int j = N - 3; j <= N; j++) {
		if(!chk[j]) {
			A[N - 4][j] = c;
			c++;
		}
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(B[i][j] < 0) continue;
			A[N - 3 + i][N - 3 + j] = B[i][j] + c;
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%d ", A[i][j]);
		}
		puts("");
	}

	return 0;
}