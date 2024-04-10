#include <stdio.h>
int d[10050];
int sum[10050];
int main() {
	int i, N;
	for(i = 1; i <= 10000; i++) d[i] = d[i-1]+i;
	sum[0] = 0;
	for(i = 1; i <= 10000; i++) sum[i] = sum[i-1]+d[i];
	scanf("%d", &N);
	for(i = 1; i <= 10000; i++) {
		if(N < sum[i]) break;
	}
	printf("%d", i-1);
	return 0;
}