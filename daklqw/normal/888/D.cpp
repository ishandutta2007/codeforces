#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define int long long
int n, k;
signed main() {
	cin >> n >> k;
	int ans = 1;
	if (k == 4) {
		--k;
		ans += n * (n - 1) * (n - 2) * (n - 3) / 24 * 9;
	}
	if (k == 3) {
		--k;
		ans += n * (n - 1) * (n - 2) / 3;
	}
	if (k == 2) {
		ans += n * (n - 1) / 2;
		--k;
	}
	cout << ans << endl;
	return 0;
}