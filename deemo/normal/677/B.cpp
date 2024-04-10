#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, h, k, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h >> k;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	ll ans = 0, sm = 0;
	for (ll i = 0; i < n; i++){
		ll z = sm - (h - vec[i]);
		if (z > 0){
			ll cnt = z/k;
			if (z % k)	cnt++;
			sm -= cnt * k;
			sm = max(sm, 0LL);
			ans += cnt;
		}
		sm += vec[i];
	}
	ans += sm/k;
	if (sm % k)	ans++;
	cout << ans << endl;
	return 0;
}