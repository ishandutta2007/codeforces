#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

ll n, m;

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return	ret;
}

int main(){
	cin >> n >> m;
	ll ans = pw(3, n);
	ans = (ans + m - 1) % m;
	cout << ans << endl;
	return 0;
}