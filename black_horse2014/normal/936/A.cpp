#include <bits/stdc++.h>
using namespace std;

int main() {
	long long k, d, t; scanf("%lld%lld%lld", &k, &d, &t);
	
	long long a, b;
	a = k; b = (d - k % d) % d;
	long long c = 2 * t / (2 * a + b), r = (2 * t) % (2 * a + b);
	double ans = c * (a + b);
	if (r >= 2 * a) r -= 2 * a, ans += (a + r);
	else ans += r / 2.0;
	printf("%.1lf\n", ans);
	return 0;
}