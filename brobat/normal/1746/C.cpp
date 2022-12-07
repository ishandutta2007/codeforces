#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector <int> ans(n);
		for(int i = 0; i < n; i++) {
			ans[v[i] - 1] = i + 1;
			if(ans[v[i] - 1] == n) ans[v[i] - 1]--;
		}
		for(int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
		cout << '\n';
		// vector <int> p = v;
		// for(int i = 0; i < n; i++) {
		// 	for(int j = ans[i]; j < n; j++) {
		// 		p[j] += i + 1;
		// 	}
		// }
		// for(int i = 0; i < n; i++) cout << p[i] << ' ';
		// cout << '\n';
		// for(int i = 1; i < n; i++) {
		// 	assert(p[i] >= p[i - 1]);
		// }
	}
	// int n = 6;
	// vector <int> p(n);
	// iota(p.begin(), p.end(), 1);
	// cout << 720 << '\n';
	// do {
	// 	cout << n << '\n';
	// 	for(auto i : p) cout << i << ' ';
	// 	cout << '\n';
	// } while(next_permutation(p.begin(), p.end()));
	
	return 0;
}