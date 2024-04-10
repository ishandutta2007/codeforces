/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 3012;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mx = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		int x = 1;
		sum += a[i];
		int sum2 = 0;
		for (int j = i + 1; j < n; j++) {
			sum2 += a[j];
			if (sum2 == sum) {
				x++;
				sum2 = 0;
			}
		}
		if (sum2)
			continue;
		mx = max(mx, x);
	}
	cout << n - mx << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}