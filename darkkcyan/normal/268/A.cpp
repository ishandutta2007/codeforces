#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int f = 0; f < n; ++f) {
			ans += a[f] == b[i];
		}
	}
	cout << ans;
	return 0;
}