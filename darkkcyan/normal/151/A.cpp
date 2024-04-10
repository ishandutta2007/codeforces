#include <iostream>
using namespace std;

#define ll long long 

int main() {
	ll n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	nl *= n;
	np *= n;
	l *= k;
	d *= c;
	cout << min(min(l / nl, p / np), d / n);
	return 0;
}