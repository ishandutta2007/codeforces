#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int mod(int a, int m) {
	while (a < 0)
		a += m;
	return a % m;
}

int main() {
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	ll ans = 0;
	int prev = 0;
	for (int i = 0; i < m; ++i) {
		int hs;
		cin >> hs;
		--hs;
		if (hs < prev)
			ans += hs + n - prev;
		else
			ans += hs - prev;
		prev = hs;
	}
	cout << ans << "\n";
	return 0;
}