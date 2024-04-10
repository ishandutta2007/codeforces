#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	int power[n];
	for (int i = 0; i < n; ++i)
		cin >> power[i];

	int min_num = 0x7fffffff;
	int min_ind = -1;
	for (int i = 0; i < k; ++i) {
		int tmp = 0;
		for (int j = 0; j * k + i < n; ++j) {
			tmp += power[j * k + i];
		}
		if (tmp < min_num) {
			min_num = tmp;
			min_ind = i;
		}
	}

	cout << min_ind + 1 << "\n";

	return 0;
}