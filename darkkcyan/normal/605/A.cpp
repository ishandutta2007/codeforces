#include <iostream>

using namespace std;

int main (void) {
	ios_base::sync_with_stdio(0);

	int i, k, m;

	int n;
	cin >> n;
	int arr[n + 1];  // rule: always have extra space

	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int tempArr[n + 1] = {0};

	for (i = 0; i < n; ++i) {
		tempArr[arr[i]] = tempArr[arr[i] - 1] + 1;
	}

	int l = tempArr[0];
	for (i = 1; i < n + 1; ++i) {
		if (tempArr[i] > l) l = tempArr[i];
	}

	int result = n - l;

	cout << result;

	return 0;
}