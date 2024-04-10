#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	ll n;	cin >> n;
	ll cnt = 0;

	ll i;
	for (i = 1; cnt < n; i++){
		ll j = i;
		cnt++;
		while (j % 5 == 0){
			j /= 5;
			cnt++;
		}
	}
	i--;
	if (cnt != n){
		cout << "0\n";
		return	0;
	}
	cout << 5 << "\n";
	for (ll j = i * 5; j < i * 5 + 5; j++)
		cout << j << " ";
	cout << "\n";
	return	0;
}