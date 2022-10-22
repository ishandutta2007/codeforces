#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll n;
vector<ll>	vec, sec;
ll sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	for (ll i = 0; i < n; i++){
		ll x;	cin >> x;
		if (x % 2 == 1)
			vec.push_back(x);
		sum += x;
	}
	if (vec.size() % 2 == 1){
		sort(vec.begin(), vec.end());
		sum -= vec[0];
	}	
	cout << sum << endl;
	return	0;
}