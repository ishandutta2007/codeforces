#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		set <int> s;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			s.insert(x);
		}
		int m = 9 - (int)s.size();
		cout << 6 * (m * (m - 1)/2 + m) << '\n';
	}
	
	return 0;
}