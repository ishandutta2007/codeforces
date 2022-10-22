#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll l, r, ans;
ll mp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll get(ll x){
	if (x == 0)	return	mp[0];
	ll ret = 0;
	while (x){
		ll z = x % 10;
		ret += mp[z];
		x /= 10;
	}
	return	ret;
}

int main(){
	cin >> l >> r;
	for (ll i = l; i <= r; i++)
		ans += get(i);
	cout << ans << endl;
	return	0;
}