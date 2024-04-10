#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int a, p;
	cin >> a >> p;
	int ans = a * p;
	int minp = p;
	for (int i = 1; i < n; ++i) {
		cin >> a >> p;
		if (p < minp) minp = p;
		ans += minp * a;
	}
	cout << ans;
	return 0;
}