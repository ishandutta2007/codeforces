#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[3];

int main() {
	ios::sync_with_stdio(0);
	cin >> a[0] >> a[1] >> a[2];
	ll k = min(a[0],min(a[1],a[2]));
	a[0] -= k;
	a[1] -= k;
	a[2] -= k;
	if(!a[0] && !a[1] && !a[2]) {
		cout << "0\n";
		return 0;
	}
	if(a[0] && !a[1] && !a[2]) {
		cout << 2*a[0]-2 << "\n";
		return 0;
	}
	if(!a[0] && a[1] && !a[2]) {
		cout << 2*a[1]-2 << "\n";
		return 0;
	}
	if(!a[0] && !a[1] && a[2]) {
		cout << 2*a[2]-2 << "\n";
		return 0;
	}
	if(!a[0]) {
		if(a[1] == a[2])
			cout << a[1]-1 << "\n";
		else if(a[1] > a[2])
			cout << 2*a[1]-a[2]-2 << "\n";
		else
			cout << 2*a[2]-a[1]-2 << "\n";
		return 0;
	}
	if(!a[1]) {
		if(a[0] == a[2])
			cout << a[0]-1 << "\n";
		else if(a[0] > a[2])
			cout << 2*a[0]-a[2]-2 << "\n";
		else
			cout << 2*a[2]-a[0]-2 << "\n";
		return 0;
	}
	if(!a[2]) {
		if(a[0] == a[1])
			cout << a[0]-1 << "\n";
		else if(a[0] > a[1])
			cout << 2*a[0]-a[1]-2 << "\n";
		else
			cout << 2*a[1]-a[0]-2 << "\n";
		return 0;
	}
	return 0;
}