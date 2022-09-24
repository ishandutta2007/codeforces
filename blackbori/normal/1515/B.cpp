#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void tc() {
	ll n, t, k;
	cin >> n;

	if (n % 4 == 0) {
		t = n / 4;
		k = int(sqrtl(t));
		if (k * k == t || (k + 1) * (k + 1) == t) {
			cout << "YES\n";
			return;
		}
	}

	if (n % 2 == 0) {
		t = n / 2;
		k = int(sqrtl(t));
		if (k * k == t || (k + 1) * (k + 1) == t) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}