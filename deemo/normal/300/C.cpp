#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 1e6 + 20;

ll a, b, n;
ll save[MAX];
ll ans;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)	ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;
}

ll c(ll x, ll y){
	ll ret = save[x];
	ret = (ret * pw((save[y] * save[n - y]) % MOD, MOD - 2)) % MOD;
	return	ret;
}

bool ok(ll x){
	while (x){
		ll t = x % 10;
		if (t != a && t != b)	return	false;
		x /= 10;
	}
	return	true;
}

int main(){
	save[0] = 1;
	for (ll i = 1; i < MAX; i++)
		save[i] = (save[i - 1] * i) % MOD;

	cin >> a >> b >> n;
	for (ll i = 0; i <= n; i++){
		ll sum = i * a + (n - i) * b;
		if (!ok(sum))	continue;
		ans = (ans + c(n, i)) % MOD;
	}
	cout << ans << endl;
	return 0;
}