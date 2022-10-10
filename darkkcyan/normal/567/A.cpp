#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n;
	cin >> n;
	#define ii pair<int, int>
	ii arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	ii ans[n];
	for (int i = 1; i < n - 1; ++i) {
		int p = arr[i].second;
		ans[p].first = min(arr[i].first - arr[i - 1].first, arr[i + 1].first - arr[i].first);
		ans[p].second = max(arr[i].first - arr[0].first, arr[n - 1].first - arr[i].first);
	}
	ans[arr[0].second].first = arr[1].first - arr[0].first;
	ans[arr[n - 1].second].first = arr[n - 1].first - arr[n - 2].first;
	ans[arr[0].second].second = ans[arr[n - 1].second].second = arr[n - 1].first - arr[0].first;
	for (int i = 0; i < n; ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}