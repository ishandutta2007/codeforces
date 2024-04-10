#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define F first
#define S second

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 9;

ll n, a, b, k;
string s;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b) {
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

ll solve(ll l, ll r){
	ll ret = 0;
	for (ll i = l; i < r; i++)
		if (s[i%k] == '+')
			ret = (ret + 1ll*pw(a, n-i)*pw(b, i)) % MOD;
		else {
			ret = (ret - 1ll*pw(a, n-i)*pw(b, i)) % MOD;
			if (ret < 0) ret += MOD;
		}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b >> k;
	cin >> s;
	ll l = 0, r = n+1;
	if (r - l == k)
		cout << solve(l, r) << "\n";
	else{
		ll t = (r-l)/ (2*k);
		ll ans = 0, tl = 0;
		for (ll i = 0; i < 2*k; i++)
			if (s[i%k] == '+')
				tl = (tl + 1ll*pw(a, n-i)*pw(b, i))%MOD;
			else{
				tl = (tl - 1ll*pw(a, n-i)*pw(b, i))%MOD;
				if (tl < 0)
					tl += MOD;
			}

		ll q = pw(b, 2*k);
		q = 1ll*q*pw(pw(a, MOD-2), 2*k)%MOD;
		if (q == 1) 
			ans = tl*t%MOD;
		else
			ans = ((1ll*tl*pw(q, t)%MOD - tl)%MOD+MOD)*pw((q-1+MOD)%MOD, MOD - 2)%MOD;
		
		l += t*k*2ll;
		ans = (ans % MOD + MOD) % MOD;
		cout << (ans + solve(l, r))%MOD << "\n";
	}
	return 0;
}