#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if ((b - a) % (d + c) == 0) cout << (b - a) / (d + c) << endl;
		else cout << -1 << endl;
	}
}