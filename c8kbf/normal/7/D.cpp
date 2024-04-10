#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E6+8;
constant mod = 1E9+7;
constant ts = 1381;
constant iv = 978276618;

_ n, a[maxn], b[maxn], s, ia[maxn], ib[maxn], dp[maxn];
char in[maxn];

_ bhsh(_ x, _ y);
_ fhsh(_ x, _ y);
int main() {
	
	scanf("%s", in+1);
	n = strlen(in+1);
	ia[0] = ib[n+1] = 1;
	for(_ i = 1, j = ts; i <= n; ++i, j = j*ts%mod) {
		a[i] = (a[i-1]+in[i]*j)%mod;
		ia[i] = ia[i-1]*iv%mod;
	}
	for(_ i = n, j = ts; i >= 1; --i, j = j*ts%mod) {
		b[i] = (b[i+1]+in[i]*j)%mod;
		ib[i] = ib[i+1]*iv%mod;
	}
	dp[1] = 1;
	for(_ i = 2; i <= n; ++i) if(fhsh(1, i) == bhsh(1, i)) dp[i] = dp[i>>1]+1;
	for(_ i = 1; i <= n; ++i) s += dp[i];
	printf("%lld\n", s);
	
	return 0;
}

_ fhsh(_ x, _ y) {
	return (a[y]-a[x-1]+mod)%mod*ia[x]%mod;
}

_ bhsh(_ x, _ y) {
	return (b[x]-b[y+1]+mod)%mod*ib[y]%mod;
}