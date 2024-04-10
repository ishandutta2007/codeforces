#include <bits/stdc++.h>
using namespace std;

bool flag[1000010] = {1, 1};
int dp[1000010];

void sieve() {
	for (int j = 2; j <= 1000; j++)
		if (!flag[j]) {
			for (int k = j * j; k <= 1000000; k += j)
				flag[k] = 1;
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	sieve();
	for (int i = 1; i <= 1000000; i++)
		dp[i] = dp[i - 1] + !flag[i];
	int tcase;
	cin >> tcase;
	while (tcase--) {
		int n;
		cin >> n;
		int root = sqrt(n + 0.1);
		cout << dp[n] - dp[root] + 1 << "\n";
	}
	return 0;
}