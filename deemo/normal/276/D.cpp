#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll l, r;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> l >> r;
	if (l == r){
		cout << 0 << endl;
		return 0;
	}
	
	int i;
	for (i = 60; i >= 0; i--){
		if (((r >> i) & 1) ^ ((l >> i) & 1))	break;
		r ^= ll(1) << ll(i);
		l ^= ll(1) << ll(i);
	}
	ll ans = ll(1) << (i);
	ll z = (ll(1) << (i)) - 1;
	ans += z;
	cout << ans << endl;
	return 0;
}