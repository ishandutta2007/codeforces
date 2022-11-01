#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 111111;
const int MOD = 1e9 + 7;

int n, k;
char digit[N];
long long fac[N], inv[N];
long long para[N], sum[N];

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	} else {
		long long t = power(a, b >> 1);
		if (b & 1) {
			return t * t % MOD * a % MOD;
		} else {
			return t * t % MOD;
		}
	}
}

long long C(int n, int m) {
	if (m < 0 || m > n) {
		return 0;
	}
	return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", digit + 1);
	/*n = 100000, k = 0;
	for(int i = 1; i <= n; i++) {
		digit[i] = '9';
	}*/
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = inv[i - 1] * power(i, MOD - 2) % MOD;
		sum[i] = (sum[i - 1] + digit[i] - '0') % MOD;
	}

	long long base = 1, answer = 0;
	for(int i = 1; i <= n; i++) {
		para[i] = C(n - i - 1, k - 1) * base % MOD;
		answer += sum[n - i] * para[i] % MOD;
		answer %= MOD;
		answer += (digit[n - i + 1] - '0') * C(n - i, k) % MOD * base % MOD;
		answer %= MOD;
		//cout << answer << endl;
		base = base * 10 % MOD;
	}
	cout << answer << endl;
	return 0;
}