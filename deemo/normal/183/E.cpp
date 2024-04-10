#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;

ll n, m, al[MAXN], sal[MAXN];

ll get(ll d){
	for (ll i = 0; i < n; i++)	sal[i] = min(al[i], d * (m * 2 - (d + 1) * n + (i + 1) * 2)/ 2LL);
	for (ll i = n - 2; i >= 0; i--)	sal[i] = min(sal[i], sal[i + 1] - d);
	for (int i = 0; i < n; i++)	if (sal[i] <= 0)	return 0;
	ll sm = d * (m * 2 - (d + 1) * n + 2)/ 2;
	ll s = m - d * n + 1 - (sm - sal[0]);
	s = max(s, 1LL);

	ll rem = (m - s + 1) - d * n;
	ll ret = sal[0];
	for (ll i = 1; i < n; i++){
		ll t = sal[i - 1] + d;
		ret += t;
		ll z = min(rem, sal[i] - t);
		ret += z;
		rem -= z;
		sal[i] = t + z;
	}
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;	for (ll i = 0; i < n; i++)	cin >> al[i];
	ll ans = 0;
	for (ll i = 1; i <= m/n; i++)
		ans = max(ans, get(i));
	cout << ans << "\n";
	return	0;
}