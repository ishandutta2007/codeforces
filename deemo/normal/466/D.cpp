#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 2e3 + 10;

ll n, h, vec[MAXN];
ll d[MAXN][MAXN];

int main(){
	cin >> n >> h;
	for (ll i = 0; i < n; i++)	cin >> vec[i];

	d[0][0] = 1;
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j <= n; j++){
			if (vec[i - 1] == h - j)	d[i][j] = d[i - 1][j];
			if (vec[i - 1] == h - j - 1)	d[i][j] = (d[i][j] + d[i - 1][j]) % MOD;
			if (j && vec[i - 1] == h - j)	d[i][j] = (d[i][j] + d[i - 1][j - 1]) % MOD;
			if (vec[i - 1] == h - j - 1)	d[i][j] = (d[i][j] + (j + 1) * d[i - 1][j + 1]) % MOD;
			if (vec[i - 1] == h - j - 1)	d[i][j] = (d[i][j] + j * d[i - 1][j]) % MOD;
		}
	cout << d[n][0] << "\n";
	return	0;
}