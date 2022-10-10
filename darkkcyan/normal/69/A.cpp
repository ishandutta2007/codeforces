#include <iostream>
using namespace std;

int main() {
	int n;
	int a, b, c;
	a = b = c = 0;
	cin >> n;
	while (n -- ) {
		int x, y, z; cin >> x >> y >> z;
		a += x; b += y; c += z;
	}
	
	cout << (!a and !b and !c ? "YES":"NO");
	return 0;
}