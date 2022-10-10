#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int ans = 0;
	vector<int>::iterator t = max_element(arr.begin(), arr.end());
	while (t != arr.begin()) swap(*t, *(t - 1)), --t, ++ans;
	vector<int>::reverse_iterator v = min_element(arr.rbegin(), arr.rend());
	while (v != arr.rbegin()) swap(*v, *(v + 1)), --v, ++ans;
	cout << ans;
	return 0;
}