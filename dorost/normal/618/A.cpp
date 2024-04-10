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
	cin >> n;
	vector <int> v;
	int x = 1;
	while (n) {
		if (n % 2)
			v.push_back(x);
		n /= 2;
		x++;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}