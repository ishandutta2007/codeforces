/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	sort(a, a + n);
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		int mn = LLONG_MAX;
		auto aa = lower_bound(a, a + n, x);
		if (aa != (a + n)) {
			mn = min(mn, max(0LL, y - (sum - *aa)));
		}
		if (aa != a) {
			aa--;
			mn = min(mn, max(0LL, y - (sum - *aa)) + x - *aa);
		}
		cout << mn << ' ';
	}
}