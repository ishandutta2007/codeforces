#include <iostream>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	k = 5 - k;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		ans += a <= k;
	}
	ans /= 3;
	cout << ans;
	return 0;
}