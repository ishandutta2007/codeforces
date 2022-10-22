#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAX = 1e5 + 10;

ll a[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, q;	cin >> n >> q;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll add = 0;
	while (q--){
		ll type;	cin >> type;
		if (type == 3){
			ll v;	cin >> v;	v--;
			cout << a[v] + add << "\n";
			continue;
		}
		if (type == 2){
			ll x;	cin >> x;	
			add += x;
			continue;
		}
		ll v, x;	cin >> v >> x;	v--;
		a[v] = x - add;
	}
	return 0;
}