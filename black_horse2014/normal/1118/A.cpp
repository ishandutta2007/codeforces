#include <bits/stdc++.h>
using namespace std;

int main() {
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long n, a, b; cin >> n >> a >> b; b = min(b, 2 * a);
		cout << b * (n / 2) + a * (n & 1) << endl;
	}
	return 0;
}