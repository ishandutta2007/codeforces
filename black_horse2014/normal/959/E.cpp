#include <bits/stdc++.h>
using namespace std;

long long f(long long n, long long p) {
	if (n == 1) return 0;
	return n / 2 * p + f((n + 1) / 2, p * 2);
}

int main() {
	ios::sync_with_stdio(0);
	long long n; cin >> n;
	cout << f(n, 1) << endl;
	return 0;
}