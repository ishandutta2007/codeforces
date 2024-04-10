#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;

ll n, k, req[MAXN], cur[MAXN];

bool ok(ll mid){
	ll tot = k;
	for (ll i = 0; tot >= 0 && i < n; i++)
		tot -= max(ll(0), req[i] * mid - cur[i]);
	return tot >= 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (ll i = 0; i < n; i++)	cin >> req[i];
	for (ll i = 0; i < n; i++)	cin >> cur[i];

	ll b = 0, e = 2e9, ret = 0;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (ok(mid))
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}	
	cout << ret << "\n";
	return 0;
}