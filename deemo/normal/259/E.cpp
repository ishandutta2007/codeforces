#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll ans;
ll n, vec[MAXN], sec[MAXN], p[MAXN];

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

ll get(ll maxi, bool fl = 0){
	if (maxi == 1 && fl == 1)	return	0;
	ll ret = 1;
	ll t = 0;
	for (ll i = 1; i * i <= maxi; i++)
		if (maxi % i == 0){
			sec[t++] = i;
			if (i * i != maxi)	sec[t++] = maxi / i;
		}
	sort(sec, sec + t);
	if (fl)	t--;
	for (ll i = 0; i < t; i++)
		p[i] = n - (lower_bound(vec, vec + n, sec[i]) - vec);
	
	for (ll i = 0; i < t; i++){
		if (i != t - 1)	
			p[i] = p[i] - p[i + 1];
		ret = (ret * pw(i + 1, p[i])) % MOD;
	}		
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	
	ll maxi = vec[n - 1];
	for (ll i = maxi; i; i--){
		ans = (ans + get(i)) % MOD;
		ans = (ans + MOD - get(i, 1)) % MOD;
	}
	cout << ans << endl;
	return 0;
}