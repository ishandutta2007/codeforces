#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll m, d, w;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%lld%lld%lld", &m, &d, &w);
		ll q = min(m, d);
		if(q == 1) { puts("0"); continue; }

		ll g = gcd(d - 1, w);
		w /= g;

		ll k = (q - 1) / w;
		printf("%lld\n", q * k - w * (k + 1) * k / 2);
	}
	return 0;
}