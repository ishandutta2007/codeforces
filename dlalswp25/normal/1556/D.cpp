#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[10101];
int O[10101];
int ans[10101];
int X;
int bit[35];

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 0; i < 30; i++) bit[i] = -1;
	for(int i = 2; i <= N; i++) {
		printf("and %d %d\n", 1, i);
		fflush(stdout);
		scanf("%d", &A[i]);
		printf("or %d %d\n", 1, i);
		fflush(stdout);
		scanf("%d", &O[i]);

		for(int j = 0; j < 30; j++) {
			if(~O[i] & 1 << j) {
				bit[j] = 0;
			}
			if(A[i] & 1 << j) {
				bit[j] = 1;
			}
		}
	}

	printf("and %d %d\n", 2, 3); fflush(stdout);
	scanf("%d", &X);
	for(int i = 0; i < 30; i++) {
		if(bit[i] != -1) continue;
		if(X & 1 << i) bit[i] = 0;
		else bit[i] = 1;
	}

	for(int i = 0; i < 30; i++) ans[1] += bit[i] * (1 << i);
	for(int i = 2; i <= N; i++) {
		for(int j = 0; j < 30; j++) {
			if(~O[i] & 1 << j) continue;
			if(A[i] & 1 << j) {
				ans[i] += 1 << j;
				continue;
			}
			if(~ans[1] & 1 << j) ans[i] += 1 << j;
		}
	}

	sort(ans + 1, ans + N + 1);
	printf("finish %d\n", ans[K]);
	fflush(stdout);

	return 0;
}