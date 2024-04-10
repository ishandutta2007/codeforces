/*  * In the name of GOD 
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
	map <int, int> mp;
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		mp[a[u]]++;
		mp[a[v]]++;
	}
	for (int i = 0; i < n; i++) {
		mp[a[i]]--;
	}
	vector <int> v;
	for (auto [x, y] : mp) {
		for (int i = 0; i < y; i++) {
			v.push_back(x);
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	cout << sum << ' ';
	for (int i = 0; i < n - 2; i++) {
		sum += v[i];
		cout << sum << ' ';
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