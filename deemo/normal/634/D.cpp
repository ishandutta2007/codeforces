#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<deque>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 20;

ll n, d, m;
pair<ll, ll>	vec[MAXN];
deque<pair<ll, ll>>	q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> d >> n >> m;	m++;
	vec[0] = {0, 0};
	for (ll i = 1; i < m; i++)
		cin >> vec[i].first >> vec[i].second;
	vec[m++] = {d, 1e7};
	sort(vec, vec + m);
	
	for (ll i = 0; i < m - 1; i++)
		if (vec[i + 1].first - vec[i].first > n){
			cout << "-1\n";
			return	0;
		}

	ll ans = 0;
	ll b = 0, cur = 0;
	for (ll i = 0; i < m - 1; i++){
		ll dif = vec[i + 1].first - vec[i].first;
		while (q.size() && q.back().second >= vec[i].second)	q.pop_back();
		q.push_back({-cur, vec[i].second});
		
		while (dif){
			ll z = min(dif, n - cur - q.front().first);
			ans += q.front().second * z;
			cur += z;
			dif -= z;
			if (n - cur - q.front().first == 0)	q.pop_front();
		}
	}
	cout << ans << "\n";
	return	0;
}