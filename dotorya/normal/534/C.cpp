#include <stdio.h>
typedef long long ll;
ll d[200050];
int main() {
	int N, i;
	ll A, sum = 0;
	scanf("%d %lld", &N, &A);
	for(i = 1; i <= N; i++) {
		scanf("%d", &d[i]);
		sum += d[i];
	}
//	if(N == 1) {
//		printf("%d", d[1]-1);
//		return 0;
//	}
	for(i = 1; i <= N; i++) {
		int t = 0;
		if(A-N+1 <= d[i]) t += d[i] - (A-N+1);
		if(A-(sum - d[i]) >= 1) t += A-(sum-d[i])-1;
		printf("%d ", t);
	}
	return 0;
}