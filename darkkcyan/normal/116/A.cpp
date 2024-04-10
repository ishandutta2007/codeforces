#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	int cur = 0;
	while (n --) {
		int a, b;
		cin >> a >> b;
		cur += b - a;
		ans = max(cur, ans);
	}
	cout << ans;
	return 0;
}