#include <stdio.h>
#define ANG 100000000

bool chk[202020202];
int N;
int A[5005];
int B[5005];
int ans[5005];

int cvt(int x) {
	if(!x) return x;
	if(x < 0) return -cvt(-x);
	for(int i = 2; i * i <= x; i++) {
		if(x % (i * i) == 0) return cvt(x / i / i);
	}
	return x;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) B[i] = cvt(A[i]);
	//for(int i = 1; i <= N; i++) printf("%d ", B[i]);

	for(int i = 1; i <= N; i++) {
		ans[1]++; chk[B[i] + ANG] = true;
		int sz = (B[i] != 0);
		for(int j = i + 1; j <= N; j++) {
			if(!chk[B[j] + ANG] && B[j]) { chk[B[j] + ANG] = true; sz++; }
			ans[sz > 1 ? sz : 1]++;
		}
		for(int j = i; j <= N; j++) {
			chk[B[j] + ANG] = false;
		}
	}
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]);
	return 0;
}