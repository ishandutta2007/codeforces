/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 301234;
int a[N];
int n, q;

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1) {
		cout << a[0] << ' ';
		return;
	}
	vector <int> v;
	if (a[1] <= a[0]) {
		v.push_back(a[0]);
	}
	for (int i = 1; i < n - 1; i++) {
		if ((a[i] >= a[i - 1]) == (a[i] >= a[i + 1]))
			v.push_back(a[i]);
	}
	if (a[n - 2] < a[n - 1])
		v.push_back(a[n - 1]);
	int ans = 0, f = 1;
	for (int i = 0; i < v.size(); i++) {
		ans += f * v[i];
		f *= -1;
//		cout << v[i] << ' ';
	}
//	cout << endl;
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}