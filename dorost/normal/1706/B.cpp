/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
vector <int> v[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		v[i].clear();
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i].empty()) {
			cout << 0 << ' ';
			continue;
		}
		int cnt = 1;
		bool lst = (v[i][0] % 2);
		for (int j = 1; j < (int)v[i].size(); j++) 	{
			if ((v[i][j] % 2) != lst) {
				lst = (v[i][j] % 2);
				cnt++;
			}
		}
		cout << cnt << ' ';
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