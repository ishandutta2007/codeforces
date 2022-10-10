#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (void) {
	ios_base::sync_with_stdio(false);

	int i, k;

	int n, m;
	cin >> n >> m;
	vector <int> arr(n);

	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int result = 0;
	for (i = n - 1; m > 0; --i, ++result) {
		m -= arr[i];
	}

	cout << result;

	return 0;
}