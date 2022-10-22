/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	ll sum = 0;
	vector <int> v1, v0;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum += b[i];
		if (a[i] == 0)
			v0.push_back(b[i]);
		else
			v1.push_back(b[i]);
	}
	sort(v0.begin(), v0.end());
	reverse(v0.begin(), v0.end());
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());
	int sz0 = (int)v0.size();
	int sz1 = (int)v1.size();
	for (int i = 0; i < min(sz0, sz1); i++) {
		sum += v1[i];
		sum += v0[i];
	}
	if (sz0 == sz1) {
		sum -= min(v0[sz0 - 1], v1[sz1 - 1]);
	}
	cout << sum << '\n';
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