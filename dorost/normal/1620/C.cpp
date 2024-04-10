/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int x2[N];

void solve() {
	string s;
	int n, k;
	ll x;
	cin >> n >> k >> x >> s;
	x--;
	int c = 0;
	s += 'a';
	for (int i = 0; i <= n; i++)
		x2[i] = 0;
	vector <pair <int, int>> v;
	for (int i = 0; i <= n; i++) {
		if (s[i] == 'a') {
			if (c == 0)
				continue;
			v.push_back({c * k, i});
			c = 0;
		} else {
			c++;
		}
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		x2[v[i].S] = x % (ll)(v[i].F + 1);
		x /= (ll)(v[i].F + 1);
	}
	for (int i = 0; i <= n; i++) {
		if (s[i] == '*')
			continue;
		for (int j = 0; j < x2[i]; j++)
			cout << 'b';
		if (i != n)
			cout << 'a';
	}
	cout << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}