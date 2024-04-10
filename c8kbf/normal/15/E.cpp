#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E6+8;
constant mod = 1E9+9;

_ n, a[maxn], b[maxn], s;

int main() {
	
	scanf("%lld", &n);
	n >>= 1;
	a[0] = 1;
	for(_ i = 1; i <= n; ++i) a[i] = (a[i-1]<<1)%mod;
	b[1] = 1;
	for(_ i = 2; i <= n; ++i) {
		b[i] = b[i-1]*(a[i]-3)%mod;
//		printf("%lld ", b[i]);
		s = (s+4*b[i])%mod;
	}	
//	printf("\n%lld\n", s);
	printf("%lld\n", (10+8*s%mod+2*s*s%mod)%mod);
	
	return 0;
}