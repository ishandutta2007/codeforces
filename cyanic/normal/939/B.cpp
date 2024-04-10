#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, a, best = -1e18, now, need;
int K, p;

int main() {
	scanf("%I64d%d", &n, &K);
	for (int i=1; i<=K; i++) {
		scanf("%I64d", &a);
		now = n - n % a;
		if (now > best) best = now, p = i, need = n / a;
	}
	printf("%d %I64d", p, need);
	return 0;
}