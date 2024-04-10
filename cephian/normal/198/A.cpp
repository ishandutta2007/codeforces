#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	ll k, b, n, t;
	cin >> k >> b >> n >> t;

	ll first = 1;
	int gone = 0;
	while (first <= t) {
		first = first * k + b;
		++gone;
	}
	cout << max(n - gone + 1, 0ll) << "\n";

	return 0;
}