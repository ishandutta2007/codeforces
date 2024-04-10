#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<ll> delta;
vector<vector<int> > data;

pair<int, ll> dp[3007][3007];
pair<int, ll> dp2[3007];

int dfs(int vertex, int last) {
	for (int i = 0; i < 3007; ++i) {
		dp[vertex][i] = {-1e9, -1e18}, dp2[i] = {-1e9, -1e18};
	}

	dp[vertex][1] = {0, delta[vertex]};

	int sz = 1;
	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		int tam = dfs(to, vertex);

		for (int e = 0; e <= tam+sz; ++e) dp2[e] = {-1e9, -1e18};

		for (int j = 0; j <= sz; ++j) for (int k = 0; k <= tam; ++k) {
			pair<int, ll> p = {dp[vertex][j].first + dp[to][k].first + (dp[to][k].second > 0), dp[vertex][j].second};
			if (p > dp2[j+k]) dp2[j+k] = p;
			if (j+k > 0) {
				p = {dp[vertex][j].first + dp[to][k].first, dp[vertex][j].second + dp[to][k].second};
				if (p > dp2[j+k-1]) dp2[j+k-1] = p;
			}
		}

		for (int e = 0; e <= tam+sz; ++e) dp[vertex][e] = dp2[e];

		sz += tam;
	}

	return sz;

}

void solve() {

	int n, m;
	cin >> n >> m;

	delta.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		delta[i] -= x;
	}

	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		delta[i] += x;
	}

	data.assign(n, {});

	for (int i=0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v), data[v].push_back(u);
	}

	dfs(0, -1);

	cout << dp[0][m].first + (dp[0][m].second > 0) << "\n";


}


main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i=0; i < t; ++i) solve();

}