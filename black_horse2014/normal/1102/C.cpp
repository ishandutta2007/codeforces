#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, y; cin >> n >> x >> y;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int z; cin >> z;
		if (z <= x) cnt++;
	}
	if (x <= y) {
		cout << (cnt + 1) / 2 << endl;
	} else {
		cout << n << endl;
	}
	return 0;
}