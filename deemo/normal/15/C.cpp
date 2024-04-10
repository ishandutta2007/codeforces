//It reminds me that it's not so bad, It's not so bad..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll get(ll z){
	ll ret = 0;
	ll s = 2;
	for (ll i = 1; i < 60; i++, s <<= 1){
		ll t = z/s;
		ll temp = t/2 * s;
		if (t % 2)
			temp += (z % s) + 1;
		if (temp % 2 == 1)
			ret ^= ll(1) << ll(i);
	}
	z = z/2 + bool(z % 2 == 1);
	if (z % 2 == 1)
		ret++;
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	ll ans = 0;
	while (n--){
		ll a, b;	cin >> a >> b;
		ans ^= get(a + b - 1);
		ans ^= get(a - 1);
	}
	if (ans == 0)
		cout << "bolik\n";
	else
		cout << "tolik\n";
	return 0;
}