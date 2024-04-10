#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 9;

ll n, m, k;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)	ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;
}

int main(){
	cin >> n >> m >> k;
	ll t = (n / k) * (k - 1);
	t += n % k;
	if (t >= m){
		cout << m << endl;
		return 0;
	}
	ll y = m - t;
	ll z = (k * (pw(2, y + 1) + MOD - 2)) % MOD; 
	m -= y * k;
	z = (z + m) % MOD;
	cout << z << endl;
	return 0;
}