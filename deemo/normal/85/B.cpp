#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<cassert>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll INF = 1e18 + 4;

ll n, k[4], t[4];
ll vec[MAXN];
deque<pair<ll, ll>>	q[4], sec[4];
ll ft[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 0; i < 3; i++)	cin >> k[i];
	for (ll i = 0; i < 3; i++)	cin >> t[i];
	cin >> n;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		sec[0].push_back({vec[i], i});
	}

	ll cur = 0, b = 0, cnt = 0;
	while (cnt < n){
		for (ll j = 0; j < 3; j++)
			while (q[j].size() && q[j][0].first + t[j] == cur){
				if (j == 2)
					cnt++, ft[q[j].front().second] = cur;
				else
					sec[j + 1].push_back({cur, q[j].front().second});
				q[j].pop_front();
			}				

		for (ll j = 0; j < 3; j++)
			while ((ll)q[j].size() < k[j] && sec[j].size() && sec[j][0].first <= cur){
				q[j].push_back({cur, sec[j].front().second});
				sec[j].pop_front();
			}	

		ll mini = INF;
		for (ll j = 0; j < 3; j++)
			if (q[j].size())
				mini = min(mini, q[j][0].first + t[j] - cur);
		for (ll j = 0; j < 3; j++)
			if ((int)sec[j].size() && sec[j][0].first > cur)
				mini = min(mini, sec[j][0].first - cur);
		assert(mini != INF || cnt == n);
		cur += mini;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		ans = max(ans, ft[i] - vec[i]);
	cout << ans << endl;
	return 0;
}