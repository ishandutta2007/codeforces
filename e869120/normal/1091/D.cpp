#include <iostream>
using namespace std;

long long N, sum, ret, mod = 998244353;

int main() {
	cin >> N; sum = N; ret = 1;
	for (long long i = 1; i <= N; i++) { sum *= i; sum %= mod; }
	for (long long i = N; i >= 2; i--) {
		ret *= i; ret %= mod; sum -= ret;
	}
	sum += mod * mod; sum %= mod;
	cout << sum << endl;
	return 0;
}