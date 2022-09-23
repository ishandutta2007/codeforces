#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b; scanf("%d%d", &a, &b);
		int x = 1;
		while(x < b) x <<= 1;
		int ans = b - a;
		for(int i = a; i < b; i++) {
			ans = min(ans, abs((i | b) - b) + (i - a) + 1);
		}
		for(int i = b; i <= x << 1; i++) {
			ans = min(ans, abs((a | i) - i) + (i - b) + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}