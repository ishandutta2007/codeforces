#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, c;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld", &c, &a, &b);
		ll x = c - a;
		ll y = b - a;
		if(b * 2 <= a + c) {
			puts("2");
			continue;
		}

		ll l = 0, r = 2000000;
		while(l <= r) {
			ll m = l + r >> 1;
			if(x * (m + 1) < y * (2 * m + 1)) r = m - 1;
			else l = m + 1;
		}

		double dl = fabs(y - (double)x * (l + 1) / (2 * l + 1));
		double dr = fabs(y - (double)x * (r + 1) / (2 * r + 1));

		// printf("%f %f\n", dl, dr);

		if(dr <= dl) printf("%lld\n", 2 * r + 1);
		else printf("%lld\n", 2 * l + 1);
	}
	return 0;
}