/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int s, l;
	cin >> s >> l;
	vector <pair <int, int>> v;
	for (int i = 1; i <= l; i++) {
		int x = i, num = 0;
		while (x) {
			if (x % 2) {
				v.push_back({1 << num, i});
				break;
			}
			num++;
			x /= 2;
		}
	}
	sort(v.begin(), v.end(), greater <pair <int, int>> ());
	vector <int> ans;
	for (auto [x, y] : v) {
		if (s >= x) {
			s -= x;
			ans.push_back(y);
		}
	}
	if (s != 0) {
		cout << -1;
	} else {
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
	}
}