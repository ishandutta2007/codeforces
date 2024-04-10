#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int ans = 0;
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		int k = 0x7fffffff;
		for(int j = 0; j < m; ++j) {
			int t;
			cin >> t;
			k = min(k,t);
		}
		ans = max(ans, k);
	}
	cout << ans << "\n";
	return 0;
}