#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll SQRT = 4e4;

ll n;
ll d[40];
map<ll, ll>	mp;
ll save[40];
bool mark[SQRT + 200];

ll get(ll x){
	if (mp.count(x))
		return	mp[x];

	vector<ll>	cnt(16);
	ll tx = x;
	for (ll i = 0; tx; i++, tx>>=1)
		if ((x >> i) & 1){
			ll z = x & save[i + 1];
			cnt[get(z)]++;
		}

	for (ll i = 0; i < 16; i++)
		if (cnt[i] == 0)
			return	mp[x] = i;
	return	-1;
}

int main(){
	for (ll i = 1; i <= 30; i++){
		ll z = -1;
		for (ll j = i - 1; j < 31; j += i)
			z ^= 1 << j;
		save[i] = z;
	}
		
	mp[0] = 0;
	for (ll i = 1; i <= 20; i++)
		d[i] = get((1<<i) - 1);
	d[21] = 4;	d[22] = 2;	d[23] = 1;	d[24] = 10;	d[25] = 9;
	d[26] = 3;	d[27] = 6;	d[28] = 11;	d[29] = 12;	d[30] = 14;
	cin >> n;
	
	ll ans = 1, cnt = max(ll(0), n - SQRT);
	for (ll i = 2; i <= min(n, SQRT); i++){
		if (mark[i])	continue;
		ll sz = 1;
		ll t = i;
		while (t <= n){
			if (t <= SQRT)	mark[t] = 1;
			else	cnt--;
			t *= i;
			sz++;
		}
		sz--;
		ans ^= d[sz];
	}
	cnt = cnt % 2;
	if (cnt)	ans ^= 1;
	if (ans == 0)
		cout << "Petya\n";
	else
		cout << "Vasya\n";
	return 0;
}