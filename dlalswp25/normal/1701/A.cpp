#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		int s = a + b + c + d;
		printf("%d\n", s == 0 ? 0 : (s == 4 ? 2 : 1));
	}
	return 0;
}