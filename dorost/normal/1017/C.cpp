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
	int sq = sqrt(n);
	map <int, int> mp;
	for (int s = 0; s < sq; s++) {
		vector <int> v;
		for (int i = s; i < n; i += sq)
			v.push_back(i + 1), mp[i] = 1; 
		reverse(v.begin(), v.end());
		for (auto x : v)
			cout << x << ' ';
	}
}

int32_t main() {
	solve();
}