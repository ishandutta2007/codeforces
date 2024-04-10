#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
long long a, b, c, ret, mod = 998244353;
long long modpow(long long a, long long b, long long m) {
	long long p = 1, q = a;
	for (int i = 0; i < 63; i++) {
		if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}
long long Div(long long a, long long b, long long m) {
	return (a*modpow(b, m - 2, m)) % m;
}
long long solve(long long a, long long b) {
	if (a < b)swap(a, b);
	long long ret = 1, fac = 1, divs = 1;
	for (int i = 1; i <= b; i++) {
		divs *= i; fac *= 1LL * (a + 1 - i)*(b + 1 - i); divs %= mod; fac %= mod;
		ret += Div(fac, divs, mod); ret %= mod;
	}
	return ret;
}
int main() {
	cin >> a >> b >> c;
	cout << (((solve(a, b)*solve(b, c)) % mod)*solve(c, a)) % mod << endl;
	return 0;
}