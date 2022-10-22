#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll a, b;	cin >> a >> b;
	ll c;	cin >> c;
	for (ll i = 0; i <= 1e4 + 2; i++)
		for (ll j = 0; j <= 1e4 + 2; j++)
			if (i * a + b * j == c){
				cout << "YES\n";
				return	0;
			}
	cout << "NO\n";
	return	0;
}