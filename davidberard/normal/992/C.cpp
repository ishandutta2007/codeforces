#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;

ll tpow(ll amt) {
	ll curr = 2;
	ll ans = 1;
	for(ll i=0;i<63;++i) {
		if(amt & (1LL<<i)) {
			ans = (ans * curr)%MOD;
		}
		curr = (curr*curr)%MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	ll x, k;
	cin >> x >> k;
	if(x == 0) {
		cout << 0 << endl;
		return 0;
	}
	x = x%MOD;
	if(k < 3) {
		x = (2*x)%MOD;
		for(int i=0;i<k;++i) {
			//cerr << "x = " << x << endl;
			x = (x*2-1+MOD)%MOD;
		}
		//cerr << "!! " << endl;
		cout << x << endl;
		return 0;
	}
	ll p = tpow(k+1);
	ll ph = tpow(k);
	//cerr << " 2 ^ " << k << " = " << p << endl;
	ll ans = ((p*x))%MOD;
	//cerr << " Subtracting " << ph-1 << " from " << ans << endl;
	ans = (ans - ph+1+MOD)%MOD;
	cout << ans << endl;

	return 0;
}