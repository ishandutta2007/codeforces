/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N], b[N];
pair <int, int> p[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <pair <int, int>> moves;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		p[i] = {a[i], b[i]};
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (p[j] > p[j + 1]) {
				swap(p[j], p[j + 1]);
				moves.push_back({j, j + 1});
			}
		}
	}
	bool f = true;
	for (int i = 0; i < n - 1; i++) {
		if (p[i].F > p[i + 1].F || p[i].S > p[i + 1].S) 
			f = false;
	}
	if (f) {
		cout << moves.size() << '\n';
		for (pair <int, int> x : moves)
			cout << x.F + 1 << ' ' << x.S + 1 << '\n';
	} else {
		cout << -1 << '\n';
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