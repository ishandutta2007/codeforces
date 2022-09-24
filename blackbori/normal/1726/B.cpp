#include <bits/stdc++.h>

using namespace std;

void tc() {
	int n, m, i;
	cin >> m >> n;
	if (n < m) {
		cout << "No\n";
	}
	else if (m == 1) {
		cout << "Yes\n";
		cout << n << "\n";
	}
	else if (m == 2) {
		if (n & 1) cout << "No\n";
		else cout << "Yes\n" << (n / 2) << " " << (n / 2) << "\n";
	}
	else if (m & 1) {
		cout << "Yes\n";
		for (i = 1; i < m; i++) cout << "1 ";
		cout << n - m + 1 << "\n";
	}
	else {
		if (n & 1) cout << "No\n";
		else {
			cout << "Yes\n";
			for (i = 1; i < m - 1; i++) cout << "1 ";
			cout << (n - m) / 2 + 1 << " " << (n - m) / 2 + 1 << "\n";
		}
	}
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