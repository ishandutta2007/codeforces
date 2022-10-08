#include <bits/stdc++.h>

using namespace std;

// n <= 10^{14}
map<int64_t, int> dp;

int64_t calc(int64_t n);

//  1,  ,    n, 
int64_t go(int64_t n) { 
	if (dp.count(n))
		return dp[n];
	return dp[n] = calc(n);
}

int64_t calc(int64_t n) { 
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 1)
		return 1;
	for (int64_t i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if ((i & 1) && go(n / i) == 0)
				return 1;
			if (((n / i) & 1) && go(i) == 0)
				return 1;
		}
	}
	return 0;
}

// int fib(int n) {
// 	if (dp.count(n))
// 		return dp[n];
// 	if (n <= 1)
// 		return 1;
// 	return dp[n] = fib(n - 1) + fib(n - 2);
// }

void solve() {
	int64_t n;
	cin >> n;
	puts(go(n) ? "Ashishgup" : "FastestFinger");
}

int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}