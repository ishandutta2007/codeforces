#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i, a, b) for (int i=a; i<b; i++)
 
ll n,m,ans, lb, ub, MOD = 1000000007;

int main() {
	cin >> n >> m;
	if (n<m) ans = ((m-n) % MOD)*(n % MOD) % MOD, m = n;
	ll z = n/m;
	ub = m, lb = n/(z+1)+1;
	while (ub-lb>1) {
		ll sum = (((n % lb) % MOD)+((n % ub) % MOD)) % MOD;
		sum = sum*((ub-lb+1) % MOD) % MOD;
		if (sum % 2 == 1) sum += MOD;
		ans = (ans+sum/2) % MOD;
		ub = lb-1, z++;
		lb = n/(z+1)+1;
	}
	FOR(i,1,ub+1) ans = (ans+((n%i) % MOD)) % MOD;
	cout << ans;
}