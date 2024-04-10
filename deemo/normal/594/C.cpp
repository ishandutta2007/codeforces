#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 4;
const ll INF = 4e18 + 4;

ll n, k, vec[MAXN];
ll tx[MAXN], ty[MAXN];
vector<ll>	lx, ly;
vector<ll>	secx, secxx, secy, secyy;

bool cmpx(ll a, ll b){
	if (tx[a] != tx[b])
		return	tx[a] < tx[b];
	return	ty[a] < ty[b];
}

ll get(ll x, ll y, ll xx, ll yy){
	if (xx < x || yy < y)	return	INF;

	ll cnt = 0;
	cnt += lower_bound(lx.begin(), lx.end(), x) - lx.begin();
	cnt += lx.end() - upper_bound(lx.begin(), lx.end(), xx);
	cnt += lower_bound(ly.begin(), ly.end(), y) - ly.begin();
	cnt += ly.end() - upper_bound(ly.begin(), ly.end(), yy);
	
	for (ll i = 0; i < n && i < k + 2; i++)
		if (tx[vec[i]] < x && (ty[vec[i]] < y || ty[vec[i]] > yy))	cnt--;
	
	for (ll i = n - 1; i >= n - k - 2 && i >= 0; i--)
		if (tx[vec[i]] > xx && (ty[vec[i]] < y || ty[vec[i]] > yy))	cnt--;
	if (cnt > k)	return	INF;

	xx -= x;
	yy -= y;
	
	xx = xx / 2 + bool(xx % 2 == 1);
	yy = yy / 2 + bool(yy % 2 == 1);

	if (xx * yy == 0)	return	INF;
	return	xx * yy;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cout << endl;
	for (ll i = 0; i < n; i++){
		ll x, y, xx, yy;	cin >> x >> y >> xx >> yy;
		tx[i] = x + xx;
		ty[i] = y + yy;

		lx.push_back(tx[i]);
		ly.push_back(ty[i]);
	}
	sort(lx.begin(), lx.end());
	sort(ly.begin(), ly.end());

	for (ll i = 0; i < n && i < k + 2; i++)	secx.push_back(lx[i]), secx.push_back(lx[i] - 1), secx.push_back(lx[i] + 1);
	for (ll i = n - 1; i >= 0 && i >= n - k - 2; i--)	secxx.push_back(lx[i]), secxx.push_back(lx[i] - 1), secxx.push_back(lx[i] + 1);
	sort(secx.begin(), secx.end());
	sort(secxx.begin(), secxx.end());
	secx.resize(unique(secx.begin(), secx.end()) - secx.begin());
	secxx.resize(unique(secxx.begin(), secxx.end()) - secxx.begin());

	for (ll i = 0; i < n && i < k + 2; i++)	secy.push_back(ly[i]), secy.push_back(ly[i] - 1), secy.push_back(ly[i] + 1);
	for (ll i = n - 1; i >= 0 && i >= n - k - 2; i--)	secyy.push_back(ly[i]), secyy.push_back(ly[i] - 1), secyy.push_back(ly[i] + 1);
	sort(secy.begin(), secy.end());
	sort(secyy.begin(), secyy.end());
	secy.resize(unique(secy.begin(), secy.end()) - secy.begin());
	secyy.resize(unique(secyy.begin(), secyy.end()) - secyy.begin());

	iota(vec, vec + n, 0);
	sort(vec, vec + n, cmpx);
	ll ans = INF;
	for (ll i = 0; i < (ll)secx.size(); i++)
		for (ll j = 0; j < (ll)secxx.size(); j++)
			for (ll w = 0; w < (ll)secy.size(); w++)
				for (ll q = 0; q < (ll)secyy.size(); q++)
					ans = min(ans, get(secx[i], secy[w], secxx[j], secyy[q]));
	cout << ans << "\n";
	return	0;
}