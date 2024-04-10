#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 50 + 2;
const ll MAXL = 20;

ll n, len;
ll c[1<<MAXL];
string s[MAXN];
ll d[MAXN][MAXN];
ld ans;

int main(){
	cout << fixed << setprecision(15);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> s[i];
	len = s[0].size();
	for (ll i = 0; i < n; i++)
		for (ll j = i + 1; j < n; j++){
			ll mask = 0;
			for (ll w = 0; w < len; w++)
				if (s[i][w] == s[j][w])	mask |= 1<<w;
			c[mask] |= 1LL<<j;
			c[mask] |= 1LL<<i;
		}

	for (ll i = (1<<len)-1; ~i; i--)
		for (ll j = 0; j < len; j++)
			if (((i >> j) & 1) == 0)
				c[i] |= c[i^(1<<j)];

	d[0][0] = 1;
	for (ll i = 1; i < MAXN; i++){
		d[i][i] = d[i][0] = 1;
		for (ll j = 1; j < i; j++)
			d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
	}

	for (ll i = (1<<len)-1; ~i; i--){
		ll t = __builtin_popcountll(i);
		ll cnt = __builtin_popcountll(c[i]);
		ans += ld(cnt)/ n * ld(1./d[len][t]);
	}
	
	cout << ans << "\n";
	return 0;
}