//I can't keep up with your turning tables
//Under your thumb I can't breathe..

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

string s;
ll k, n;
ll ans = 0;

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

ll get(ll ind){
	ll ret = pw(2, ind);
	ll a = (pw(2, k * n) + MOD - 1) % MOD;
	ll b = (pw(2, n) + MOD - 1) % MOD;
	a = (a * pw(b, MOD - 2)) % MOD;
	return	(ret * a) % MOD;
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> k;
	n = s.size();
	for (int i = 0; i < n; i++){
		if (s[i] != '5' && s[i] != '0')	continue;
		if (k == 1)
			ans = (ans + pw(2, i)) % MOD;
		else
			ans = (ans + get(i)) % MOD;
	}
	cout << ans << endl;
	return 0;
}