//I miss it..

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<functional>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, sz;
map<ll, ll>	mp;
vector<pair<ll, ll>>	vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll a, b;	cin >> a >> b;
		if (mp.count(a))	a = mp[a];
		else	a = mp[a] = sz++;
	
		vec[a].push_back({b, i + 1});
	}

	ll cn = 0;
	for (ll i = 0; i < sz; i++){
		sort(vec[i].begin(), vec[i].end(), greater<pair<ll, ll>>());
		ll sum = 0;
		for (ll j = 0; j < (ll)vec[i].size(); j++){
			sum += vec[i][j].first;
			sec[j + 1].push_back({sum, i});
		}
		cn = max(cn, (ll)vec[i].size());
	}

	ll maxi = 0, ind = 0, sind = -1;
	for (ll i = 1; i <= cn; i++){
		sort(sec[i].begin(), sec[i].end(), greater<pair<ll, ll>>());
		if (sec[i].size() > 1 && maxi < sec[i][0].first + sec[i][1].first){
			maxi = sec[i][0].first + sec[i][1].first;
			ind = sec[i][0].second;
			sind = sec[i][1].second;
		}
		
		if (i > 1){
			if (sec[i][0].second != sec[i - 1][0].second && maxi < sec[i][0].first + sec[i - 1][0].first){
				maxi = sec[i][0].first + sec[i - 1][0].first;
				ind = sec[i][0].second;
				sind = sec[i - 1][0].second;
			}
			if (sec[i - 1].size() > 1 && sec[i][0].second != sec[i - 1][1].second && maxi < sec[i][0].first + sec[i - 1][1].first){
				maxi = sec[i][0].first + sec[i - 1][1].first;
				ind = sec[i][0].second;
				sind = sec[i - 1][1].second;
			}
			if (sec[i].size() > 1 && sec[i][1].second != sec[i - 1][0].second && maxi < sec[i][1].first + sec[i - 1][0].first){
				maxi = sec[i][1].first + sec[i - 1][0].first;
				ind = sec[i][1].second;
				sind = sec[i - 1][0].second;
			}
		}
	}
	cout << maxi << "\n";
	ll x = min((ll)vec[ind].size(), (ll)vec[sind].size());
	cout << 2 * x + bool((ll)vec[ind].size() > x || (ll)vec[sind].size() > x) << "\n";
	if ((ll)vec[ind].size() < (ll)vec[sind].size())	swap(ind, sind);

	for (ll i = 0; i < 2 * x + bool(vec[ind].size() > x); i++){
		if (i % 2 == 0)
			cout << vec[ind][i/2].second << " ";
		else
			cout << vec[sind][i/2].second << " ";
	}
	cout << endl;
	return 0;
}