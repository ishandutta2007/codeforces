/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
vector <int> a[N];

void solve() {
	int n, m;
	cin >> n >> m;
	int in1 = 0, in2 = 0;
	for (int i = 0; i < n; i++) {
		a[i].clear();
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	for (int i = 0; i < n; i++) {
		if (is_sorted(a[i].begin(), a[i].end()))
			continue;
		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] > a[i][j + 1]) {
				in1 = j;
				break;
			}
		}
		for (int j = m - 1; j >= 1; j--) {
			if (a[i][j] < a[i][j - 1]) {
				in2 = j;
				break;
			}
		}
		while (in2 != m - 1 && a[i][in2] == a[i][in2 + 1])
			in2++;
		while (in1 != 0 && a[i][in1] == a[i][in1 - 1])
			in1--;
		break;
	}
	for (int i = 0; i < n; i++) {
		swap(a[i][in1], a[i][in2]);
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		if (!is_sorted(a[i].begin(), a[i].end()))
			f = false;
	}
	if (f == false)
		cout << -1 << '\n';
	else
		cout << in1 + 1 << ' ' << in2 + 1 << '\n';
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