#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll n;	cin >> n;
	ll ans = 1;
	for (ll i = n; i > n - 5; i--)	ans *= i;
	for (ll i = 2; i <= 5; i++)	ans/=i;
	for (ll i = n; i > n - 5; i--)	ans *= i;
	cout << ans << "\n";
	return	0;
}