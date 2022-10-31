#include <bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k, long long a, long long b) {
	if (n == 1) return 0;
	if (k == 1 || n < k) return (n - 1) * a;
	return min(solve(n / k, k, a, b) + (n % k) * a + b, (n - 1) * a);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	long long n, k, a, b; cin >> n >> k >> a >> b;
	cout << solve(n, k, a, b) << endl;
	return 0;
}