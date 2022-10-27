#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
mt19937 rng(228);
#else
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

#define int long long

const int INF = (int)1e18 + 7;

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	int n;
	string s;
	cin >> n >> s;
	assert((int)s.size() == n);

	int cnt_ones = 0;
	for (auto& ch : s) {
		assert(ch == '0' || ch == '1');
		cnt_ones += (ch == '1');
	}

	if (cnt_ones == 0) {
		cout << "0\n";
		return 0;
	}

	reverse(s.begin(), s.end());
	while (!s.empty() && s.back() == '0') {
		s.pop_back();
	}
	reverse(s.begin(), s.end());
	n = (int)s.size();
	string sol = s;
	for (int nd = n - 1; nd >= 0; nd--) {
		string sau = s;
		bool ok = 1;
		for (int i = 0; i < n - 1 - nd; i++) {
			if (sol[i] == '1' && s[i] == '0') {
				ok = 0;
				break;
			}
		}
		if (!ok) {
			break;
		}
		for (int i = n - 1 - nd; i <= n - 1; i++) {
			if (s[i - n + 1 + nd] == '1') {
				sau[i] = '1';
			}
		}
		sol = max(sol, sau);
	}
	cout << sol << "\n";
	return 0;
}


/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */