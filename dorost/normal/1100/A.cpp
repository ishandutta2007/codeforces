/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
int a[N], b[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = 0;
	for (int i = 0; i < k; i++) {
		int x = 0, y = 0; 
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		for (int j = i; j < n; j += k) {
			b[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			if (b[j] == -1)
				x++;
			if (b[j] == 1)
				y++;
		}
		mx = max(mx, abs(x - y));
	}
	cout << mx;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}