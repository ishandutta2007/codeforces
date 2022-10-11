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

int main() {
	long long T, N, R;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> R;
		long long base = min(R, N - 1);
		long long sum = base * (base + 1LL) / 2LL;
		if (N <= R) sum += 1;
		cout << sum << endl;
	}
	return 0;
}