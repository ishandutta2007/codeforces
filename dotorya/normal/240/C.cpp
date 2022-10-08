#include <stdio.h>
int chk[1050];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, t=2, i, ans;
	scanf("%d", &N);
	for(i = 1;;i++) {
		if(N <= t) {
			printf("%d\n", i);
			break;
		}
		t *= 2;
	}
	t = 2;
	while(1) {
		ans = 0;
		for(i = 0; i < N; i++) {
			if((i*2/t)%2 == 0) chk[i] = 0;
			else chk[i] = 1;
			ans += chk[i];
		}
		printf("%d ", ans);
		for(i = 0; i < N; i++) {
			if(chk[i] == 0) continue;
			printf("%d ", i+1);
		}
		if(t >= N) break;
		printf("\n");
		t *= 2;
	}
	return 0;
}