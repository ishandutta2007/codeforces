#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		vector <int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector <int> mx;
		mx.push_back(0);
		map<int, int> ans;
		ans[0] = 0;
		int prev = 0;
		for(int i = 0; i < n; i++) {
			mx.push_back(max(mx.back(), v[i]));
			prev += v[i];
			ans[mx.back()] = prev;
		}
		for(int i = 0; i < q; i++) {
			int k;
			cin >> k;
			int x = *(--upper_bound(mx.begin(), mx.end(), k));
			cout << ans[x] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}