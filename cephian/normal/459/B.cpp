#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int min = 0x7fffffff;
	ll min_m = 0;
	int max = -1;
	ll max_m = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == min)
			++min_m;
		else if (a < min) {
			min = a;
			min_m = 1;
		}

		if (a == max)
			++max_m;
		else if (a > max) {
			max = a;
			max_m = 1;
		}
	}

	cout << max - min << " ";
	if (min == max) {
		cout << (min_m * (min_m - 1)) / 2 << "\n";
	} else {
		cout << min_m * max_m << "\n";
	}

	return 0;
}