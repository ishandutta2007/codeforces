#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<string>

using namespace std;

typedef long long ll;

const ll MAXN = 100;

ll ans;
ll n, m;
string s, t;
ll d[3][1<<9][9], c[3][1<<9][9];

string get(ll x){
	if (x == 0)	return "0";
	string ret;
	while (x){
		ret = char(x % 7 + '0') + ret;
		x /= 7;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;	n--, m--;
	s = get(n), t = get(m);
	if (s.size() + t.size() > 7){
		cout << "0\n";
		return 0;
	}
	ll z = s[0] - '0';
	d[1][1<<z][1] = 1;
	while (--z >= 0)
		d[0][1<<z][1] = 1;

	ll sz = s.size();
	for (ll i = 1; i < sz; i++){
		z = s[i] - '0';
		for (ll ms = 0; ms < (1<<7); ms++)
			for (ll w = 0; w < 7; w++)
				if (((ms >> w) & 1) == 0){
					if (z == w)
						d[1][ms | (1<<w)][i + 1] += d[1][ms][i];
					if (z > w)
						d[0][ms | (1<<w)][i + 1] += d[1][ms][i];

					d[0][ms | (1<<w)][i + 1] += d[0][ms][i];
				}
	}

	z = t[0] - '0';
	c[1][1<<z][1] = 1;
	while (--z >= 0)
		c[0][1<<z][1] = 1;

	sz = t.size();
	for (ll i = 1; i < sz; i++){
		z = t[i] - '0';
		for (ll ms = 0; ms < (1<<7); ms++)
			for (ll w = 0; w < 7; w++)
				if (((ms >> w) & 1) == 0){
					if (z == w)
						c[1][ms | (1<<w)][i + 1] += c[1][ms][i];
					if (z > w)
						c[0][ms | (1<<w)][i + 1] += c[1][ms][i];

					c[0][ms | (1<<w)][i + 1] += c[0][ms][i];
				}
	}

	ll sz1 = s.size(), sz2 = t.size();
	for (ll i = 1; i < (1<<7); i++)
		for (ll j = 1; j < (1<<7); j++)
			if ((i|j) == (i^j)){
				for (ll aa = 0; aa <= 1; aa++)
					for (ll bb = 0; bb <= 1; bb++)
						ans += d[aa][i][sz1] * c[bb][j][sz2];
			}
	cout << ans << endl;
	return 0;
}