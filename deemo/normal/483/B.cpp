#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll c1, c2, xx, yy;

bool ok(ll x){
	ll a = x - x/xx;
	ll b = x - x/yy;

	ll c = x - x/xx - x/yy + x/(xx * yy);
	a -= c;	b -= c;

	ll g = max(0LL, c1 - a);
	a += min(g, c);
	c -= min(g, c);
	if (a < c1)	return	false;

	b += c;
	if (b < c2)	return	false;
	return	true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c1 >> c2 >> xx >> yy;

	ll b = 1, e = 1e18, ret = 1e18;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (ok(mid)){
			ret = mid;
			e = mid - 1;
		}
		else	b = mid + 1;
	}
	cout << ret << "\n";
	return	0;
}