/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int x = 0, y = ((n) / 2);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			v.push_back(a[y]);
			y++;
		}else{
			v.push_back(a[x]);
			x++;
		}
	}
	int ans = 0;
	for (int i = 1; i < (int)v.size() - 1; i++) {
		if (v[i] < v[i - 1] && v[i] < v[i + 1])
			ans++;
	}
	cout << ans << '\n';
	for (auto z : v) {
		cout << z << ' ';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}