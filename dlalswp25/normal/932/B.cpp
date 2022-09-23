#include <stdio.h>

int D[1000005];
int cnt[1000005][15];

int main() {
	for(int i = 1; i <= 9; i++) D[i] = i;
	for(int i = 10; i <= 1000000; i++) {
		int now = i;
		int next = 1;
		while(now > 0) {
			int t = now % 10;
			if(t) next *= t;
			now /= 10;
		}
		D[i] = D[next];
	}
	int Q; scanf("%d", &Q);
	for(int i = 1; i <= 1000000; i++) {
		for(int j = 1; j <= 9; j++) {
			cnt[i][j] = cnt[i - 1][j];
			if(j == D[i]) cnt[i][j]++;
		}
	}
	for(int q = 0; q < Q; q++) {
		int l, r, k; scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", cnt[r][k] - cnt[l - 1][k]);
	}
	return 0;
}