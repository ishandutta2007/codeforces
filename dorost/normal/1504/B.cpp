/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	if (n % 2) {
		if (a[n - 1] != b[n - 1]) {
			cout << "NO\n";
			return;
		}
		a.erase(n - 1);
		b.erase(n - 1);
		n--;
	}
	vector <int> v;
	v.push_back(0);
	bool f = true;
	int x = 0, y = 0;
	for (int i = 0; i < n; i += 2) {
		if (a[i] == '1')
			x++;
		if (a[i + 1] == '1')
			x++;
		if (b[i] == '1')
			y++;
		if (b[i + 1] == '1')
			y++;
		if (a[i] != b[i] && a[i + 1] == b[i + 1])
			f = false;
		if (a[i] == b[i] && a[i + 1] != b[i + 1]) 
			f = false;
		if (x == (i / 2) + 1) {
			v.push_back(i + 2);
		}
	}
	v.push_back(n);
	if (x != y)
		f = false;
	for (int i = 0; i < v.size() - 1; i++) {
		int x = (a[v[i]] == b[v[i]]);
		for (int j = v[i] + 2; j < v[i + 1]; j += 2) {
			if ((a[j] == b[j]) != x) {
				f = false;
			}
		}
	}
	cout << (f ? "YES" : "NO") << '\n';
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