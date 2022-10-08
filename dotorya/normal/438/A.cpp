#include <stdio.h>
long long MIN(long long a,long long b) {
	if(a<b) return a;
	else return b;
}
long long d[1050];
int main() {
	int N, M, i, t1, t2;
	scanf("%d %d", &N, &M);
	long long ans = 0;
	for(i = 1; i <= N; i++) scanf("%lld", &d[i]);
	for(i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		ans += MIN(d[t1], d[t2]);
	}
	printf("%lld", ans);
	return 0;
}