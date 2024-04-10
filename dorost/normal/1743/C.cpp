/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
const int N = 201234;
int a[N];

void solve() {
	vector <int> v;
	int sum = 0;
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			v.push_back(i);
	}
	v.push_back(n);
	for (int i = 0; i < (int)v.size() - 1; i++) {
		int l = v[i];
		int r = v[i + 1] - 1;
		int mn = INT_MAX;
		for (int j = l; j <= r; j++)
			mn = min (mn, a[j]);
		sum -= mn;
	}
	cout << sum << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}