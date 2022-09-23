#include <bits/stdc++.h>

using namespace std;

int A[303][303];
int N;
int c;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int y;
			if(i & 1) y = j;
			else y = (N + 1 - j);
			A[i][y] = ++c;
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%d ", A[j][i]);
		}
		puts("");
	}

	return 0;
}