#include <iostream>
using namespace std;

int main() {
	#define long long long
	int n;
	cin >> n;
	long ans, a, ma, mi;
	cin >> a;
	ma = a;
	mi = a;
	ans = 0;
	for (int i = 1; i < n; ++i) {
		cin >> a;
		if (a > ma) ++ans, ma = a;
		if (a < mi) ++ans, mi = a;
	}
	cout << ans;
	return 0;
}