#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long solve(long long n) {
	long long lis = (n - 1LL) / 3LL;
	long long a = 0, b = 0, c = 0;

	// a 
	for (int i = 0; i < 30; i++) {
		long long cl = (1LL << (2 * i));
		long long cr = 2LL * cl - 1LL;
		if (lis >= (cr - cl + 1LL)) { lis -= (cr - cl + 1LL); }
		else {
			a = cl + lis;
			break;
		}
	}

	// b 
	for (int i = 0; i < 30; i++) {
		long long v = (a / (1LL << (2 * i))) % 4LL;
		if (v == 0) b += 0LL * (1LL << (2 * i));
		if (v == 1) b += 2LL * (1LL << (2 * i));
		if (v == 2) b += 3LL * (1LL << (2 * i));
		if (v == 3) b += 1LL * (1LL << (2 * i));
	}
	
	// c 
	c = (a ^ b);

	// 
	if ((n - 1LL) % 3LL == 0) return a;
	if ((n - 1LL) % 3LL == 1) return b;
	if ((n - 1LL) % 3LL == 2) return c;
	return -1LL;
}

int main() {
	long long T, N;
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld", &N);
		printf("%lld\n", solve(N));
	}
	return 0;
}