#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, P, minx = (1LL << 60);

int main() {
	cin >> N >> P;
	for (int i = 1; i <= 100000; i++) {
		long long E = 1LL * N - 1LL * i * P;
		if (E < i) continue;

		long long cnt = 0;
		for (int j = 0; j < 40; j++) {
			if ((E / (1LL << j)) % 2 == 1) cnt++;
		}
		if (cnt <= i) minx = min(minx, 1LL * i);
	}
	if (minx == (1LL << 60)) minx = -1;
	cout << minx << endl;
	return 0;
}