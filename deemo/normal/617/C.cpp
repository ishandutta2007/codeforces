#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 20;

ll n, x, y, xx, yy;
pair<ll, ll>	vec[MAXN];
ll ans = 1e18 + 2;
bool mark[MAXN];

ll get(ll a, ll b, ll c, ll d){
	ll ret = (a - c) * (a - c);
	ret += (b - d) * (b - d);
	return	ret;
}

int main(){
	cin >> n >> x >> y >> xx >> yy;
	ll maxi = 0;
	for (ll i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		maxi = max(maxi, get(xx, yy, vec[i].first, vec[i].second));
	}
	ans = maxi;

	for (ll i = 0; i < n; i++){
		ll dis = get(x, y, vec[i].first, vec[i].second);
		memset(mark, 0, sizeof(mark));
		for (ll j = 0; j < n; j++)
			if (get(x, y, vec[j].first, vec[j].second) <= dis)	mark[j] = 1;
		
		ll maxi = 0;
		for (ll j = 0; j < n; j++)
			if (!mark[j])
				maxi = max(maxi, get(xx, yy, vec[j].first, vec[j].second));
		ans = min(ans, maxi + dis);
	}
	cout << ans << endl;
	return	0;
}