#include <bits/stdc++.h>

using namespace std;

void tc() {
	int n, a;
	cin >> n; a = 0;
	for (; n; n /= 10) {
		a = max(a, n % 10);
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}