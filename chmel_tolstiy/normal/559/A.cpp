#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a(6);
	for (int i = 0; i < 6; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	do {
		int x = a[0] + a[3] + a[1];
		bool ok = true;
		ok &= a[0] + a[3] + a[1] == x;
		ok &= a[1] + a[4] + a[2] == x;
		ok &= a[2] + a[5] + a[0] == x;

		if (ok) {
			cout << x * x - a[0] * a[0] - a[1] * a[1] - a[2] * a[2] << endl;
			return 0;
		}

	} while (next_permutation(a.begin(), a.end()));
	return 0;
}