#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	pair<int, int> arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	int i = 0;
	while (i < n && k >= arr[i].first) {
		k -= arr[i].first;
		++i;
	}
	cout << i << "\n";
	for (int j = 0; j < i; ++j) {
		cout << arr[j].second + 1;
		if (j != i - 1)
			cout << " ";
	}
	cout << "\n";
	return 0;
}