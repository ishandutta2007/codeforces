#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll n, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll sum = 0;
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> vec[i], sum += vec[i];	sort(vec, vec + n);
	ll z = sum/ n;
	if (sum % n == 0){
		ll ans = 0;
		for (ll i = 0; i < n; i++)	
			if (vec[i] > z)	ans += vec[i] - z;
		cout << ans << endl;
	}
	else{
		ll x = sum % n, ans = 0;
		x = n - x;
		for (ll i = 0; i < n; i++)
			if (i < x)	
				ans += abs(vec[i] - z);
			else
				ans += abs(vec[i] - (z + 1));
		cout << ans/2 << endl;
	}
	return	0;
}