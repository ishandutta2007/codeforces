#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 20;
const int LIMIT = 18;

int n;
long long g[N], a;

int f(int x) {
	if (x == 0) {
		return 0;
	} else {
		return x % 10 + f(x / 10);
	}
}

long long mul(long long c, int d) {
	long long res = 0;
	for(int i = 0; i < d; i++) {
		(res += c) %= a;
	}
	return res % a;
}

int main() {
	cin >> a;
	long long l = 1LL, r = 1LL;
	for(int i = 1; i <= LIMIT; i++) {
		r *= 10;
	}
	long long cur = 1, power = 1;
	for(int i = 1; i < LIMIT; i++) {
		power = mul(power, 10);
	}
	int digit = 45;
	power = mul(power, digit);
	power = mul(power, LIMIT);
	(++power) %= a;
	//cout << power << endl;
	if (power == 0) {
		cout << l << " " << r << endl;
	} else {
		cout << l + a - power << " " << r + a - power << endl;
	}
	return 0;
}