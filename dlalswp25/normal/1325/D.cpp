#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll u, v; scanf("%lld%lld", &u, &v);
	if(u == 0 && v == 0) {
		puts("0"); return 0;
	}
	if(u == v) {
		puts("1");
		printf("%lld\n", u);
		return 0;
	}

	if(u > v || u % 2 != v % 2) {
		puts("-1");
		return 0;
	}

	ll t = (v - u) / 2;
	if((t & u) == 0) {
		puts("2");
		ll z = (u & -u);
		printf("%lld %lld\n", t ^ z, t ^ u ^ z);
		return 0;
	}

	puts("3");
	v -= u;
	printf("%lld %lld %lld\n", u, v / 2, v / 2);
	return 0;
}