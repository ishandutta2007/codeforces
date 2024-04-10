#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int A[1010][1010];

int H, W;

void ex() {
	puts("0"); exit(0);
}

int main() {
	scanf("%d%d", &H, &W);
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) A[i][j] = -1;

	for(int i = 0; i < H; i++) {
		int x; scanf("%d", &x);
		for(int j = 0; j < x; j++) { if(!A[i][j]) ex(); A[i][j] = 1; }
		if(A[i][x] == 1) ex(); A[i][x] = 0;
	}
	for(int i = 0; i < W; i++) {
		int x; scanf("%d", &x);
		for(int j = 0; j < x; j++) { if(!A[j][i]) ex(); A[j][i] = 1; }
		if(A[x][i] == 1) ex(); A[x][i] = 0;
	}

	int ans = 1;
	for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) {
		if(A[i][j] == -1) ans = ans * 2 % MOD;
	}
	printf("%d\n", ans);

	return 0;
}