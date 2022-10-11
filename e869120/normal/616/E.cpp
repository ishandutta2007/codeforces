#include<iostream>
#include<algorithm>
using namespace std;
long long n, m, sum, mod = 1000000007, maxn = (1LL << 60);
int main() {
	cin >> n >> m;
	for (long long i = 1; i <= 1000000; i++) {
		long long L = min(m, n / (i + 1)); maxn = min(maxn, L);
		long long R = min(m, n / i); if (R <= 0 || R - L == 0)continue;
		long long AVG = (n%R) + ((n%R) + i*((R - L - 1) % mod)); AVG %= mod;

		long long B = ((R - L) % mod)*AVG; B %= mod; if (B % 2 == 1)B += mod; B /= 2;
		sum += B % mod; sum %= mod;
	}
	if (m > n) { sum += ((m - n) % mod)*(n%mod); sum %= mod; }
	for (long long i = 1; i <= maxn; i++) { sum += (n%i); sum %= mod; }
	cout << sum << endl;
	return 0;
}