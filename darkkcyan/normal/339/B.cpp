#include <iostream>
using namespace std;

#define long long long 
int main() {
	int n, m;
	cin >> n >> m;
	long a, ans;
	cin >> a;
	ans = a - 1;
	for (long b, i = 1; i < m; ++i) {
		cin >> b;
		if (b < a) ans += n - a + b;
		else ans += b - a;
		a = b;
	}
	cout << ans;
	return 0;
}