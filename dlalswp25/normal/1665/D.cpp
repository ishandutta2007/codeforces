#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll query(ll a, ll b) {
	printf("? %lld %lld\n", a, b);
	fflush(stdout);
	ll res; scanf("%lld", &res);
	return res;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x = 0;
		for(int i = 1; i <= 30; i++) {
			ll t = query((1LL << i - 1) - x, 3 * (1LL << i - 1) - x);
			if(t == 1 << i) x += 1 << i - 1;
		}
		printf("! %d\n", x); fflush(stdout);
	}
	return 0;
}