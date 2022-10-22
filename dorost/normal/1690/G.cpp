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
	set <pair <int, int>> st;
	int n, m;
	cin >> n >> m;
	int mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < mn) {
			st.insert({i, a[i]});
			mn = a[i];
		}
	}
	for (int i = 0; i < m; i++) {
		int k, d;
		cin >> k >> d;
		k--;
		st.erase({k, a[k]});
		a[k] -= d;
		auto x = st.upper_bound({k, N});
		if (x == st.begin()) {
			st.insert({k, a[k]});
		} else {
			x--;
			if ((*x).S > a[k]) {
				st.insert({k, a[k]});
			}
		}
		if (st.count({k, a[k]})) {	
			auto x = st.lower_bound({k, a[k]});
			vector <pair <int, int>> vec;
			x++;
			for (; x != st.end(); x++) {
				if ((*x).S >= a[k]) {
					vec.push_back(*x);
				} else {
					break;
				}
			}
			for (pair <int, int> p : vec)
				st.erase(p);
		}
/*		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n'; */
		cout << (int)st.size() << ' ';
		/*
		for (pair <int, int> p : st) {
			cout << p.F << ' ' << p.S << '\n';
		}
		cout << ".....\n"; */
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