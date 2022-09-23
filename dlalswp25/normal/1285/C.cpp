#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	ll X; scanf("%lld", &X);
	ll a, b;
	for(ll i = 1; i * i <= X; i++) {
		if(X % i) continue;
		ll j = X / i;
		if(gcd(i, j) > 1) continue;
		a = i, b = j;
	}
	printf("%lld %lld\n", a, b);

	return 0;
}