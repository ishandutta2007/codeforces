#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (1e9)+7;
 
pair<ll, ll> query(ll x, ll y, ll k, ll lim) {
	if(x <= 0 || y <= 0 || k < 0 || lim <= 0) return {0, 0};
	ll pw = 1 << k;
	ll cnt = 0, sum = 0;
	if(x >= pw || y >= pw) {
		ll val_cnt = min(pw, lim), node_cnt = min(pw, min(x, y));
		cnt = val_cnt * node_cnt % MOD;
		sum = (val_cnt * (val_cnt + 1) / 2 % MOD) * node_cnt % MOD;
	} else {
		pw >>= 1;
		pair<ll, ll> res[2][2] = {
			query(x, y, k-1, lim),
			query(x - pw, y, k-1, lim - pw),
			query(x, y - pw, k-1, lim - pw),
			query(x - pw, y - pw, k-1, lim)
		};
		cnt = (res[0][0].second + res[0][1].second + res[1][0].second + res[1][1].second) % MOD;
		sum = (res[0][0].first + res[0][1].first + res[1][0].first + res[1][1].first) % MOD; 
		sum = (sum + (res[0][1].second + res[1][0].second) * pw) % MOD;
	}
	assert(sum >= 0 && cnt >= 0);
	return {sum, cnt};
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while(q--) {
		ll x1, y1, x2, y2, lim;
		cin >> x1 >> y1 >> x2 >> y2 >> lim;
		ll k = 0;
		while(1ll << k <= max(x2, y2)) ++k;
		ll res = query(x2, y2, k, lim).first
					 - query(x1 - 1, y2, k, lim).first
					 - query(x2, y1 - 1, k, lim).first
					 + query(x1 - 1, y1 - 1, k, lim).first;
		res %= MOD;
		cout << (res + MOD) % MOD << '\n';
	}
}