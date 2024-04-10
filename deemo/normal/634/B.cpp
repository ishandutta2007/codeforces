#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll s, x, z;
	cin >> s >> x;	z = s;
	ll ans = 1;
	for (ll i = 45; i >= 0; i--)
		if ((x >> i) & 1){
			z -= (1LL << i);
			ans *= 2;
		}
	if (z % 2 == 1){
		cout << "0\n";
		return	0;	
	}
	z /= 2;
	for (ll i = 45; i >= 0; i--)
		if (((x >> i) & 1) && ((z >> i) & 1)){
			cout << "0\n";
			return	0;
		}
	if (z == 0)	ans -= 2;
	cout << ans << "\n";
	return	0;
}