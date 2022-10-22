/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	map <int, int> cnt;
	for (int i = 0; i < n; i++)
		cin >> a[i], cnt[a[i]]++;
	bool f = true;
	for (auto [x, y] : cnt)
		if (y >= 2) {
			f = false;
		}
	cout << (!f ? "YES" : "NO") << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}