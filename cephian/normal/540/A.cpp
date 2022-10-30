#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	string a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i])
			swap(a[i], b[i]);
		ans += min(b[i] - a[i], a[i] + 10 - b[i]);
	}
	cout << ans << "\n";

	return 0;
}