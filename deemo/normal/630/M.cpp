#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll x;	cin >> x;
	x %= 360LL;
	
	if (x < 0)	x += 360;
	ll mn = min(x, 360 - x);
	ll ans = 0;

	for (ll i = 1; i <= 4; i++){
		x -= 90;

		ll z = x >= 0?min(x, 360 - x):min(-x, 360 - (-x));
		if (z < mn){
			mn = z;
			ans = i;
		}
	}		
	cout << ans << "\n";
	return	0;
}