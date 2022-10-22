#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cassert>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 200;
const ll LOG = 20;

ll n, vec[MAXN];
map<ll, ll>	mp;
ll ss[LOG][MAXN];
ll save[MAXN];

void init(){
	for (ll i = 0; i < n; i++)
		ss[0][i] = vec[i];
	for (ll j = 1; j < LOG; j++)
		for (ll i = 0; i < n; i++)
			if (i + (1 << (j - 1)) >= n)
				ss[j][i] = ss[j - 1][i];
			else
				ss[j][i] = __gcd(ss[j - 1][i], ss[j - 1][i + (1 << (j - 1))]);

	save[2] = 0;
	for (ll i = 3, j = 1; i < MAXN; i += (1 << j), j++){
		ll k = i;
		for (ll k = i; k < MAXN && k < i + (1 << j); k++)
			save[k] = j;
	}
}

void fill(){
	for (ll i = 0; i < n; i++){
		ll z = vec[i], cur = i;
		while (z > 1 && cur < n){
			ll tc = cur;
			for (ll k = LOG - 1; k >= 0; k--){
				if (cur + (1 << k) > n)	continue;
				ll g = ss[k][cur];
				if (__gcd(g, z) == z)
					cur += 1 << k;
			}
			mp[z] += cur - tc;
			if (cur < n)	
				z = __gcd(z, vec[cur]);
		}
		mp[1] += max((ll)0, n - cur);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	init();
	fill();

	ll q;	cin >> q;
	while (q--){
		ll x;	cin >> x;
		cout << mp[x] << "\n";
	}
	return 0;
}