/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k, nc;
	cin >> n >> k;
	nc = n;
	vector <int> v;
	for (int i = 2; i <= n; i++) {
		if (nc % i)
			continue;
		while (nc % i == 0) {
			nc /= i;
			v.push_back(i);
		}
	}
	if (v.size() < k) {
		cout << -1;
	} else {
		int ans = 1;
		for (int i = 0; i < k - 1; i++) {
			cout << v[i] << ' ';
			ans *= v[i];
		}
		cout << n / ans;
	}
}

int32_t main() {
	solve();
}