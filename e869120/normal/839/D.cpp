#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long n, a[200009], c[1000009], power[1000009], dp[1000009], mod = 1000000007;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 1; j*j <= a[i]; j++) {
			if (a[i] % j == 0) {
				c[j]++; if ((a[i] / j) != j)c[a[i] / j]++;
			}
		}
	}
	power[0] = 1; for (int i = 1; i <= 1000008; i++) { power[i] = power[i - 1] * 2; power[i] %= mod; }
	for (long long i = 1000000; i >= 1; i--) {
		if (c[i] == 0)continue;
		long long U = 0;
		for (int j = 2 * i; j <= 1000000; j += i)U -= dp[j];
		U += 1LL * power[c[i] - 1] * c[i];
		dp[i] = U; dp[i] += 1LL * mod*mod; dp[i] %= mod;
	}
	long long ret = 0;
	for (long long i = 1000000; i >= 2; i--) { ret += dp[i] * i; ret %= mod; }
	cout << ret << endl;
	return 0;
}