#include<iostream>
using namespace std;
long long n, dp[90];
int main() {
	cin >> n; dp[0] = 1; dp[1] = 1; int ret = 0;
	for (int i = 2; i < 90; i++)dp[i] = dp[i - 1] + dp[i - 2];
	for (int i = 0; i < 90; i++) {
		if (n >= dp[i])ret = i;
	}
	cout << ret - 1 << endl;
	return 0;
}