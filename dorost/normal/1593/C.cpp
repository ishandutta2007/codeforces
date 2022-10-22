/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 401234;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	sort(a, a + k);
	reverse(a, a + k);
	int ans = 0, nn = n;
	for (int i = 0; i < k; i++) {
		nn -= n - a[i];
		if (nn > 0)
			ans++;
		else
			break;
	}
	cout << ans << ' ';
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