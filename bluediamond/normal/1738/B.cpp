#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
int main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n, k;
		cin >> n >> k;
		vector<ll> s(n + 1, 0LL), a(n + 1, 0LL);
		for (int i = n - k + 1; i <= n; i++) {
			cin >> s[i];
		}
		vector<ll> v;
		for (int i = n - k + 2; i <= n; i++) {
			a[i] = s[i] - s[i - 1];
			v.push_back(a[i]);
		}
		bool ok = 1;
		for (int i = 0; i + 1 < (int) v.size(); i++) {
			ok &= (v[i] <= v[i + 1]);
		}
		int cnt = n - k + 1;
		if ((k == 1 || a[n - k + 2] * (ll) cnt >= s[n - k + 1]) && ok) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}
	
	return 0;
}