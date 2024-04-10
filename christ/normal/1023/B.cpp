#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5 + 5, MOD = 1e9 + 7;
int main () {
	ll n,k;
	scanf ("%lld %lld",&n,&k);
	ll lBound = max(1LL,k-n), rBound = min(n,k-1);
	ll ret = max(0ll,rBound - lBound + 1)
	;
	if (k % 2 == 0 && 1 <= k/2 && k/2 <= n) --ret;
	printf ("%lld\n",ret / 2);
	return 0;
}