//*
#include <stdio.h>
#pragma warning(disable:4996)
int d[1000050];
int d2[1000050];
int main() {
	int N, i, t;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		scanf("%d", &t);
		d[t]++;
	}
	long long ANS = 0, C = -1;
	for(i = 1000000; i >= 1; i--) {
		d2[i] += d[i];
		if(C != -1) {
			if(d2[i] < 2) {
				if(d[i] == 1) d2[i-1] += d[i];
				continue;
			}
			ANS += (long long) C * i;
			d2[i] -= 2;
			C = -1;
		}
		if(d2[i] >= 4) {
			ANS += (long long) i * i * (d2[i]/4);
			d2[i] %= 4;
		}
		if(d2[i] >= 2) {
			C = i;
		}
		if(d[i] != 0 && d2[i] % 2 == 1) d2[i-1]++;
	}
	printf("%lld", ANS);
	return 0;
}
//*/