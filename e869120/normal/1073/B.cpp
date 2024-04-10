#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int n, a[1 << 18], id[1 << 18], b[1 << 18], maxn;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); id[a[i]] = i; }
	for (int i = 1; i <= n; i++) { scanf("%d", &b[i]); }
	for (int i = 1; i <= n; i++) {
		if (i >= 2) printf(" ");
		int rem = maxn;
		maxn = max(maxn, id[b[i]]);
		printf("%d", maxn - rem);
	}
	printf("\n");
	return 0;
}