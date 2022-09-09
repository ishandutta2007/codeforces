#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int now = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		now += x;
		k -= min(now, 8);
		now -= min(now, 8);
		if (k <= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}