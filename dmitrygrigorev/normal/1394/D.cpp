#include <bits/stdc++.h>
#define int long long
#define ll __int128
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> t, h;

vector<vector<int> > gr;
const int N = 200007;

ll dp[N][2];

void dfs(int vertex, int last) {

	dp[vertex][0] = 1e18;
	dp[vertex][1] = 1e18;

	int small = 0, large = 0;
	ll ans = 0;

	vector<ll> sw;

	for (auto to : gr[vertex]) {
		if (to == last) continue;
		dfs(to, vertex);
		if (h[to] < h[vertex]) {
			ans += dp[to][0];
			small++;
		}

		else if (h[to] > h[vertex]) {
			ans += dp[to][1];
			large++;
		}

		else {
			ans += dp[to][0];
			small++;
			sw.pb(dp[to][1] - dp[to][0]);
		}
	}

	sort(all(sw));
	for (int take = 0; take <= sw.size(); ++take) {

		if (last == -1 || h[vertex] <= h[last]) {
			dp[vertex][0] = min(dp[vertex][0], ans + max(small, large + (last != -1)) * t[vertex]);
		}

		if (last == -1 || h[vertex] >= h[last]) {
			dp[vertex][1] = min(dp[vertex][1], ans + max(small + (last != -1), large) * t[vertex]);
		}

		if (take == sw.size()) continue;
		ans += sw[take];
		small--;
		large++;

	} 


}

ll read() {
	long long x;
	cin >> x;
	return x;
}

main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	n = read();

	t.assign(n, -1), h.assign(n, -1);

	for (auto &x : t) x = read();
	for (auto &x : h) x = read();

	gr.assign(n, {});
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].pb(v);
		gr[v].pb(u);
	}

	dfs(0, -1);
	cout << (long long) min(dp[0][0], dp[0][1]);

}