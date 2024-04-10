#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long n, x; cin >> n >> x;
		printf("%lld\n", x + (n - 1) * 9);
	}
	return 0;
}