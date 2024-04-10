#include <stdio.h>

int ans[1000005];

int main() {
	int N, A, B; scanf("%d %d %d", &N, &A, &B);
	int x = 0, y = 0;
	for(x = 0; x <= N; x++) {
		if(x * A > N) break;
		if((N - x * A) % B == 0) {
			y = (N - x * A) / B;
			break;
		}
	}
	if(x * A + y * B != N) {
		puts("-1"); return 0;
	}
	int now = 1;
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < A; j++) {
			ans[now + j] = now + (j + 1) % A;
		}
		now += A;
	}
	for(int i = 0; i < y; i++) {
		for(int j = 0; j < B; j++) {
			ans[now + j] = now + (j + 1) % B;
		}
		now += B;
	}
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]);
	return 0;
}