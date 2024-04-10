#include<cstring>
#include<cstdio>
int main() {
	int k;
	scanf("%d", &k);
	int pw(1);
	if(k == 1 || k == 2) {
		printf("-1\n");
	}else {
		if(k % 2 == 1) {
			printf("%I64d %I64d\n", (1ll * k * k / 2) * pw, (1ll * k * k + 1) / 2 * pw);
		}else {
			printf("%I64d %I64d\n", (1ll * k * k / 4 - 1), (1ll * k * k / 4 + 1));
		}
	}
}