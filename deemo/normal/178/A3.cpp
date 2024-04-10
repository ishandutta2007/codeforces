#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll LOG = 17 + 3;

ll n, vec[MAXN], mark[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll x, t = i;	cin >> x;
		mark[i + 1] += x;
		for (ll j = LOG - 1; j >= 0; j--){
			if (t + (1 << j) >= n)	continue;
			t += 1 << j;
			mark[t + 1] += x;
		}
	}
	
	ll sum = 0;
	for (ll i = 1; i < n; i++){
		sum += mark[i];
		cout << sum << "\n";
	}
	return	0;
}