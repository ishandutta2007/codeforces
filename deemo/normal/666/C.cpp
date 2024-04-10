//Too late..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 10;
const ll SQ = 300;

ll n;
string s;
ll ss[2 * MAXN], c[MAXN], p25[MAXN], zss[MAXN];
ll d[SQ + 2][MAXN];
bool seen[2 * MAXN];

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

ll cal(ll a, ll b){return (ss[a] * zss[b] % MOD * zss[a - b] % MOD);}

void proc(){
	if (seen[n] && n < SQ)	return;
	seen[n] = 1;
	if (n < SQ){
		d[n][0] = 1;
		for (ll i = 1; i < MAXN; i++)
			d[n][i] = (d[n][i - 1] * 26LL + p25[i] * cal(i+n-1, n-1)) % MOD;
	}
	else{
		c[0] = 1;
		for (ll i = 1; i < MAXN; i++)
			c[i] = (c[i - 1] * 26LL + p25[i] * cal(i+n-1, n-1)) % MOD;
	}
}

ll get(ll x){
	if (n < SQ)	return d[n][x];
	return c[x];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	p25[0] = 1;
	for (int i = 1; i < MAXN; i++)	p25[i] = (p25[i - 1] * 25LL) % MOD;
	zss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		zss[i] = (zss[i - 1] * pw(i, MOD - 2)) % MOD;

	ss[0] = 1;
	for (ll i = 1; i < 2 * MAXN; i++)
		ss[i] = (ss[i - 1] * i) % MOD;

	ll q;	cin >> q;
	cin >> s;	n = s.size();	proc();
	while (q--){
		ll type;	cin >> type;	
		if (type == 1){
			cin >> s, n = s.size();
			proc();
		}
		else{
			ll x;	cin >> x;
			if (n > x)
				cout << "0\n";
			else
				cout << get(x-n) << "\n";
		}
	}
	return 0;
}