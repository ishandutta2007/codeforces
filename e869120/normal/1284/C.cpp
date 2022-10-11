#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, M;
long long fact[1 << 19];

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 300000; i++) fact[i] = (1LL * i * fact[i - 1]) % M;
}

long long product(vector<long long> a) {
	long long t = 1;
	for (int i = 0; i < a.size(); i++) { t *= a[i]; t %= M; }
	return t;
}

int main() {
	cin >> N >> M;
	init();

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		long long v1 = N + 1 - i;
		long long v2 = fact[N - i];
		long long v3 = fact[i];
		sum += product({ v1, v1, v2, v3 });
		sum %= M;
	}
	cout << sum << endl;
	return 0;
}