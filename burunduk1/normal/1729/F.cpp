/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int MOD = 9;

void solve() {
	string s;
	int w, m;
	cin >> s >> w >> m; // w <= n
	int n = s.size();
	forn(i, n) s[i] -= '0';

	// O(n+MOD)
	vector<int> pref(n + 1), deg(n + 1, 1);
	forn(i, n) {
		pref[i + 1] = (pref[i] * 10 + s[i]) % MOD;
		deg[i + 1] = (deg[i] * 10) % MOD;
	}
	auto get = [&](int l, int r) {
		return ((pref[r] - pref[l] * deg[r-l]) % MOD + MOD) % MOD;
	};

	vector<vector<int>> ids(MOD);
	forn(i, n - w + 1) {
		// printf("i=%d : %d\n", i, get(i, i + w));
		ids[get(i, i + w)].push_back(i);
	}
	
	while (m--) {
		int l, r, k;
		cin >> l >> r >> k, l--; // [l,r)

		int v = get(l, r);
		// printf("l=%d r=%d : v=%d\n", l, r, v);
		pair<int, int> ans = {INT_MAX, INT_MAX};
		forn(r1, MOD)
			forn(r2, MOD)
				if ((r1 * v + r2) % MOD == k &&
						(int)ids[r1].size() > 0 &&
						(int)ids[r2].size() > (r1 == r2)) {
					int L1 = ids[r1][0];
					int L2 = ids[r2][r1 == r2];
					ans = min(ans, {L1, L2});
				}
		if (ans.first == INT_MAX)
			ans = {-2, -2};
		cout << ans.first+1 << " " << ans.second+1 << "\n";
	}	
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}