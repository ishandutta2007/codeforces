#include<iostream>
#include<string>
using namespace std;
string S, T; long long hush[100009], power[100009], las[100009], dp[100009], mod = 1000000007, res = 0, sum = 0; bool used[100009];
long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 60; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}
long long Div(long long a, long long b, long long m) {
	long long C = (a*modpow(b, m - 2, m)) % m;
	return C;
}
int main() {
	cin >> S >> T;
	power[0] = 1; for (int i = 1; i <= 100008; i++) { power[i] = power[i - 1] * 28LL; power[i] %= mod; }
	for (int i = 0; i < S.size(); i++) { hush[i + 1] = hush[i] + 1LL * (S[i] - 'a')*power[i]; hush[i + 1] %= mod; }
	long long rets = 0; for (int i = 0; i < T.size(); i++) { rets += 1LL * (T[i] - 'a')*power[i]; rets %= mod; }
	for (int i = 0; i <= (int)S.size() - (int)T.size(); i++) {
		if (Div((hush[i + T.size()] - hush[i] + mod) % mod, power[i], mod) == rets)used[i + 1] = true;
	}
	las[0] = -1; for (int i = 1; i <= S.size(); i++) { if (used[i] == true)las[i] = i; else las[i] = las[i - 1]; }
	dp[0] = 1; int A = T.size() - 1;
	for (int i = 1; i <= S.size(); i++) {
		if (i < T.size() || las[i - A] == -1)continue;
		res += sum*(las[i - A] - las[i - A - 1]); res %= mod;
		long long G = 0;
		for (int j = las[i - A] - 1; j >= las[i - A - 1]; j--) {
			G++; sum += dp[j]; res += G*dp[j]; res %= mod; sum %= mod;
		}
		dp[i] = res;
	}
	long long ans = 0;
	for (int i = 1; i <= S.size(); i++)ans += dp[i]; ans %= mod;
	cout << ans << endl;
	return 0;
}