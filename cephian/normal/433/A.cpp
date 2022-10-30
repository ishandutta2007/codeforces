#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		int apl;
		cin >> apl;
		if (apl == 100)
			++a;
		else
			++b;
	}
	int f1 = 0, f2 = 0;
	while (b != 0) {
		if (f1 < f2) {
			f1 += 2;
		} else {
			f2 += 2;
		}
		--b;
	}

	while (a != 0) {
		if (f1 < f2) {
			f1 += 1;
		} else {
			f2 += 1;
		}
		--a;
	}

	if (f1 == f2)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}