#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 3e6 + 20;

ll ss[MAXN], ans = 1, n, save[MAXN];

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

ll cal(ll a, ll b){
	return	(ss[a] * pw((ss[b] * ss[a - b]) % MOD, MOD - 2)) % MOD;
}

ll get(ll x){
	ll ret = (save[n - x] * 2 + MOD - 1) % MOD;
	ret = (ret + MOD - (n - x + 1)) % MOD;
	ret = (ret * ((cal(n + x, x) + MOD - cal(n + x - 1, x - 1)) % MOD)) % MOD;
	return	(ret * 2 % MOD);
}

int main(){
	cin >> n;
	ss[0] = save[0] = 1;
	for (ll i = 1; i < MAXN; i++){
		ss[i] = (ss[i - 1] * i) % MOD;
		save[i] = (save[i - 1] * 2) % MOD;
	}
	ans = (save[2 * n] * 2 + MOD - 1) % MOD;

	for (ll i = 0; i < n; i++)
		ans = (ans + MOD - get(i)) % MOD;
	cout << ans << endl;
	return	0;
}