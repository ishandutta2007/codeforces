#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long fib[1 << 19], mod = 1000000007;
long long H, W;

int main() {
	cin >> H >> W;
	fib[0] = 1; fib[1] = 1;
	for (int i = 2; i <= 100000; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	
	long long v = fib[H] + fib[W] - 1;
	cout << 2LL * (v + mod) % mod << endl;
	return 0;
}