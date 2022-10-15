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
		vector<int> a(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = i + 1 - a[i];
		}
		a[n] = (int) 1e9 + 7;
		vector<int> stk = {n};
		ll sol = 0;
		
		for (int i = n - 1; i >= 0; i--) {
			while (!stk.empty() && a[i] >= a[stk.back()]) {
				stk.pop_back();
			}
			// urm >= strict
			int low = 0, high = (int) stk.size() - 1, g = -1;
			while (low <= high) {
				int it = (low + high) / 2;
				if (a[stk[it]] > i) {
					g = stk[it];
					low = it + 1;
				} else {
					high = it - 1;
				}
			}
			assert(g != -1);
			sol += g;
			stk.push_back(i);
		}
		cout << sol - 1LL * n * (n - 1) / 2 << "\n";
	}

 	return 0;
}
/*
6
3
7
*/