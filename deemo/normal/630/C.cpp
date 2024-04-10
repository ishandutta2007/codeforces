#include<iostream>

using namespace std;

typedef long long ll;

int main(){
	ll n;	cin >> n;
	ll ans = 0, t = 1;
	for (int i = 1; i <= n; i++){
		t <<= 1LL;
		ans += t;
	}
	cout << ans << "\n";
	return	0;
}