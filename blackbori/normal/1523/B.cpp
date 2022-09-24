#include <bits/stdc++.h>

using namespace std;

int A[10101];
int n;

void tc() {
	int i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
	}
	cout << n * 3 << "\n";
	for (i = 1; i <= n; i += 2) {
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "2 " << i << " " << i + 1 << "\n";
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "1 " << i << " " << i + 1 << "\n";
		cout << "2 " << i << " " << i + 1 << "\n";
		cout << "1 " << i << " " << i + 1 << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}