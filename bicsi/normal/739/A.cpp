#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int ans = 1e9;
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		ans = min(ans, b - a + 1);
	}

	cout << ans << endl;
	for(int i = 0; i < n; ++i) {
		cout << i % ans << " ";
	}
	cout << endl;

	return 0;
}