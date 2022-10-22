#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 40;

map<pair<ll, ll>, ll>	mp;
vector<ll>	vec[MAXN];
ll save[MAXN];

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

ll cal(ll a, ll b){return	(save[a] * pw((save[b] * save[a - b]) % MOD, MOD - 2)) % MOD;}

void init(){
	save[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		save[i] = (save[i - 1] * i) % MOD;

	for (ll i = 2; i < MAXN; i++)
		for (ll j = i; j < MAXN; j += i)
			vec[j].push_back(i);
}

ll get(ll n, ll f){
	if (n < f)	return	0;
	if (n == f)	return	1;

	if (mp.count({n, f}))	
		return	mp[{n, f}];

	ll ret = cal(n - 1, f - 1);
	for (ll u:vec[n])
		ret = (ret + MOD - get(n/u, f)) % MOD;
	return	mp[{n, f}] = ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();

	ll q;	cin >> q;
	while (q--){
		ll n, f;	cin >> n >> f;
		cout << get(n, f) << "\n";
	}
	return	0;
}