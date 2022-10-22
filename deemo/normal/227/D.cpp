#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n;
ll vec[MAXN];
ll p[MAXN];
ll ans[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec, vec + n, greater<ll>());
	for (ll i = n - 1; i >= 0; i--)
		p[i] = (p[i + 1] + vec[i]);
	
	for (ll i = 1; i < n; i++){
		ans[i] = p[1];
		ll s = i;
		for (ll j = i + 1; j < n; s *= i, j += s)
			ans[i] += p[j];
	}

	ll q;	cin >> q;
	while (q--){
		ll k;	cin >> k;
		k = min(k, n - 1);
		cout << ans[k] << " ";
	}
	cout << endl;
	return 0;
}