#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << a + abs(b - d) << " " << b << " " << c + abs(b - d) << " " << d;
	} else if (b == d) {
		cout << a << " " << b + abs(c - a) << " " << c << " " << d + abs(c - a);
	} else {
		if (abs(b - d) != abs(c - a)) {
			cout << "-1";
		} else {
			cout << c << " " << b << " " << a << " " << d;
		}
	}
	cout << "\n";

	return 0;
}