#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int q;
		cin >> q;
		vector <int> s(26, 0);
		vector <int> t(26, 0);
		s[0]++; t[0]++;
		int st = 0;
		int tt = 0;
		for(int i = 0; i < q; i++) {
			int d, k;
			cin >> d >> k;
			string zz;
			cin >> zz;
			vector <int> a(26, 0);
			for(auto i : zz) {
				a[i - 'a'] += k;
			}
			if(d == 1) {
				for(int i = 0; i < 26; i++) {
					s[i] += a[i];
					st += a[i];
				}
			} else {
				for(int i = 0; i < 26; i++) {
					t[i] += a[i];
					tt += a[i];
				}
			}
			vector<pair<char, int>> x, y;
			for(int i = 0; i < 26; i++) {
				if(s[i] > 0) {
					x.push_back({i, s[i]});
				}
				if((int)x.size() == 2) break;
			}
			for(int i = 25; i >= 0; i--) {
				if(t[i] > 0) {
					y.push_back({i, t[i]});
				}
				if((int)y.size() == 2) break;
			}
			// cout << (x < y ? "YES" : "NO") << '\n';
			bool pos = false;
			if(x.empty()) pos = true;
			else if(!y.empty()) {
				if(x.front().first < y.front().first) {
					pos = true;
				} else if(x.front().first == y.front().first) {
					if(x.front().second > y.front().second) {

					} else if(x.front().second == y.front().second) {
						if((int)x.size() == 1 && (int)y.size() == 2) {
							pos = true;
						}
					} else {
						if((int)x.size() == 1) pos = true;
					}
				}
			}
			cout << (pos ? "YES" : "NO") << '\n';
		}
	}
	
	return 0;
}