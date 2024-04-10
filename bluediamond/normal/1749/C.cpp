#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

bool isok(int n, vector<int>v, int k, int ix, int iy) {
	assert((int)v.size() == n);
	for (int i = 1; i <= k; i++) {
		sort(v.begin(), v.end());
		if (ix)reverse(v.begin(), v.end());
		int p = -1;
		for (int j = 0; j < (int)v.size(); j++) {
			if (v[j] <= k - i + 1) {
				p = j;
			}
		}
		if (p == -1) {
			return 0;
		}
		swap(v[p], v.back());
		v.pop_back();
		sort(v.begin(), v.end());
		if (iy)reverse(v.begin(), v.end());
		if (!v.empty()) {
			v[0] += k - i + 1;
		}
	}
	return 1;
}

bool isok(int n, vector<int> v, int k) {
	for (int ix = 0; ix < 2; ix++) {
		if (isok(n, v, k, ix, 0) && isok(n, v, k, ix, 1))return 1;
	}
	return 0;
}

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		int low = 0, high = n + 1, sol = -1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (isok(n, v, mid)) {
				sol = mid;
				low = mid + 1;
			}
			else high = mid - 1;

		}
		assert(sol != -1);
		cout << sol << "\n";
	}

	return 0;
}


/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */