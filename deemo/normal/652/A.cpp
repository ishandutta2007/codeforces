#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll h1, h2, a, b;	cin >> h1 >> h2 >> a >> b;
	ll dif = h2 - h1;
	dif -= 8LL * a;
	if (dif <= 0){
		cout << "0\n";
		return 0;
	}
	dif += 12LL * b;
	ll ans = 1;
	for (ll i = 0; i < 2e6; i++){
		dif -= 12LL * a;
		if (dif <= 0)	break;
		dif += 12LL * b;
		ans++;
	}
	if (dif > 0){
		cout << "-1\n";
		return 0;
	}
	cout << ans << "\n";
	return	0;
}