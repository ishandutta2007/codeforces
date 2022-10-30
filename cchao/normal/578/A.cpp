#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int t = a + b;
	double ans = -1;
	int l = 1, r = 1000000000;
	while(l <= r) {
		int m = (l + r) >> 1;
		if(t >= 1LL * m * b * 2) {
			ans = 0.5 * t / m;
			l = m + 1;
		}
		else r = m - 1;
	}
	if(ans < 0) puts("-1");
	else printf("%.12f\n", ans);

	return 0;
}