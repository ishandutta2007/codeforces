#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e3 + 10;

ll n;
pair<ll, ll>	x[MAXN];
set<pair<ll, ll>>	st;

int main(){
	cin >> n;	
	ll mx = 0, xx = 0;
	for (ll i = 0; i < n; i++){
		cin >> x[i].first >> x[i].second;
		swap(x[i].first, x[i].second);
		mx = max(mx, max(x[i].first, x[i].second));
		xx = max(xx, min(x[i].first, x[i].second));
	}

	ll ans = 1e18 + 2;
	for (ll i = xx; i <= mx; i++){
		ll ret = 0, rem = n/2;	st.clear();

		for (ll j = 0; rem >= 0 && j < n; j++){
			if (x[j].first > i){
				rem--;
				ret += i * x[j].first;
			}
			else if (x[j].first >= x[j].second)
				ret += i * x[j].second;
			else if (x[j].second > i)
				ret += i * x[j].second;
			else
				st.insert({x[j].first - x[j].second, j});
		}
		if (rem < 0)	continue;

		for (auto it:st){
			if (rem)
				ret += i * x[it.second].first, rem--;
			else
				ret += i * x[it.second].second;
		}

		ans = min(ans, ret);
	}
	cout << ans << "\n";
	return	0;
}