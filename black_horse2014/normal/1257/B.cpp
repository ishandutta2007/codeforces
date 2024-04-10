#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			cout << (b == 1 ? "YES" : "NO") << "\n";
		} else if (a >= 4) {
			cout << "YES\n";
		} else {
			cout << (b < 4 ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}