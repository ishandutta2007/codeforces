#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;


void solve() {
	
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	vector<int> cnt(60, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 60; ++j) {
			if ((1LL<<j)&v[i]) cnt[j]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int sand = 0, sor = 0;
		for (int j = 0; j < 60; ++j) {
			if ((1LL<<j)&v[i]) {
				sor += n * ((1LL<<j)%mod);
				sor %= mod;

				sand += cnt[j] * ((1LL<<j)%mod);
				sand %= mod;

			}

			else {
				sor += cnt[j] * ((1LL<<j)%mod);
				sor %= mod;
			}
		}

		ans += sand*sor;
		ans %= mod;
	}

	cout << ans << '\n';

	

}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i <t ; ++i) solve();

}