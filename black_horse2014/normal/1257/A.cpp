#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, x, a, b; cin >> n >> x >> a >> b;
		cout << min(n - 1, abs(b - a) + x) << '\n';
	}
	return 0;
}