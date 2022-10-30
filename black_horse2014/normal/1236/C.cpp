#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (~j & 1) cout << j * n + i + 1 << ' ';
			else cout << j * n + n - i << ' ';
		}
		cout << "\n";
	}
	return 0;
}