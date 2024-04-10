#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;

ll sum = 0;
ll n, m, a[MAXN];
vector<ll>	vec;

int main(){
	cin >> n >> m;
	for (ll i = 0; i < n; i++)	cin >> a[i], sum += a[i];
	while (m--){
		ll x;	cin >> x;	x--;
		vec.push_back(a[x]);
		sum -= a[x];
	}
	ll ss = sum;
	sort(vec.begin(), vec.end());
	ss += vec.back();
	for (ll j = 0; j < (ll)vec.size() - 1; j++)
		ss *= 2LL;	

	ll i = 0;
	for (; i < (ll)vec.size(); i++){
		if (sum < vec[i])	break;
		sum *= 2LL;
	}
	
	if (i != (ll)vec.size()){
		sum += vec.back();
		for (; i < (ll)vec.size() - 1; i++)
			sum *= 2LL;
	}
	cout << max(sum, ss) << "\n";
	return	0;
}