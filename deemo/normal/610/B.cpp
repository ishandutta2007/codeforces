#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin >> n;
	vector<ll>	vec(n);
	ll mini = 1e9;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		mini = min(mini, vec[i]);
	}

	ll ans = n * mini, ret = 0;
	vector<bool>	mark(n, 0);
	for (ll i = 0; i < n; i++){
		if (vec[i] != mini)	continue;
		ll j = (i + n - 1) % n, g = 0;
		while (vec[j] != mini)	j = (j + n - 1) % n, g++;
		ret = max(ret, g);
	}
	cout << ans + ret << endl;
	return 0;
}