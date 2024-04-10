//Toxic

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 6e5 + 30;
const ll MOD = 1e9 + 7;
const ll BASE1 = 701;
const ll BASE2 = 721;

ll n, m;
ll ss[MAXN];
map<pair<ll, ll>, ll>	mp;
map<ll, ll>	cn;

ll hs(string s){
	ll h1 = 0, h2 = 0;
	for (ll i = 0; i < (ll)s.size(); i++){
		h1 = (h1 * BASE1 + s[i]) % MOD, h2 = (h2 * BASE2 + s[i]) % MOD;
		ss[i] = (h1 << 32) ^ h2;
	}
	return	(h1 << 32) ^ h2;
}

void process(string s){
	ll sz = s.size();
	cn[hs(s)]++;
	
	ll h1 = 0, h2 = 0, b = 1, bb = 1;
	for (ll i = sz - 1; i >= 0; i--){
		if (i)
			mp[make_pair(ss[i - 1], (h1 << 32) ^ h2)]++;
		else
			mp[make_pair(0, (h1 << 32) ^ h2)]++;

		h1 = (h1 + b * s[i]) % MOD;
		h2 = (h2 + bb * s[i]) % MOD;

		b = (b * BASE1) % MOD;
		bb = (bb * BASE2) % MOD;
	}
}

bool found(string s){
	ll h = hs(s);
	ll c = cn[h], sz = s.size();

	ll h1 = 0, h2 = 0, b = 1, bb = 1;
	for (ll i = sz - 1; i >= 0; i--){
		ll cc;
		if (i)
			cc = mp[make_pair(ss[i - 1], (h1 << 32) ^ h2)];
		else
			cc = mp[make_pair(0, (h1 << 32) ^ h2)];
		if (cc > c)
			return	true;

		h1 = (h1 + b * s[i]) % MOD;
		h2 = (h2 + bb * s[i]) % MOD;

		b = (b * BASE1) % MOD;
		bb = (bb * BASE2) % MOD;
	}	
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;	while(n--){string s;	cin >> s;	process(s);}	while (m--){string t;	cin >> t;	if (found(t))	cout << "YES\n"; else	cout << "NO\n";}
	return	0;
}