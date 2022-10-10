#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		bool found = false;
		for (int f = 0; f < t; ++f) {
			int g; cin >> g;
			found |= k > g;
		}
		if (found) ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); ++i) cout << ans[i] << ' ';
	return 0;
}