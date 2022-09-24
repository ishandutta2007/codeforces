#include <bits/stdc++.h>

using namespace std;

void tc() {
	int c, d;
	cin >> c >> d;
	if ((c + d) & 1) {
		cout << "-1\n";
	}
	else if (c == 0 && d == 0) {
		cout << "0\n";
	}
	else if (c == d || c == -d) {
		cout << "1\n";
	}
	else cout << "2\n";
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