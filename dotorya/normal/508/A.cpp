#include <stdio.h>
int d[1050][1050];
int main() {
	int N, M, K, i, t1, t2;
	scanf("%d %d %d", &N, &M, &K);
	for(i = 1; i <= K; i++) {
		scanf("%d %d", &t1, &t2);
		d[t1][t2] = 1;
		if(d[t1-1][t2-1] + d[t1][t2-1] + d[t1-1][t2] + d[t1][t2] == 4) break;
		if(d[t1-1][t2] + d[t1-1][t2+1] + d[t1][t2] + d[t1][t2+1] == 4) break;
		if(d[t1+1][t2] + d[t1+1][t2-1] + d[t1][t2] + d[t1][t2-1] == 4) break;
		if(d[t1+1][t2] + d[t1+1][t2+1] + d[t1][t2] + d[t1][t2+1] == 4) break;
	}
	printf("%d", i%(K+1));
	return 0;
}