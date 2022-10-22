/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int lst = -1, x = 0;
	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (true) {
		if (a.empty() || b.empty()) {
			cout << '\n';
			return;
		}
		bool f;
		if (x == k) {
			f = !lst;
		} else if (a.back() < b.back()) 
			f = 0;
		else
			f = 1;
		if (f == 0) {
			cout << a.back();
			if (lst == 0)
				x++;
			else
				x = 1;
			lst = 0;
			a.pop_back();
		} else {
			cout << b.back();
			if (lst == 1)
				x++;
			else
				x = 1;
			lst = 1;
			b.pop_back();
		}
	}
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