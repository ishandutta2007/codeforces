#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#include<utility>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll BASE = 701;
const ll MAXN = 1e5 + 20;

ll n, m;
string s;
ll vec[20], sz[20], h[MAXN], save[MAXN];

ll hsh(string t){
	ll h = 0;
	for (ll i = 0; i < t.size(); i++)
		h = (h * BASE + t[i]) % MOD;
	return	(h << ll(32)) ^ (t[0] * t[0] * (ll)t.size());
}

void init(){
	for (ll i = 0; i < n; i++)
		h[i + 1] = (h[i] * BASE + s[i]) % MOD;
	save[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		save[i] = (save[i - 1] * BASE) % MOD;
}

ll get(ll l, ll r){
	ll ret = (h[r] + MOD - ((h[l] * save[r - l]) % MOD)) % MOD;
	return	(ret << ll(32)) ^ (s[l] * s[l] * (r - l));
}

ll ok(ll x){
	ll cnt = 0;
	for (ll i = 0; i < x - 1; i++)
		for (ll j = 0; j < m; j++)
			if (i + 1 >= sz[j])
				if (get(i + 1 - sz[j], i + 1) == vec[j])	cnt++;

	for (ll i = x - 1; i < n; i++){
		for (ll j = 0; j < m; j++){
			if (x >= sz[j])
				if (get(i + 1 - sz[j], i + 1) == vec[j])	cnt++;
			if (i - x >= 0 && sz[j] <= x)
				if (get(i - x, i - x + sz[j]) == vec[j])	cnt--;
		}
		if (cnt == 0)	
			return	i + 1 - x;
	}
	return	-1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> m;
	n = s.size();
	init();
	for (ll i = 0; i < m; i++){
		string temp;	cin >> temp;
		vec[i] = hsh(temp);
		sz[i] = temp.size();
	}

	ll b = 0, e = n, ret = 0, ind = 0;
	while (b <= e){
		ll mid = (b + e)/ 2, temp;
		if ((temp = ok(mid)) != -1){
			ret = mid;
			ind = temp;
			b = mid + 1;
		}
		else	e = mid - 1;
	}
	cout << ret << " " << ind << endl;
	return 0;
}