#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	cout << "0 0" << endl;
	for (int i = 0; i < n - 1; i++) {
		int D = (i / 4) + 1;
		if (i % 4 == 0) cout << D << " " << 0 << endl;
		if (i % 4 == 1) cout << 0 << " " << D << endl;
		if (i % 4 == 2) cout << -D << " " << 0 << endl;
		if (i % 4 == 3) cout << 0 << " " << -D << endl;
	}
	return 0;
}