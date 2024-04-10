/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int d[N], c[N];

int ask (int v) {
	cout << "? " << v << endl;
	int u;
	cin >> u;
	return u;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < N; i++)
		c[i] = 0;
	vector <pair <int, int>> v;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		v.push_back({d[i], i});
	}
	sort (v.begin(), v.end());
	reverse (v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int x = v[i].S;
		if (c[x] != 0)
			continue;
		vector <int> a = {x};
		int color = i + 1;
		for (int j = 0; j < d[x]; j++) {
			int y = ask(x);
			if (c[y] != 0) {
				color = c[y];
				break;
			}
			a.push_back(y);
		}
		for (int j : a) {
			c[j] = color;
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; i++)
		cout << c[i] << ' ';
	cout << endl;
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