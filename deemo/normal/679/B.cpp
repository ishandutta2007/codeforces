#include<iostream>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

map<ll, pair<ll, ll>>	mp;
ll vec[MAXN], sz;

pair<ll, ll> get(ll x){
	if (x == 0)	return {0, 0};
	if (x < 8)	return {x, x};
	if (mp.count(x))	return mp[x];
	int pos = upper_bound(vec, vec + sz, x) - vec;
	pos--;

	auto a = get(x - vec[pos]);
	a.first++, a.second += vec[pos];

	auto b = get(vec[pos] - 1);
	return mp[x] = max(a, b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m;	cin >> m;
	for (ll i = 1; i * i * i <= m; i++)
		vec[sz++] = i * i * i;
	auto ans = get(m);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}