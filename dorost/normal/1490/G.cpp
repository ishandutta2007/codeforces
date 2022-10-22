/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N], mn[N];

void solve() {
	int n, q;
	cin >> n >> q;
	vector <pair <int, int>> v;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		v.push_back({sum, i});
	}
	sort(v.begin(), v.end());
	mn[n - 1] = v[n - 1].S;
	for (int i = n - 2; i >= 0; i--) {
		mn[i] = min(mn[i + 1], v[i].S);
	}
	while (q--) {
		int x;
		cin >> x;
		if (sum <= 0) {
			cout << (upper_bound(v.begin(), v.end(), make_pair(x, -1LL)) - v.begin() == n ? -1 : mn[(upper_bound(v.begin(), v.end(), make_pair(x, -1LL))) - v.begin()]) << ' ';
		} else {
			int xc = x;
			x -= v[n - 1].F;
			int y;
			if (x < 0)
				y = 0;
			else
				y = max(0LL, (x + sum - 1) / sum);
			xc -= y * sum;
			cout << mn[(upper_bound(v.begin(), v.end(), make_pair(xc, -1LL))) - v.begin()] + y * n << ' ';
		}
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}