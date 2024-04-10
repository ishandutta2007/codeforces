/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
#define int long long
vector <int> v[N];
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		v[i].clear();
		v[i].push_back(0);
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			x -= j;
			x = max(x, 0LL);
			v[i].push_back(x);
			v[i][0] = max(v[i][0], x);
		}
	}
	sort(v, v + n);
	int x = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, v[i][0] - x);
		x += ((int)v[i].size() - 1);
	}
	cout << mx + 1 << ' ';
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