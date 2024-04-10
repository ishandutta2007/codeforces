#include <iostream>
using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	int ans = 0;
	for (int a, i = 0; i < n; ++i) cin >> a, ans += 1 + (a > h);
	cout << ans;
	return 0;
}