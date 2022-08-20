#include <iostream>
#define ll long long
#define F0R(i, a) for (int i=0; i<a; i++)

using namespace std;

int main() {
	ll n;
	cin >> n;
	string x = to_string(n);
	string y = x;
	y[1] = x[2];
	y[2] = x[4];
	y[4] = x[1];
	ll value = (ll)(atoi(y.c_str()));
	ll v = value;
	F0R(i,4) {
		value *= v;
		value %= 100000;
	}
	string value1 = to_string(value);
	F0R(i,5-value1.length()) cout << '0';
	cout << value1;
	return 0;
}