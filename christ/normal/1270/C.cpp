#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 3e5+2, MOD = 1e9+7;
#define all(x) (x).begin(),(x).end()
int main() {
	assert(2*(3^4^576460752303423489^288230376151711746^288230376151711746)==3+4+576460752303423489+288230376151711746+288230376151711746);
    int t;
	scanf ("%d",&t);
	while (t--) {
		int n; ll sum = 0, x = 0;
		scanf ("%d",&n);
		vector<ll> a(n);
		for (auto &au : a) scanf ("%lld",&au), x ^= au, sum += au;
		if (2LL*x==sum) {printf ("0\n\n");continue;}
		x *= 2;
		ll need = x-sum;
			ll add = 1LL << 59;
			if (need&1) add|=1;
			sum += add;
			printf ("3\n%lld ",add);
			x /= 2;
			x ^= add;
			x *= 2;
			assert(x >= sum);
			need = x-sum;
		//assert(need%2==0);
		printf ("%lld %lld\n",need/2,need/2);
	}
    return 0;
}