#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll n, vec[200];
ll ans = 1;
vector<ll>	sec;

int main(){
	bool fl = 0;
	cin >> n;	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		if (vec[i]){
			fl = 1;
			sec.push_back(i);
		}
	}
	if (fl == 0){
		cout << 0 << endl;
		return	0;
	}

	for (ll i = 1; i < sec.size(); i++)
		ans *= (sec[i] - sec[i - 1]);
	cout << ans << endl;
	return	0;	
}