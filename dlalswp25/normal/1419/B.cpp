#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll x; scanf("%lld", &x);
		int ans = 0;
		ll t = 1;
		while(x) {
			if(t >= 2000000000) break;
			ll c = t * (t + 1) / 2;
			if(x < c) break;
			ans++; x -= c;
			t = t * 2 + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}