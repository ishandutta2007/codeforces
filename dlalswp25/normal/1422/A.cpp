#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		printf("%lld\n", (long long)a + b + c - 1);
	}
	return 0;
}