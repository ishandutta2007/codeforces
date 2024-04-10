#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 1E3+8;
constant mod = 998244353;

_ tc, n, fc[maxn];

int main() {

	fc[0] = fc[1] = 1;
	for(_ i = 2; i <= 1000; ++i) fc[i] = fc[i-1]*i%mod;
	scanf("%lld", &tc);
	for(; tc--; ) {
		scanf("%lld", &n);
		if(n & 1) puts("0");
		else printf("%lld\n", fc[n>>1]*fc[n>>1]%mod);
	}

	return 0;
}