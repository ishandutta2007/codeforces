#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 10;

ll n, x[MAXN], y[MAXN], sz;
pair<ll, pair<ll, ll>>	sec[MAXN * MAXN];
map<pair<ll, ll>, ll>	mp;

void add(ll a, ll b){
	if (x[a] != x[b]){
		if (x[a] > x[b])
			swap(a, b);
	}
	else{
		if (y[a] > y[b])
			swap(a, b);
	}

	ll dis = (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
	pair<ll, ll> tm = {y[a] - y[b], x[a] - x[b]};
	sec[sz++] = {dis, tm};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> x[i] >> y[i];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
			if (i < j)	add(i, j);
	sort(sec, sec + sz);
	ll cc = 0;
	for (ll i = 0; i < sz; ){
		ll j = i;
		while (j < sz && sec[j].first == sec[i].first)	j++;
		
		mp.clear();
		for (; i < j; i++)
			cc += mp[sec[i].second]++;
	}
	cout << cc/2 << "\n";
	return	0;
}