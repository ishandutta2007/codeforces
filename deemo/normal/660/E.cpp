#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, m;
ll d[MAXN];

int main(){
	cin >> n >> m;
	d[1] = 1;
	ll y = m;
	for (ll i = 2; i <= n; i++){
		d[i] = (d[i - 1] * m) % MOD;
		d[i] = (d[i] + y) % MOD;
		d[i] = (d[i] + d[i - 1] * (m - 1)) % MOD;
		y = (y * m) % MOD;
	}
	cout << (m * d[n] + y) % MOD << "\n";
	return	0;
}