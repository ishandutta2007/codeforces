/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
vector <int> v[N];

void ask(int x) {
	cout << "? " << x + 1 << endl;
	cout.flush();
}

int32_t main() {
	int n;
	cin >> n;
	ask(0);
	int x;
	v[0].push_back(0);
	set <pair <int, int>> st;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x].push_back(i);
		if (x == 1) {
			st.insert(minmax({i, 0}));
		}
	}
	x = 1;
	for (int i = 2; i <= n; i += 2) {
		x += v[i].size();
	}
	if (x <= (n + 1) / 2) {
		for (int i = 2; i <= n; i += 2) {
			for (auto a : v[i]) {
				ask(a);
				int y;
				for (int j = 0; j < n; j++) {
					cin >> y;
					if (y == 1) {
						st.insert(minmax({j, a}));
					}
				}
			}
		}
	} else {
		for (int i = 1; i <= n; i += 2) {
			for (auto a : v[i]) {
				ask(a);
				int y;
				for (int j = 0; j < n; j++) {
					cin >> y;
					if (y == 1) {
						st.insert(minmax({j, a}));
					}
				}
			}
		}
	}
	cout << "!" << endl;
	cout.flush();
	for (auto x : st) {
		cout << x.F + 1 << ' ' << x.S + 1 << endl;
		cout.flush();
	}
}