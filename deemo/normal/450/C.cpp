#include<iostream>
#include<cassert>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll n, m, k, ans;

ll get(ll a, ll b){
	if (a <= 0 || b <= 0)	return	0;
	a = n / a;
	b = m / b;
	return	a * b;
}

int main(){
	cin >> n >> m >> k;
	if (k > n + m - 2){
		cout << -1 << endl;
		return	0;
	}
	k += 2;
	
	for (ll i = n; i;){
		ll r = i;
		ans = max(ans, get(r, k - r));
		for (ll j = 35; j >= 0; j--){
			if ((ll(1) << j) >= r)	continue;

			ll z = r - (ll(1) << j);
			if (n/z == n/ i)
				r = z;
		}
		i = r - 1;
	}

	for (ll i = m; i;){
		ll r = i;
		ans = max(ans, get(k - r, r));
		for (ll j = 35; j >= 0; j--){
			if ((ll(1) << j) >= r)	continue;

			ll z = r - (ll(1) << j);
			if (m/z == m/ i)
				r = z;
		}
		i = r - 1;
	}

	assert(ans);
	cout << ans << endl;
	return	0;
}