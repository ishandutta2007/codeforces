/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
vector <int> a[N];
bool f[N];
int x[N];
int n, m;

bool is_valid(int c) {
	for (int i = 0; i < m; i++)
		f[i] = false;
	for (int i = 0; i < n; i++)
		x[i] = 0;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= c) {
				x[i]++;
				if (x[i] >= 2)
					ans = true;
				f[j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++)
		ans &= f[i];
	return ans;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a[i].clear();
		int x;
		for (int j = 0; j < m; j++) {
			cin >> x;
			a[i].push_back(x);
		}
	}
	int l = 0, r = 1000 * 1000 * 1000 + 48;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid)) 
			l = mid;
		else
			r = mid;
	}
	cout << l << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}