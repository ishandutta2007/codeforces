#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

ll l, r;

int main(){
	cin >> l >> r;
	if (r - l + 1 < 3){
		cout << -1 << endl;
		return	0;
	}
	if (r - l + 1 > 3 && l % 2)	l++;

	if (l % 2 == 0){
		cout << l << " " << l + 1 << " " << l + 2 << "\n";
		return	0;
	}
	if (__gcd(l, l + 2) == 1)	cout << -1 << endl;
	else
		cout << l << " " << l + 1 << " " << l + 2 << "\n";
	return	0;
}