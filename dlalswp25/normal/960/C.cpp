#include <stdio.h>

long long ans[10005];
long long two[65];

int main() {
	int cnt = 0;
	int tmp = 1;
	long long X, D; scanf("%lld%lld", &X, &D);
	two[1] = 1; for(int i = 2; i <= 62; i++) two[i] = two[i - 1] * 2 + 1;
	for(int i = 62; i >= 1; i--) {
		if(!X) break;
		if(two[i] > X) continue;
		for(int j = 0; j < i; j++) {
			ans[cnt++] = D * tmp;
		}
		X -= two[i]; tmp++; i++;
	}
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++) printf("%lld ", ans[i]);
	return 0;
}