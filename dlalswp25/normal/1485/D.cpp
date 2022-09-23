#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[505][505];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			int t = A[i][j];
			if(i + j & 1) printf("720720 ");
			else printf("%d ", 720720 - t * t * t * t);
		}
		puts("");
	}
	return 0;
}