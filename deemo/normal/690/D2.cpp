#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 10;
const int MOD = 1e6 + 3;

int k, m;
ll ss[MAXN];

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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> m;
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = ss[i - 1] * ll(i) % MOD;
	ll ans = ss[k + m] * pw(ss[m] * ss[k] % MOD, MOD - 2) % MOD;
	cout << (ans + MOD - 1) % MOD<< endl;
	return 0;	
}