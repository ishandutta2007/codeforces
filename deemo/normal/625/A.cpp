#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll n, a, b, c;	cin >> n >> a >> b >> c;
	ll ans = 0;
	ll z = b - c;
	if (a < z){
		cout << n/a << "\n";
		return	0;
	}

	if (n < b){
		cout << n/a << "\n";
		return	0;
	}

	ll y = n - b;
	ans = y / z;
	y %= z;
	n = b + y;

	ans++, n -= z;
	ans += n/a;
	cout << ans << "\n";
	return	0;
}