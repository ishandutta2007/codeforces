#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
	ll n;
	cin >> n;
	n--;
	ll c = 1;
	while (n >= c * 5) {
		n -= c * 5;
		c *= 2;
	}
	n /= c;
	cout << names[n] << endl;
	return 0;
}