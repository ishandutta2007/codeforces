#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	bool has1 = false;
	for (int a, i = 0; i < n; ++i) cin >> a, has1 |= a == 1;
	if (has1) cout << -1;
	else cout << 1;
	return 0;
}