#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

const ll MAXN = 60 + 5;

ll n, k;
ll vec[MAXN];
vector<ll>	ans;

int main(){
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec, vec + n, greater<ll>());
	
	ll mask = 0;
	for (ll i = 0; i < n; i++){
		for (ll j = i; j < n; j++)
			ans.push_back(mask ^ (ll(1) << j));
		mask ^= ll(1) << i;
	}

	for (ll i = 0; i < k; i++){
		mask = ans[i];
		ll ret = 0;
		for (ll j = 0; j < n; j++)
			if ((mask >> j) & 1)	ret++;
		cout << ret << " ";
		for (ll j = 0; j < n; j++)
			if ((mask >> j) & 1)	cout << vec[j] << " ";
		cout << endl;
	}	
	return 0;
}