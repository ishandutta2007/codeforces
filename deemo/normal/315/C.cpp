#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAX = 2e5 + 20;

ll a[MAX];
vector<ll>	ans;

int main(){
	ll n, k, rmv = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	
	ll sum = 0;
	for (ll i = 0; i < n; i++){
		ll x = ll(i - rmv) * a[i] * (n - i - 1);
		x = -x;
		x += sum;
		if (x < k){
			ans.push_back(i + 1);
			rmv++;
		}
		else	sum += (i - rmv) * a[i];
	}
	
	for (ll v:ans)
		cout << v << "\n";
	return 0;
}