#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

ll p[4] = {2, 3, 5, 7};

int main(){
	ll n, ans = 0;	cin >> n;
	for (ll i = 1; i < (1<<4); i++){
		ll t = 1;
		for (ll j = 0; j < 4; j++)
			if ((i >> j) & 1)	t *= p[j];
		
		ll sz = __builtin_popcount(i);
		if (sz % 2)
			ans += n/t;
		else
			ans -= n/t;
	}
	cout << n - ans << "\n";
	return	0;
}