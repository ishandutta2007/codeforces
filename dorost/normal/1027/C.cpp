/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345, M = 10123;
int a[N];

void solve() {
	map <short, int> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], mp[a[i]]++;
	int x = 0;
	int a = -1, b = -1, c = -1, d = -1;
	for (auto p : mp) {
		if (p.S >= 2)
			x++;
	}
	vector <int> v;
	for (auto p : mp) {
		if (p.S < 2)
			continue;
		v.push_back(p.F);
	}
	ld mn = 1000000.0;
	for (int i = 0; i < v.size() - 1; i++) {
		ld x = (ld) v[i + 1] / ld(v[i]);
		if (x < mn) {
			mn = x;
			a = b = v[i];
			c = d = v[i + 1];
		}
	}
	if (mn > 1) {
		for (auto p : mp) {
			if (p.S < 4)
				continue;
			a = b = c = d = p.F;
		}
	}
	printf("%d %d %d %d\n", a, b, c, d);
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