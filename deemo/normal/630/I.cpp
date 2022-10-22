#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll n;	cin >> n;
	ll ans = 0;
	for (ll i = 1; i + n <= 2 * n - 1; i++){
		ll t = 4;
		if (i == 1 || i + n == 2 * n - 1){
			t *= 3;
			for (ll j = n - 3; j; j--)
				t *= 4;
		}
		else{
			t *= 3;
			t *= 3;
			for (ll j = n - 4; j; j--)
				t *= 4;
		}
		ans += t;
	}
	cout << ans << "\n";
	return	0;
}