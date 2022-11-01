#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ll l,r,k;
	cin >> l >> r >> k;
	ll p = 1;
	int a = 0;
	while(p<=r) {
		if(p>=l) {cout << p << " ";++a;}
		ll prv = p;
		p *= k;
		if(p/k != prv) break;
	}
	if(a==0) cout << "-1";
	cout << "\n";
}