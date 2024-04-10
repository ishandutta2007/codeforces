//My spirit's sleeping somewhere cold..

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a = 0, b = 0;
	ll n;	cin >> n;	while (n--){ll x;	cin >> x; if (x == 1)	a++;	else	b++;}
	ll x = 1, y = 1;
	for (ll i = 2; i <= a; i++){
		ll temp = x;
		x = (x + (i - 1)*y) % MOD;
		y = temp;
	}
	for (ll i = a + 1; i <= a + b; i++)
		x = (x * i) % MOD;
	cout << x << "\n";
	return	0;
}