//Come and show 'em what you're worth!

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ret;
}

ll get(ll A, ll n){
	if (A == 1)
		return n % MOD;

	ll ret = (pw(A, n) - 1 + MOD) % MOD;
	ret = (ret * pw(A-1, MOD - 2)) % MOD;
	return ret;
}

int main(){
	ll A, B, n, x;
	cin >> A >> B >> n >> x;
	ll ans = (x * pw(A, n)) % MOD;
	ans = (ans + B * get(A, n)) % MOD;
	cout << ans << "\n";
	return 0;
}