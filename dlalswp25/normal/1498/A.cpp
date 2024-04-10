#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

ll f(ll x) {
	ll ret = 0;
	while(x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll N; scanf("%lld", &N);
		for(; ; N++) {
			if(gcd(N, f(N)) > 1) break;
		}
		printf("%lld\n", N);
	}
	return 0;
}