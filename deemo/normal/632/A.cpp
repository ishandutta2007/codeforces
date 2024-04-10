#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

ll n, p;
ll ans;
bool mark[50];

int main(){
	cin >> n >> p;
	for (ll i = 0; i < n; i++){
		string temp;	cin >> temp;
		if (temp == "half")
			mark[i] = 0;
		else
			mark[i] = 1;
	}
	ll cur = 0;
	for (ll i = n - 1; i >= 0; i--){
		if (mark[i])
			ans += cur * p + p/2, cur = cur * 2 + 1;
		else
			ans += cur * p, cur *= 2;
	}
	cout << ans << "\n";
	return	0;
}