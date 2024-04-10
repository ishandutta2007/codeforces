/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], ans[N];
vector <int> k[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + 10; i++)
		a[i] = 0;
	for (int i = 0; i < m + 10; i++)
		k[i] = {};
	for (int i = 0; i < m; i++) {
		int l;
		cin >> l;
		if (l == 1) {
			int x;
			cin >> x;
			a[x]++;
			ans[i] = x;
		} else {
			for (int j = 0; j < l; j++) {
				int x;
				cin >> x;
				k[i].push_back(x);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (k[i].size() > 1) {
			for (int j = 0; j < k[i].size(); j++) {
				if (a[k[i][j]] < (m + 1) / 2) {
					a[k[i][j]]++;
					ans[i] = k[i][j];
					break;
				}
			}
		}
	}
	bool f = true;
	for (int i = 1; i <= n; i++) {
		if (a[i] > (m + 1) / 2) {
			f = false;
		}
	}
	if (!f) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < m; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}