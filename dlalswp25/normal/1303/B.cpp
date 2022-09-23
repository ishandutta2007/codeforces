#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, g, b; scanf("%d%d%d", &n, &g, &b);
		int m = (n + 1) / 2;
		ll t = m / g;
		ll d = (m % g == 0 ? (t - 1) * (g + b) + g : t * (g + b) + (m % g));
		printf("%lld\n", max(d, (ll)n));
	}
	return 0;
}