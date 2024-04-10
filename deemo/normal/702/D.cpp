#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 3e18;

ll d, k, a, b, t;

ll get(ll ret){
	if (ret * k > d)	return INF;
	ll ans = 0;
	ll td = d;
	ans = ret * (t + k * a);
	d -= ret * k;
	ll g = min(d, k);
	ans += g * a;
	d -= g;
	
	ans += d * b;
	d = td;
	return ans;
}

int main(){
	cin >> d >> k >> a >> b >> t;
	ll lo = -1, hi = ll(1e12) + 1, ret = 1e12;
	while (hi - lo > 1){
		ll mid = lo + hi >> 1;
		if (get(mid) > get(mid + 1))
			lo = mid;
		else
			hi = mid;
	}
	ret = lo + 1;
	
	cout << get(ret) << endl;
	return 0;
}