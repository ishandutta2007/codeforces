#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		while (arr[i] <= arr[i - 1]) {
			++arr[i];
			++ans;
		}
	}
	cout << ans << "\n";

	return 0;
}