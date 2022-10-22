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
	int n, m;
	cin >> n >> m;
	vector <int> v;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a, a + m);
	for (int i = 0; i < m - 1; i++) {
		v.push_back(a[i + 1] - a[i] - 1);
	}
	v.push_back(n - a[m - 1] + a[0] - 1);
	sort(v.begin(), v.end(), greater<int>());
	int ans = m;
	int t = 0;
	for (int i : v) {
		int x = i - (2 * t);
		if (x <= 0) {
			ans += i;
		} else {
			if (x == 1) {
				ans += (i - 1);
				t++;
			} else {
				ans += (i - x + 1);
				t += 2;
			}
		}
	}
	cout << ans << '\n';
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