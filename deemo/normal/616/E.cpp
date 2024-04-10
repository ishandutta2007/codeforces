#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<utility>

using namespace std;

typedef long long ll;

const ll SQRT = 3e6 + 1e5;
const ll MOD = 1e9 + 7;

ll n, m, ans;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;
}

ll zzz;
ll get(ll r, ll l){
	ll g = n/r;
	ll z = n % r;
	z %= MOD;
	ll t = r - l + 1;
	t %= MOD;

	ll ret = t * (((t - 1) * g) % MOD + 2 * z) % MOD;
	return	(ret * zzz) % MOD;
}

int main(){
	zzz = pw(2, MOD - 2);
	cin >> n >> m;
	if (m > n){
		ll a = n % MOD, b = (m - n) % MOD;
		ans = (a * b) % MOD;
		m = n;
	}

	for (ll i = 1; i <= min(SQRT, m); i++)
		ans = (ans + (n % i)) % MOD;

	ll r = m;
	while (r > SQRT){
		ll temp = n/r;	
		ll b = r, e = 1, ret = 1;
		ll zz = n % r;		zz = n - zz - 1;

		ret = r;
		for (ll i = 40; i >= 0; i--){
			if ((ll(1) << i) >= ret)	continue;
			ll x = ret - (ll(1) << i);
			if (n/x == n/r)	
				ret = x;
		}

		ret = max(ret, SQRT + 1);
		ans = (ans + get(r, ret)) % MOD;
		r = ret - 1;
	}
	cout << ans << "\n";
	return	0;
}