#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string S; long long a, b, ret, fact[500000], inv[500000], factinv[500000], mod = 1000000007;
long long ncr(int n, int r) {
	return (n - r >= 0 && r >= 0) ? 1LL * fact[n] * factinv[r] % mod * factinv[n - r] % mod : 0;
}
int main() {
	cin >> S;
	fact[0] = 1;
	for (int i = 1; i < 500000; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
	inv[1] = 1;
	for (int i = 2; i < 500000; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
	factinv[0] = 1;
	for (int i = 1; i < 500000; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
	for (int i = 0; i < S.size(); i++) { if (S[i] == ')')b++; }
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == ')')b--;
		if (S[i] == '(') {
			ret += (ncr(a + b + 1, b) - ncr(a + b, b) + mod) % mod; ret %= mod;
			a++;
		}
	}
	cout << ret << endl;
	return 0;
}