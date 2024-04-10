#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e3 + 10;
const ll MAX = 1e4 + 20;

ll n, vec[MAXN];
ll d[MAXN][MAX * 2];
ll ans;

int main(){
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];

	d[0][MAX] = 1;
	for (ll i = 0; i < n; i++){
		ans = (ans + d[i][vec[i]]) % MOD;
		ans = (ans + d[i][MAX + vec[i]]) % MOD;
		d[i + 1][MAX] = 1;

		for (ll j = 1; j < MAX * 2; j++){
			ll z;
			if (j < MAX)	
				z = -j;
			else
				z = j - MAX;
			
			ll t = z - vec[i];
			if (t < 0 && t > -MAX)
				d[i + 1][j] = (d[i + 1][j] + d[i][-t]) % MOD;
			else if (t >= 0 && t < MAX)
				d[i + 1][j] = (d[i + 1][j] + d[i][MAX + t]) % MOD;

			t = z + vec[i];
			if (t < 0 && t > -MAX)
				d[i + 1][j] = (d[i + 1][j] + d[i][-t]) % MOD;
			else if (t >= 0 && t < MAX)
				d[i + 1][j] = (d[i + 1][j] + d[i][MAX + t]) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}