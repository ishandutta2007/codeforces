#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAX = 1e5 + 40;

ll n;
string a, b;
ll d1[MAX], d2[MAX], ans[MAX], t[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	
	d1[0] = d2[0] = ans[0] = 0;
	t[0] = 1;
	for (ll i = 0; i < n; i++){
		ll f = 0, g = 0, e = 0;
		for (ll j = 0; j < 10; j++)
			for (ll w = 0; w < 10; w++){
				if (a[i] != '?' && j != a[i] - '0')	continue;
				if (b[i] != '?' && w != b[i] - '0')	continue;
	
				if (j > w)	f++;
				if (w > j)	g++;
				if (j == w)	e++;
			}
		
		t[i + 1] = (t[i] * (e + f + g)) % MOD;

		d1[i + 1] = (d1[i] * (e + g)) % MOD;
		d1[i + 1] = (d1[i + 1] + f * t[i]) % MOD;

		d2[i + 1] = (d2[i] * (e + f)) % MOD;
		d2[i + 1] = (d2[i + 1] + g * t[i]) % MOD;
		
		ans[i + 1] = (ans[i] * e) % MOD;
		ans[i + 1] = (ans[i + 1] + f * d2[i]) % MOD;
		ans[i + 1] = (ans[i + 1] + g * d1[i]) % MOD;
	}
	cout << ans[n] << endl;
	return 0;
}