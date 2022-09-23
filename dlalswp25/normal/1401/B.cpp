#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x1, y1, z1, x2, y2, z2;
		scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
		int ans = 0;
		int m = min(z1, y2);
		ans += 2 * m;
		z1 -= m; y2 -= m;
		z2 -= x1;
		z2 -= z1;
		ans -= 2 * max(0, z2);
		printf("%d\n", ans);
	}
	return 0;
}