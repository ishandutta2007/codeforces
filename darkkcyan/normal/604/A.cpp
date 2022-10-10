#include <iostream>

using namespace std;

const int MAX_N = 5;

const int s[] = {
	 500, 1000, 1500, 2000, 2500
};

int max (int a, int b) {
	return a > b ? a : b;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int m[MAX_N];
	int w[MAX_N];
	int hs, hu;

	int i, k;

	for (i = 0; i < MAX_N; ++i) {
		cin >> m[i];
	}

	for (i = 0; i < MAX_N; ++i) {
		cin >> w[i];
	}

	cin >> hs >> hu;

	int result = 0;

	for (i = 0; i < MAX_N; ++i) {
		result += max(
			(s[i] * 3) / 10,
			s[i] - (s[i] * m[i]) / 250 - 50 * w[i]
		);
		// cout << result << endl;
	}

	result += hs * 100 - hu * 50;

	cout << result;

	return 0;
}