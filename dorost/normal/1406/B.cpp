/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	vector <int> v1, v2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 0) 
			v1.push_back(a[i]);
		else
			v2.push_back(a[i]);
	}
	sort(a, a + n);
	reverse(a, a + n);
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int mx = LLONG_MIN;
	for (int i = 0; i <= 5; i++) { 
		if ((int)v2.size() < i || (int)v1.size() < 5 - i)
			continue;
		int ans = 1;
		for (int j = 0; j < i; j++) {
			ans *= v2[j];
		}
		for (int j = 0; j < 5 - i; j++) {
			ans *= v1[j];
		}
		mx = max(mx, ans);
	}
	reverse(v2.begin(), v2.end());
	reverse(v1.begin(), v1.end());
	for (int i = 0; i <= 5; i++) { 
		if ((int)v2.size() < i || (int)v1.size() < 5 - i)
			continue;
		int ans = 1;
		for (int j = 0; j < i; j++) {
			ans *= v2[j];
		}
		for (int j = 0; j < 5 - i; j++) {
			ans *= v1[j];
		}
		mx = max(mx, ans);
	}
	cout << mx << ' ';
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