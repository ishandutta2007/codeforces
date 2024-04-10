#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> cnt(60, 0);

	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;

		int cur = 0;
		while (x > 1) {
			cur++;
			x/=2;
		}

		cnt[cur]++;

	}

	int ans = 0;

	for (int i = 0; i < 60; ++i) {
		if ((1LL<<i)&n) {
			if (!cnt[i]) {
				bool was = false;
				for (int j = i+1; j < 60; ++j) {
					if (cnt[j] > 0) {
						was = true;
						for (int k = j-1; k > i; k--) cnt[k]++;
						cnt[j]--;
						cnt[i] += 2;
						ans += j-i;
						break;
					}
				}
				if (!was) {
					cout << "-1\n";
					return;
				}
			}
			cnt[i]--;
		}

		if (i==59) break;
		cnt[i+1] += cnt[i]/2;
	}

	cout << ans << "\n";

}

main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

	





}