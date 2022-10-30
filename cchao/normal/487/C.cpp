#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow_mod(ll a, ll p, ll m) {
	ll ret = 1;
	for(; p; p >>= 1, a = a * a % m)
		if(p&1) ret = ret * a % m;
	return ret % m;
}
bool test(ll n, ll a, ll d) {
	if(n == 1) return false;
	if(n == 2) return true;
	if(n == a) return true;
	if((n&1) == 0) return false;
	while(!(d&1)) d >>= 1;
	ll t = pow_mod(a, d, n);
	while((d != n - 1) && (t != 1) && (t != n - 1)) {
		t = 1LL * t * t % n;
		d <<= 1;
	}
	return t == n - 1 || (d&1) == 1;
}
bool isPrime(ll n) {
	if(n < 2) return false;
	int a[] = {2, 7, 61};
	for(int x: a) if(x < n and !test(n, x, n - 1)) return false;
	return true;
}
ll inv(ll a, ll n) {
	return a < 2 ? a : ((1 - n * 1LL * inv(n % a, a)) / a % n + n) % n;
}
int main() {
	int n;
	scanf("%d", &n);
	if(n == 1) puts("YES\n1");
	else if(n == 4) puts("YES\n1\n3\n2\n4");
	else if(isPrime(n)) {
		puts("YES");
		puts("1");
		for(int i = 2; i < n; ++i)
			printf("%d\n", (int)(i * inv(i - 1, n) % n));
		printf("%d\n", n);
	}
	else {
		puts("NO");
	}

	return 0;
}