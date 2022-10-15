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
		int n;
		cin >> n;
		vector<int> last(n), type(n, -1);
		for (int i = 0; i < n; i++) {
			cin >> last[i];
			last[i]--;
		}
		int k = -1;
		for (int i = 0; i < n; i++) {
			k += (last[i] > i);
		}
		cout << k + 1 << "\n";
		vector<vector<int>> who(n);
		vector<int> beg;
		for (int i = 0; i < n; i++) {
			if (0 <= last[i] && last[i] < n) {
				who[last[i]].push_back(i);
			} else {
				beg.push_back(i);
			}
		}
		vector<int> sol;
		while (1) {
			int x = -1;
			for (auto &i : beg) {
				if (!who[i].empty()) {
					x = i;
				}
			}
			if (x == -1) {
				for (auto &j : beg) {
					sol.push_back(j);
				}
				break;
			}
			for (auto &j : beg) {
				if (j != x) {
					sol.push_back(j);
				}
			}
			sol.push_back(x);
			beg = who[x];
		}
		for (auto &x : sol) {
			cout << x + 1 << " ";
		}
		cout << "\n";		
	}
	
	return 0;
}