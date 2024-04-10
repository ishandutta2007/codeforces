#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, x, y; scanf("%d%d%d", &x, &y, &n);
		int t = (n - y) / x;
		printf("%d\n", t * x + y);
	}
	return 0;
}