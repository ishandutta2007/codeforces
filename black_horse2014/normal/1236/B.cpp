#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

int fast_exponentiation(int a, int n) {
	int ret = 1;
	for (; n; n >>= 1, a = a * 1LL * a % P) {
		if (n & 1) {
			ret = ret * 1LL * a % P;
		}
	}
	return ret;
}

int main() {
	int n, m; cin >> n >> m;
	cout << fast_exponentiation((fast_exponentiation(2, m) + P - 1) % P, n) << endl;
	return 0;
}