/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	map <int, vector <int>> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i + 1] = i + 1;
		mp[x].push_back(i + 1);
	}
	for (pair <int, vector <int>> p : mp) {
		if (p.S.size() <= 1) {
			cout << -1 << '\n';
			return;
		}
		for (int i = 0; i < (int)p.S.size(); i++) {
			if (i == 0) {
				a[p.S[i]] = p.S[(int)p.S.size() - 1];
			} else {
				a[p.S[i]] = p.S[i - 1];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
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