#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif 
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		int r1, c1, r2, c2, r3, c3, x, y;
		cin >> n >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> x >> y;
		for (int ix = 0; ix <= 1; ix++) {
			for (int iy = 0; iy <= 1; iy++) {
				if (ix) {
					r1 = n + 1 - r1;
					r2 = n + 1 - r2;
					r3 = n + 1 - r3;
					x = n + 1 - x;
				}
				if (iy) {
					c1 = n + 1 - c1;
					c2 = n + 1 - c2;
					c3 = n + 1 - c3;
					y = n + 1 - y;
				}
				
				{
					// solve
					set<pair<int, int>> shave;
					shave.insert({r1, c1});
					shave.insert({r2, c2});
					shave.insert({r3, c3});
					vector<pair<int, int>> have;
					for (auto &c : shave) {
						have.push_back(c);
					}
					bool ok = 1;
					
					
					ok &= (have[1].first == have[0].first);
					ok &= (have[1].second == have[0].second + 1);
					
					
					ok &= (have[2].first == have[0].first + 1);
					ok &= (have[2].second == have[0].second);
					
					if (ok) {
						if (have[0] == make_pair(1, 1)) {
							cout << ((x == 1 || y == 1) ? ("YES") : ("NO")) << "\n";
						} else {
							cout << ((y % 2 == have[0].second % 2 || x % 2 == have[0].first % 2) ? ("YES") : ("NO")) << "\n";
						}
					}
				}
				
				if (ix) {
					r1 = n + 1 - r1;
					r2 = n + 1 - r2;
					r3 = n + 1 - r3;
					x = n + 1 - x;
				}
				if (iy) {
					c1 = n + 1 - c1;
					c2 = n + 1 - c2;
					c3 = n + 1 - c3;
					y = n + 1 - y;
				}
			}
		
		}
	}
  return 0;
}