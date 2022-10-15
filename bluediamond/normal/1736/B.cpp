#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif 

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> g(n), a(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> g[i];
		}
		a[0] = g[0];
		a[n] = g[n - 1];
		for (int i = 1; i < n; i++) {
			a[i] = g[i - 1] * g[i] / __gcd(g[i], g[i - 1]);
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			ok &= (__gcd(a[i], a[i + 1]) == g[i]);
		}
		cout << ((ok) ? "YES" : "NO") << "\n";
	}

 	return 0;
}
/*

*/