#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; string s; cin >> n >> s;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i + 1]) {
			cout << "YES\n";
			cout << i + 1 << ' ' << i + 2 << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}