#include <bits/stdc++.h>

using namespace std;

int A[303][303];
int N, K;

void print() {
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) printf("%d", A[i][j]); puts("");
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) A[i][j] = 0;

		int x = 1, y = 1;
		for(int i = 1; i <= K; i++) {
			A[x][y] = 1;
			x++; y++;
			if(x > N) x = 1;
			if(y > N) y = 1;
			if(A[x][y] == 1) y++;
		}
		if(K % N == 0) printf("0\n");
		else printf("2\n");
		print();
	}
	return 0;
}