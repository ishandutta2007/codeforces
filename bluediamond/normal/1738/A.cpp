#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
int main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		vector<vector<ll>> ve(2);
		ll sum = 0, sol;
		int n;
		cin >> n;
		vector<int> tp(n);
		for (int i = 0; i < n; i++) cin >> tp[i];
		for (int i = 0; i < n; i++) {
			int l;
			cin >> l;
			sum += l;
			ve[tp[i]].push_back(l);
		}
		sol = sum;
		for (int f = 0; f <= 1; f++) {
			vector<vector<ll>> v = ve;
			if (f) {
				swap(v[0], v[1]);
			}
			sort(v[0].begin(), v[0].end());
			sort(v[1].begin(), v[1].end());
			if (v[0].empty() || v[1].empty()) continue;
			ll cur = 0;
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					// from 1
					if ((int) v[1].size() == 0) break;
					cur += v[1].back();
					v[1].pop_back();
				} else {
					if ((int) v[0].size() == 1) break;
					cur += v[0].back();
					v[0].pop_back();
				}
			}
			sol = max(sol, sum + cur);
		}
		cout << sol << "\n";
		
	}
	
	return 0;
}