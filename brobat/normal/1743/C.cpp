#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector <int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int st = -1;
		vector<pair<int, int>> r;
		for(int i = 0; i < n; i++) {
			if(st == -1) {
				if(s[i] == '1') {
					st = (i == 0 ? i : i - 1);
				}
			}
			else {
				if(s[i] == '0') {
					r.push_back({st, i - 1});
					st = -1;
				}
			}
		}
		if(st != -1) r.push_back({st, n - 1});
		// for(auto i : r) cout << i.first << "," << i.second << " ";
		// cout << '\n';
		int ans = 0;
		for(auto i : r) {
			vector <int> t;
			for(int j = i.first; j <= i.second; j++) {
				t.push_back(v[j]);
			}
			sort(t.begin(), t.end());
			for(int j = 1; j < (int)t.size(); j++) {
				ans += t[j];
			}
			if(i.first == 0 && s[0] == '1') ans += t[0];
		}
		cout << ans << '\n';
	}
	
	return 0;
}