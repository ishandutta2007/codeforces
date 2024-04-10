#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int s = 0;
	int n; cin >> n;
	for (int i = 1, a; i <= n; ++i) cin >> a, s += (a & 1) * i;
	cout << min(s, n * (n + 1) / 2 - s);
	return 0;
}