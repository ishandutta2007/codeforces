#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5;
const ll MOD = 1e9;

ll n, q, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++)	cin >> vec[i];

	while (q--){
		ll type;	cin >> type;
		if (type == 1){
			ll x, val;	cin >> x >> val;	x--;
			vec[x] = val;
		}
		else{
			ll l, r;	cin >> l >> r;	l--;
			ll ans = 0;
			ll aa = 1, bb = 1;
			for (ll i = l; i < r; i++){
				ans += vec[i] * aa;
				ll tmp = bb;
				bb += aa;
				aa = tmp;

				aa %= MOD;
				bb %= MOD;
				ans %= MOD;
			}
			cout << ans << "\n";
		}
	}
	return	0;
}