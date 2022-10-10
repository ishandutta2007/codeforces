#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int n, m;
	cin >> m >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0];
	for (int i = 0; i < n - m + 1; ++i) {
		ans = min(ans, arr[i + m - 1] - arr[i]);
	}
	cout << ans;
 
	return 0;
}