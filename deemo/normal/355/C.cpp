#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, l, r, a, b, vec[MAXN], p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> r >> a >> b;
	for (ll i = 0; i < n; i++)
		cin >> vec[i], p[i + 1] = p[i] + vec[i];
	
	ll ans = 1e18;
	for (ll i = 0; i <= n; i++){
		ll ret = l * p[i] + r * (p[n] - p[i]);
		
		if (i > (n - i))
			ret += a * max(0LL, (i - (n - i)) - 1);
		else
			ret += b * max(0LL, ((n - i) - i) - 1);

		ans = min(ans, ret);
	}
	cout << ans << "\n";
	return	0;	
}