#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b, c, d, e, f; scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		int ans = abs(a - c) + abs(b - d);
		if(a == c && c == e && (b - f) * (d - f) < 0) ans += 2;
		if(b == d && d == f && (a - e) * (c - e) < 0) ans += 2;
		printf("%d\n", ans);
	}
	return 0;
}