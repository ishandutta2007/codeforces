#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];

	map<int, int> left;
	int i = 0, j = 0;
	while (j < n) {
		if (i == n || a[i] != b[j]) {
			if (left[b[j]] > 0 && j > 0 && b[j - 1] == b[j]) {
				// pull from store
				--left[b[j]];
				++j;
			} else if (i < n) {
				// store/skip i
				++left[a[i]];
				++i;
			} else {
				return false;
			}
		} else {
			// match without move
			++i, ++j;
		}
	}
	return i == n && j == n;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}