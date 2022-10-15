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
		vector<int> a(n), b(n);
		for (auto &x : a) cin >> x;
		for (auto &x : b) cin >> x;
		int sol = n;
		for (int e = 0; e < 2; e++) {
			int c = e;
			for (int i = 0; i < n; i++) {
				c += (a[i] != b[i]);
			}
			sol = min(sol, c);
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
		}
		cout << sol << "\n";
	}

 	return 0;
}
/*

*/