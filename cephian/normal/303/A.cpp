#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	scanf("%d", &n);

	if (!(n & 1)) {
		printf("-1\n");
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d", i % n);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}
	for (int i = 0; i < n; ++i) {
		printf("%d", i % n);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}
	for (int i = 0; i < n; ++i) {
		printf("%d", (i*2)% n);
		if (i == n - 1) printf("\n");
		else printf(" ");
	}

	return 0;
}