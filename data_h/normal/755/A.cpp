#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n;

bool is_prime(long long x) {
	for (long long i = 2; i < x && i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; ; i++) {
		if (!is_prime(1LL * i * n + 1)) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}