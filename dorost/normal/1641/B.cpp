/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 502;

void solve() {
	int n;
	cin >> n;
	vector <int> a, ans;
	int sz = 0;
	vector <pair <int, int>> o;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	while (!a.empty()) {
//		for (auto x : a)
//			cout << x << ' ';
//		cout << '\n';
		int x = a[0];
		int in = -1;
		for (int i = 1; i < a.size(); i++) {
			if (a[i] == a[0]) {
				in = i;
				break;
			}
		}
		if (in == -1) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 1; i < in; i++) {
			o.push_back(make_pair(a[i], sz + in + i));
		}
		vector <int> b;
		for (int i = in - 1; i >= 1; i--) {
			b.push_back(a[i]);
		}
		for (int i = in + 1; i < a.size(); i++)
			b.push_back(a[i]);
		a = b;
		ans.push_back((in) * 2);
		sz += (in) * 2;
	}
	cout << o.size() << '\n';
	for (auto [x, y]: o) {
		cout << y << ' ' << x << '\n';
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}