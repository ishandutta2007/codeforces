#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

int n;

int main() {
	scanf("%d", &n);
	printf("%d\n", 2);
	for (int i = 2; i <= n; i++) {
		printf("%lld\n", 1LL * i * (i + 1) * (i + 1) - (i - 1));
	}
	return 0;
}