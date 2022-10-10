#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) cin >> arr[i];
 
	int ans = 1;
	int cur = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i] >= arr[i - 1]) ++ cur;
		else cur = 1;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}