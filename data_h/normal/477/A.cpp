#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int a, b;
long long divv;
const int MOD = 1e9 + 7;

long long power(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	a %= MOD;
	if (b == 1) {
		return a;
	}
	long long temp = power(a, b >> 1);
	if (b & 1) {
		return temp * temp % MOD * a % MOD;
	} else {
		return temp * temp % MOD;
	}
}

inline long long sum(int r) {
	r %= MOD;
	return 1LL * (1 + r) * r % MOD * divv % MOD;
}

int main() {
	divv = power(2, MOD - 2);
	long long answer = 0;
	scanf("%d %d", &a, &b);
	long long temp = 1LL * (1 + a) * a / 2 % MOD * b % MOD + a;
	temp %= MOD;
	temp *= sum(b - 1);
	cout << temp % MOD << endl;
	return 0;
}