#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	int k; cin >> k;
	#define ii pair<int, int>
	ii a[12];
	for (int i = 0; i < 12; ++i) cin >> a[i].first, a[i].second = i;
	sort(a, a + 12);
	int ans;
	for (ans = 11; k > 0 and ans >= 0; --ans) {
		k -= a[ans].first;
	}
	ans = 11 - ans;
	cout << (k > 0 ? -1 : ans);
	return 0;
}