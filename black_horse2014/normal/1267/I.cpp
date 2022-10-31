#include <bits/stdc++.h>

#ifdef LOCAL
#include "E:\\Competitive-Programming\\Template\\Standard Template Codes\\debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; cin >> n;
		vector<int> a, b;
		for (int i = 1; i <= n / 2; i++) {
			a.push_back(i);
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			b.push_back(i);
		}
		vector<vector<int>> used(2 * n + 1, vector<int>(2 * n + 1, 0));
		auto query = [&](int u, int v) {
			if (!used[u][v]) {
				cout << "? " << u << ' ' << v << endl;
				cout.flush();
				string ret; cin >> ret;
				if (ret[0] == '>') {
					used[u][v] = 1;
				} else {
					used[u][v] = -1;
				}
			}
			if (used[u][v] > 0) {
				return v;
			} else {
				return u;
			}
		};
		for (int i = n + 1; i <= n + n; i++) {
			if (a.size() > b.size()) {
				swap(a, b);
			}
			a.push_back(i);
			int X = a[0];
			for (int j = 1; j < a.size(); j++) {
				X = query(X, a[j]);
			}
			int Y = b[0];
			for (int j = 1; j < b.size(); j++) {
				Y = query(Y, b[j]);
			}
			int Z = query(X, Y);
			if (Z == Y) {
				b.erase(find(b.begin(), b.end(), Z));
			} else {
				a.erase(find(a.begin(), a.end(), Z));
			}
		}
		cout << "!" << endl;
		cout.flush();
	}
	return 0;
}