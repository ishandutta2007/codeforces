#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<vector<int>, int> H;
	for (int i = 0; i < 1 << 18; i++) {
		vector<int> b(n);
		for (int j = 0; j < n; j++) {
			b[j] = __builtin_popcount((a[j] >> 12) ^ i);
		}
		H[b] = i;
	}
	for (int i = 0; i < 1 << 12; i++) {
		vector<int> b(n);
		for (int j = 0; j < n; j++) {
			b[j] = __builtin_popcount((a[j] & ((1 << 12) - 1)) ^ i);
		}
		int st = *max_element(b.begin(), b.end());
		for (int add = 0; add <= 30 - st; add++) {
			vector<int> c(n);
			for (int j = 0; j < n; j++) {
				c[j] = st + add - b[j];
			}
			if (H.count(c)) {
				cout << ((H[c] << 12) | i) << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}