/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
pair <int, int> a[N];
int pre[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a, a + n);
	pre[0] = a[0].F;
	for (int i = 1; i < n - 1; i++) {
		pre[i] = pre[i - 1] + a[i].F;
	}
	vector <int> v = {a[n - 1].S + 1};
	for (int i = n - 1; i >= 0; i--) {
		if (pre[i - 1] >= a[i].F) {
			v.push_back(a[i - 1].S + 1);
		} else {
			break;
		}
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (auto x : v) {
		cout << x << ' ';
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