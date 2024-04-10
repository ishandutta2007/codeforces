#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
	for (int i = 1; i <= n; ++i) {
		for (int f = 1; f <= n; ++f) {
			char ch; cin >> ws >> ch;
			a[i][f] = ch == 'o';
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int f = 1; f <= n; ++f) {
			if ((a[i - 1][f] + a[i + 1][f] + a[i][f - 1] + a[i][f + 1]) & 1) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}