#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll n, s; scanf("%lld%lld", &n, &s);
		ll l = 1, r = s;
		int t = n / 2 + 1;
		while(l <= r) {
			ll m = l + r >> 1;
			if(t * m > s) r = m - 1;
			else l = m + 1;
		}
		printf("%lld\n", r);
	}
	return 0;
}