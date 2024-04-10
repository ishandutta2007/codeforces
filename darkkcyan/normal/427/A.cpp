#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int ans = 0; int p = 0;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		p += a;
		if (a > 0) continue;
		if (p < 0) ans += -p, p = 0;
	}
	cout << ans;
	return 0;
}