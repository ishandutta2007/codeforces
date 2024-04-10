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

	vector<int> cnt(m, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnt[x-1]++;
	}

	vector<int> v(m);
	for (auto &x : v) cin >> x;

	int ans = 0;
	int u = 0;

	for (int i = 0; i < m; ++i) {
		ans += cnt[i] * v[i];
	}



	for (int i = m-1; i >= 0; --i) {
		while (cnt[i] && u <= i) {
			ans += (v[u] - v[i]);
			u++;
			cnt[i]--;
		}

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

	for (int i = 0; i < t; ++i) solve();

}