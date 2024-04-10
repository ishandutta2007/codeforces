#include<iostream>

using namespace std;

typedef long long ll;

int main(){
	ll x, k;	cin >> x >> k;
	ll z = x/2;
	if (x % 2 == 1)	z++;

	if (k <= z){
		cout << ll(2) * (k-1) + 1 << endl;
		return 0;
	}
	k -= z;
	cout << k * 2 << endl;
	return 0;
}