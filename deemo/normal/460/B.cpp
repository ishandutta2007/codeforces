#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll a, b, c;
vector<ll>	ans;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b--)
		ret *= a;
	return	ret;
}

ll get(ll x){
	ll sum = 0, tx = x;
	while (tx){
		sum += tx % 10;
		tx /= 10;
	}
	return	b * pw(sum, a) + c;
}

int main(){
	cin >> a >> b >> c;
	for (ll i = 1; i < 90; i++){
		ll x = b * pw(i, a) + c;
		if (x >= 1e9)	continue;
		if (x == 0)	continue;
		if (get(x) == x)	ans.push_back(x);
	}
	cout << ans.size() << endl;
	for (ll v:ans)
		cout << v << " ";
	cout << endl;
	return	0;
}